//
// Created by Rodion Shyshkin on 02.11.2020.
//

#include "GRPCServer.h"

GRPCServer::GRPCServer(std::unique_ptr<StorageInterface> storage) :
        storage_(std::move(storage)) {  }

::grpc::Status GRPCServer::SaveDirectory(::grpc::ServerContext *context,
                                         const ::DirRequest *request,
                                         ::DirResponse *response) {
  if(request->has_dir()) {
    auto path = std::filesystem::path(request->dir().path());

    auto result = storage_->AddDir(path);
    response->set_status(result);
  }
  else {
    response->set_status(false);
  }
  return ::grpc::Status::OK;
}

::grpc::Status GRPCServer::RemoveDirectory(::grpc::ServerContext *context,
                                           const ::DirRequest *request,
                                           ::DirResponse *response) {
  if(request->has_dir()) {
    auto path = std::filesystem::path(request->dir().path());

    auto result = storage_->RemoveDir(path);
    response->set_status(result);
  }
  else {
    response->set_status(false);
  }
  return ::grpc::Status::OK;
}