//
// Created by Rodion Shyshkin on 03.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_ACCESS_CHECKER_UTILS_GRPCCONVERTER_H_
#define DIRECTORYACCESSCHECKER_SRC_ACCESS_CHECKER_UTILS_GRPCCONVERTER_H_

#include "service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <filesystem>

namespace grpc_converter {
  static DirRequest* PathToRequest(const std::filesystem::path& path) {
    auto string_path = path.string();
    auto dir = Directory::default_instance().New();
    dir->set_path(string_path);
    auto request = DirRequest::default_instance().New();
    request->set_allocated_dir(dir);

    return request;
  }
}

#endif //DIRECTORYACCESSCHECKER_SRC_ACCESS_CHECKER_UTILS_GRPCCONVERTER_H_
