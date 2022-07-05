#include <iostream>
#include <protobuf/grpc_server.grpc.pb.h>
#include <protobuf/grpc_server.pb.h>
#include "server/server.h"

int main() {
    std::cout << "aaa" << std::endl;
    std::string server_address("0.0.0.0:50051");

    std::cout << server_address << std::endl;

    CustomServer *s = new CustomServer(9999);

    s->start();

    // wait for signals
    while (true) {

    };

    
}