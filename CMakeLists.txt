cmake_minimum_required(VERSION 4.0)

project( grpc_example )

# set(gRPC_DIR C:/src/vcpkg/packages/grpc_x64-windows/share/grpc/)
# set(Protobuf_DIR C:/src/vcpkg/packages/protobuf_x64-windows/share/protobuf/)

find_package(gRPC CONFIG REQUIRED)

find_package(Protobuf REQUIRED CONFIG)

add_executable( server ../src/greeter_server.cc ../proto/helloworld.grpc.pb.cc ../proto/helloworld.pb.cc)

add_executable( client ../src/greeter_client.cc ../proto/helloworld.grpc.pb.cc ../proto/helloworld.pb.cc)

target_link_libraries( server PRIVATE gRPC::grpc++ gRPC::grpc++_reflection gRPC::gpr gRPC::grpc gRPC::grpc++ protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite )

target_link_libraries( client PRIVATE gRPC::grpc++ gRPC::grpc++_reflection gRPC::gpr gRPC::grpc gRPC::grpc++ protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite )