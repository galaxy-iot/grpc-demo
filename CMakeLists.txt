cmake_minimum_required(VERSION 2.8.12)
project(EdgeConnector)

# compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# conan setup
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SRC ${CMAKE_CURRENT_BINARY_DIR}/../src)
set(INC ${CMAKE_CURRENT_BINARY_DIR}/../include)

# common include directories
include_directories(${INC})
include_directories(${SRC})

# grpc
set(proto_srcs "${SRC}/protobuf/grpc_server.pb.cc")
set(grpc_srcs "${SRC}/protobuf/grpc_server.grpc.pb.cc")


set(use_mqtt ON CACHE  BOOL "Set mqtt on" FORCE )
set(skip_samples ON CACHE  BOOL "Set slip_samples on" FORCE )
set(BUILD_TESTING OFF CACHE  BOOL "Set BUILD_TESTING off" FORCE )

# Add Azure IoT SDK C
add_subdirectory(thirdparty/azure-iot-sdk-c out)

compileAsC99()


# grpc library
add_library(grpc_proto STATIC
  ${proto_srcs}
  ${grpc_srcs})

target_link_libraries(grpc_proto ${CONAN_LIBS})


add_executable(md5
  ${SRC}/main.cpp
  ${SRC}/server/server.cpp
  ${iothub_project_files}
)

target_link_libraries(md5 
  ${CONAN_LIBS} 
  grpc_proto
  curl
  aziotsharedutil
  hsm_security_client
  iothub_client
  #iothub_client_amqp_transport
  #iothub_client_amqp_ws_transport
  #iothub_client_http_transport
  iothub_client_mqtt_transport
  iothub_client_mqtt_ws_transport
  iothub_service_client
  parson
  prov_amqp_transport
  prov_amqp_ws_transport
  prov_auth_client
  prov_device_client
  prov_device_ll_client
  prov_http_transport
  prov_mqtt_transport
  prov_mqtt_ws_transport
  serializer
  uamqp
  uhttp
  umock_c
  umqtt
  utpm
  pthread
  m
)