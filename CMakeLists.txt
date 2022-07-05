cmake_minimum_required(VERSION 2.8.12)
project(EdgeConnector)

# compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# conan setup
add_definitions("-std=c++11")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SRC ${CMAKE_CURRENT_BINARY_DIR}/../src)
set(INC ${CMAKE_CURRENT_BINARY_DIR}/../include)

# grpc
set(proto_srcs "${SRC}/protobuf/grpc_server.pb.cc")
set(grpc_srcs "${SRC}/protobuf/grpc_server.grpc.pb.cc")

include_directories(${INC})
include_directories(${SRC})

add_library(grpc_proto STATIC
  ${proto_srcs}
  ${grpc_srcs})

target_link_libraries(grpc_proto ${CONAN_LIBS})

add_executable(md5
  ${SRC}/main.cpp
  ${SRC}/server/server.cpp
)

target_link_libraries(md5 ${CONAN_LIBS} grpc_proto)