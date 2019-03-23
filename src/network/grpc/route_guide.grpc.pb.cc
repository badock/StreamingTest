// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: route_guide.proto

#include "route_guide.pb.h"
#include "route_guide.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace gamingstreaming {

static const char* GamingStreamingService_method_names[] = {
  "/gamingstreaming.GamingStreamingService/GamingChannel",
};

std::unique_ptr< GamingStreamingService::Stub> GamingStreamingService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< GamingStreamingService::Stub> stub(new GamingStreamingService::Stub(channel));
  return stub;
}

GamingStreamingService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_GamingChannel_(GamingStreamingService_method_names[0], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::ClientReaderWriter< ::gamingstreaming::InputCommand, ::gamingstreaming::Frame>* GamingStreamingService::Stub::GamingChannelRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::gamingstreaming::InputCommand, ::gamingstreaming::Frame>::Create(channel_.get(), rpcmethod_GamingChannel_, context);
}

::grpc::ClientAsyncReaderWriter< ::gamingstreaming::InputCommand, ::gamingstreaming::Frame>* GamingStreamingService::Stub::AsyncGamingChannelRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::gamingstreaming::InputCommand, ::gamingstreaming::Frame>::Create(channel_.get(), cq, rpcmethod_GamingChannel_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::gamingstreaming::InputCommand, ::gamingstreaming::Frame>* GamingStreamingService::Stub::PrepareAsyncGamingChannelRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::gamingstreaming::InputCommand, ::gamingstreaming::Frame>::Create(channel_.get(), cq, rpcmethod_GamingChannel_, context, false, nullptr);
}

GamingStreamingService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GamingStreamingService_method_names[0],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< GamingStreamingService::Service, ::gamingstreaming::InputCommand, ::gamingstreaming::Frame>(
          std::mem_fn(&GamingStreamingService::Service::GamingChannel), this)));
}

GamingStreamingService::Service::~Service() {
}

::grpc::Status GamingStreamingService::Service::GamingChannel(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::gamingstreaming::Frame, ::gamingstreaming::InputCommand>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace gamingstreaming

