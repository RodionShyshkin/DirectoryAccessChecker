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

/*
 * \brief Class for calling service methods.
 *
 * @see GRPCServer.h
 *
 * @author Rodion Shyshkin
 */

class DirectoryHolderClient {
 public:
  explicit DirectoryHolderClient(const std::shared_ptr<Channel>& channel);

 public:
  /*
   * Asks service to add directory to the storage.
   *
   * @param const-ref std::filesystem::path
   *
   * @return bool True if success, False if path already exists in storage.
   */
  bool AddDirectory(const std::filesystem::path& path);

  /*
   * Asks service to remove directory from storage.
   *
   * @param const-ref std::filesystem::path
   *
   * @return bool True if success, False if path is not contained in storage.
   */
  bool RemoveDirectory(const std::filesystem::path& path);

 private:
  std::unique_ptr<DirectoryHolder::Stub> stub_;
};

#endif //DIRECTORYACCESSCHECKER_SRC_ACCESSCHECKER_DIRHOLDERCLIENT_H_
