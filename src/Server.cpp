//
// Created by Rodion Shyshkin on 02.11.2020.
//

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <directory_storage/GRPCServer.h>
#include <directory_storage/DirectoryStorage.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

int main(int argc, char** argv) {
  std::string server_address("0.0.0.0:50051");
  auto model = std::make_unique<DirectoryStorage>();
  GRPCServer service(std::move(model));

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}