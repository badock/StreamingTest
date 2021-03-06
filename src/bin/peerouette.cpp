
#include "src/output/output.h"
#include "src/extractors/extractors.h"
#include "src/inputs/inputs.h"
#include "src/streaming/streaming.h"

// compatibility with newer API
#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(55,28,1)
#define av_frame_alloc avcodec_alloc_frame
#define av_frame_free avcodec_free_frame
#endif

#undef main

int FRAME_POOL_SIZE = 45;
int SDL_WINDOW_WIDTH = 1280;
int SDL_WINDOW_HEIGHT = 720;
// int CAPTURE_WINDOW_WIDTH = 1680;
// int CAPTURE_WINDOW_HEIGHT = 1050;

void my_log_callback(void *ptr, int level, const char *fmt, va_list vargs)
{
	vprintf(fmt, vargs);
}

int main(int argc, char* argv[]){
    log_info("Simple GameClient has started");

	// [FFMPEG] Registering file formats and codecs
	log_info("Registering file formats and codecs");
	av_register_all();

//    av_log_set_callback(my_log_callback);
//    av_log_set_level(AV_LOG_VERBOSE);

    // Initialize streaming environment and threads
    log_info("Initializing streaming environment");
    auto se = new StreamingEnvironment();

    // Analyse arguments passed to the program
    if (argc == 1) {
        se->is_all_in_one = true;
        se->is_server = true;
        se->is_client = true;
        se->listen_address = std::string("0.0.0.0:50051");
        se->server_address = std::string("localhost:50051");
    } else {
        std::string role(argv[1]);
        if (role.compare("--server") == 0) {
            se->is_server = true;
            se->listen_address = std::string("0.0.0.0:50051");
        } else if (role.compare("--client") == 0) {
            se->is_client = true;
            se->server_address = std::string("192.168.1.29:50051");
        }
    }

    /////////////////////////
    /// Create threads
    /////////////////////////

    // a) server threads
    if (se->is_all_in_one || se->is_server) {
        if (se->is_all_in_one) {
            se->frame_extractor_thread = SDL_CreateThread(frame_extractor_thread, "frame_extractor_thread", se);
        } else {
#if defined(WIN32)
            se->gpu_frame_extractor_thread = SDL_CreateThread(gpu_frame_extractor_thread, "gpu_frame_extractor_thread", se);
#endif
        }
        se->video_encode_thread = SDL_CreateThread(video_encode_thread, "video_encode_thread", se);
        se->packet_sender_thread = SDL_CreateThread(packet_sender_thread, "packet_sender_thread", se);
    }

    if(se->is_all_in_one) {
        while (! se->server_initialized) {
            usleep(1 * 1000);
        }
    }


    // b) Client threads
    if (se->is_all_in_one || se->is_client) {
        se->packet_receiver_thread = SDL_CreateThread(packet_receiver_thread, "packet_receiver_thread", se);
        se->video_decode_thread = SDL_CreateThread(video_decode_thread, "video_decode_thread", se);
        se->frame_output_thread = SDL_CreateThread(frame_output_thread, "frame_output_thread", se);
    }
    se->finishing = 0;
    se->initialized = 0;
	se->network_initialized = 0;
    se->screen_is_initialized = 0;
    se->width = -1;
    se->height = -1;
    se->client_width = SDL_WINDOW_WIDTH;
    se->client_height = SDL_WINDOW_HEIGHT;
	se->format = AV_PIX_FMT_YUV420P;
    se->flow_id = 0;

	if (se->is_all_in_one) {
	    se->cursor_disabled = true;
	}

    if (se->is_client || se->is_all_in_one) {

        // [SDL] Initializing SDL library
        log_info("Initializing SDL library");
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
            fprintf(stderr, "Could not initialize SDL - %s\n", SDL_GetError());
            exit(1);
        }


        // [SDL] Creating a display
        log_info("Creating a SDL display");
        Uint32 screen_flags = SDL_WINDOW_OPENGL;
        if (0) {
            screen_flags = SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL;
        }
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");
        SDL_Window *screen = SDL_CreateWindow(
                "FFmpeg Tutorial",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOW_WIDTH,
                SDL_WINDOW_HEIGHT,
                screen_flags
        );

        SDL_ShowWindow(screen);
        se->screen = screen;

        if (!se->screen) {
            fprintf(stderr, "SDL: could not create window - exiting\n");
            exit(1);
        }

        se->renderer = SDL_CreateRenderer(se->screen, -1, 0);
        if (!se->renderer) {
            fprintf(stderr, "SDL: could not create renderer - exiting\n");
            exit(1);
        }
    }

    // Application is ready to read frame and display frames
    se->initialized = 1;

	// [FFMPEG] Initialize frame pool
	//init_frame_pool(FRAME_POOL_SIZE, se);

    if (se->is_client) {

        SDL_Event event;

        while(! se->screen_is_initialized) {
            usleep(30 * 1000);
        }

        while(!se->finishing) {
            // [SDL] handle events
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        se->finishing = 1;
                        SDL_Quit();
                        break;
                    default:
                        handle_sdl_input(se, event);
                        break;
                }
            }
            // Prevent high CPU usage
            SDL_Delay(1);
        }
    } else {
        while (true) {
            usleep(30 * 1000);
        }
    }

    // [FFMPEG] Free the RGB image
    while (! se->frame_extractor_pframe_pool.isEmpty()) {
        auto frame_data = se->frame_extractor_pframe_pool.pop();
        frame_data_destroy(frame_data);
    }

    log_info("Simple GameClient is exiting");

	return 0;
}
