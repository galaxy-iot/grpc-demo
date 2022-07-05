#ifndef SERVER_H
#define SERVER_H

#include "protobuf/grpc_server.pb.h"
#include "protobuf/grpc_server.grpc.pb.h"

class CustomServer : ::azureConnectorGrpcServer::GrpcServer::Service {
    private:
        int port;

    public:
        ::grpc::Status TransformData(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::azureConnectorGrpcServer::Response, 
            ::azureConnectorGrpcServer::Data>* stream);

        int start();
        void stop();
        CustomServer();
        CustomServer(int port);
};

#endif