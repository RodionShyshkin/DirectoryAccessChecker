//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_PATHCHECKER_H_
#define DIRECTORYACCESSCHECKER_SRC_PATHCHECKER_H_

#include <filesystem>
#include <optional>
#include "access_checker/ResultType.h"

namespace path_checker {
  static bool CheckPermissions(const std::filesystem::path& path) {
    std::filesystem::directory_entry dir{path};
    auto perms = dir.status().permissions();
    return ((perms & std::filesystem::perms::owner_write) != std::filesystem::perms::none);
  }

  static std::optional<ResultType> Check(const std::filesystem::path& path) {
    if(!path.is_absolute()) return ResultType::PATH_IS_NOT_ABSOLUTE;
    if(!std::filesystem::is_directory(path)) return ResultType::NOT_DIRECTORY;
    if(!CheckPermissions(path)) return ResultType::PERMISSION_DENIED;

    return std::nullopt;
  }
}

#endif //DIRECTORYACCESSCHECKER_SRC_PATHCHECKER_H_
