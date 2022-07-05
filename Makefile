force:

protobuf: force
	protoc --cpp_out=./src --grpc_out=./src   --plugin=protoc-gen-grpc=/home/wh8199/grpc/cmake/build/grpc_cpp_plugin  ./protobuf/grpc_server.proto

aa:
	echo ${CURDIR}