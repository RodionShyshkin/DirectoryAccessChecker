//
// Created by Rodion Shyshkin on 03.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_ACCESSCHECKER_DIRHOLDERCLIENT_H_
#define DIRECTORYACCESSCHECKER_SRC_ACCESSCHECKER_DIRHOLDERCLIENT_H_

#include <memory>
#include "service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <filesystem>

using grpc::Channel;
using grpc::ClientContext;

using grpc::Status;

class DirectoryHolderClient {
 public:
  explicit DirectoryHolderClient(const std::shared_ptr<Channel>& channel);

 public:
  bool AddDirectory(const std::filesystem::path& path);
  bool RemoveDirectory(const std::filesystem::path& path);

 private:
  std::unique_ptr<DirectoryHolder::Stub> stub_;
};

#endif //DIRECTORYACCESSCHECKER_SRC_ACCESSCHECKER_DIRHOLDERCLIENT_H_
