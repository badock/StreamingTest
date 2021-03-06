#define NOMINMAX

#include <SDL.h>
#include <SDL_thread.h>
#include <string>
#include <sstream>
#include <iostream>


#if defined(WIN32)
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>
#include <crtdbg.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#else
#include <unistd.h>
#endif

#ifndef GAMECLIENTSDL_STREAMING_H
#define GAMECLIENTSDL_STREAMING_H

#include "src/codec/codec.h"

extern "C" {
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
#include <libavutil/imgutils.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <SDL.h>
#include <SDL_thread.h>
#include <stdlib.h>
}

#include <chrono>
#include "src/queue/queue.h"
#include "src/log/log.h"
#include <queue>

#if defined(WIN32)
void usleep(unsigned int usec);
#else
#include <unistd.h>
#endif

#include "protos/route_guide.pb.h"

using gamingstreaming::InputCommand;

typedef struct _FrameData {
    AVFrame *pFrame;
    uint8_t *buffer;
    int numBytes;
    int id;
    int pitch;
    int stride;
	int flow_id;
    // debug field
    std::chrono::system_clock::time_point life_started_time_point;
    std::chrono::system_clock::time_point dxframe_acquired_time_point;
    std::chrono::system_clock::time_point dxframe_processed_time_point;
    std::chrono::system_clock::time_point avframe_produced_time_point;
    std::chrono::system_clock::time_point sdl_received_time_point;
    std::chrono::system_clock::time_point sdl_avframe_rescale_time_point;
    std::chrono::system_clock::time_point sdl_displayed_time_point;
} FrameData;


typedef struct _StreamingEnvironment {
	SDL_Thread *frame_extractor_thread;
	SDL_Thread *frame_encoder_thread;
	SDL_Thread *frame_decoder_thread;
	SDL_Thread *frame_output_thread;
	SDL_Thread *video_encode_thread;
	SDL_Thread *video_decode_thread;
	SDL_Thread *packet_sender_thread;
    SDL_Thread *asio_udp_listener;
	SDL_Thread *packet_receiver_thread;
#if defined(WIN32)
	SDL_Thread *gpu_frame_extractor_thread;
#endif
    SimpleQueue<packet_data*> network_simulated_queue;
	SimpleQueue<FrameData*> frame_extractor_pframe_pool;
	SimpleQueue<FrameData*> frame_sender_thread_queue;
    SimpleQueue<packet_data*> packet_sender_thread_queue;
	SimpleQueue<FrameData*> frame_output_thread_queue;
    SimpleQueue<InputCommand*> input_command_queue;
	AVPixelFormat format;

	AVCodecContext* frameExtractorDecodingContext;
	AVFormatContext* frameExtractorEncodingFormatContext;

	int width;
	int height;
	int flow_id;

    int client_width;
    int client_height;

	AVCodec* encoder;
	AVCodec* decoder;

    AVCodecContext *encodingContext;
    AVCodecContext *decodingContext;
	
	SDL_Window *screen;
	SDL_Renderer *renderer;
	int videoStream;
	int initialized;
	int network_initialized;
	int screen_is_initialized;
	int finishing;

	bool client_connected = false;
	bool server_initialized = false;
	bool can_begin_stream = false;
	bool is_all_in_one = false;
	bool is_client = false;
	bool is_server = false;

	bool cursor_disabled = false;
    SDL_Texture* mouse_cursor_icon_texture;

	std::string listen_address;
    std::string server_address;

	// field relate to mouse cursor
	int client_mouse_x = 0;
	int client_mouse_y = 0;
	int client_mouse_is_visible = 0;
//    int server_port;

    // Fields related to SDL client
    SDL_Texture *texture;;
    SwsContext *sws_ctx = NULL;
    Uint8 *yPlane, *uPlane, *vPlane;
    size_t yPlaneSz, uvPlaneSz;
    int uvPitch;

} StreamingEnvironment;

void frame_data_reset_time_points(FrameData* frame_data);
void frame_data_debug(FrameData* frame_data);
FrameData* frame_data_create(StreamingEnvironment* se);
int frame_data_destroy(FrameData* frame_data);
int init_frame_pool(int framecount, StreamingEnvironment* se);
int destroy_frame_pool(StreamingEnvironment* se);
#endif