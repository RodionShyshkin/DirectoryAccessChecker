//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_GRPCSERVER_H_
#define DIRECTORYACCESSCHECKER_SRC_GRPCSERVER_H_

#include <service.grpc.pb.h>
#include "DirectoryStorage.h"

 class GRPCServer final : public ::DirectoryHolder::Service {
 public:
  GRPCServer(std::unique_ptr<DirectoryStorage> storage);

 public:
  ::grpc::Status SaveDirectory(::grpc::ServerContext *context, const ::DirRequest *request, ::DirResponse *response) override;
  ::grpc::Status RemoveDirectory(::grpc::ServerContext *context, const ::DirRequest *request, ::DirResponse *response) override;

 private:
  std::unique_ptr<DirectoryStorage> storage_;
};

#endif //DIRECTORYACCESSCHECKER_SRC_GRPCSERVER_H_
