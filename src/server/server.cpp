#include "server/server.h"
#include <grpcpp/support/status.h>

CustomServer::CustomServer() {}

CustomServer::CustomServer(int port) : port(port) {}

::grpc::Status CustomServer::TransformData(::grpc::ServerContext *context, ::grpc::ServerReaderWriter< ::azureConnectorGrpcServer::Response, ::azureConnectorGrpcServer::Data> *stream) {
    return grpc::Status{};
}

int CustomServer::start() {
    return 0;
}

void CustomServer::stop() {}