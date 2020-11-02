//
// Created by Rodion Shyshkin on 03.11.2020.
//

#include "DirectoryHolderClient.h"
#include <access_checker/utils/GRPCConverter.h>

DirectoryHolderClient::DirectoryHolderClient(const std::shared_ptr<Channel> &channel)
    : stub_(DirectoryHolder::NewStub(channel)) {  }

bool DirectoryHolderClient::AddDirectory(const std::filesystem::path &path) {
  ClientContext context;

  auto request = grpc_converter::PathToRequest(path);
  auto response = DirResponse::default_instance().New();

  stub_->SaveDirectory(&context, *request, response);

  return response->status();
}

bool DirectoryHolderClient::RemoveDirectory(const std::filesystem::path &path) {
  ClientContext context;

  auto request = grpc_converter::PathToRequest(path);
  auto response = DirResponse::default_instance().New();

  stub_->RemoveDirectory(&context, *request, response);

  return response->status();
}