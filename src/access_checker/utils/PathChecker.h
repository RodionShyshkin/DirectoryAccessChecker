//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_PATHCHECKER_H_
#define DIRECTORYACCESSCHECKER_SRC_PATHCHECKER_H_

#include <filesystem>
#include <optional>
#include "access_checker/ResultType.h"

/*
 * Toolkit for validating a directory path.
 *
 * @author Rodion Shyshkin
 */

namespace path_checker {
/*
 * Checks if directory has a permission to write for owner.
 *
 * @param const-ref std::filesystem::path
 *
 * @return bool True if it has a permission to write, False in another case.
 */
  static bool CheckPermissions(const std::filesystem::path& path) {
    std::filesystem::directory_entry dir{path};
    auto perms = dir.status().permissions();
    return ((perms & std::filesystem::perms::owner_write) != std::filesystem::perms::none);
  }

  /*
   * Checks if directory exists and create it if it is not.
   *
   * @param const-ref std::filesystem::path
   */
  static void CheckDirectoryExistence(const std::filesystem::path& path) {
    if(std::filesystem::exists(path) || path.has_filename()) return;
    else {
      std::filesystem::create_directories(path);
    }
  }

  /*
   * Makes all verification for a directory path, which includes checking
   * if path is absolute, if it is a path to a directory, if directory
   * exists and creating it in another case, and if it has permissions
   * to write.
   *
   * @param const-ref std::filesystem::path.
   *
   * @return optional ResultType, std::nullopt if there are no errors.
   */
  static std::optional<ResultType> Check(const std::filesystem::path& path) {
    if(!path.is_absolute()) return ResultType::PATH_IS_NOT_ABSOLUTE;
    try {
      CheckDirectoryExistence(path);
    }
    catch(const std::filesystem::filesystem_error& err) {
      return ResultType::PERMISSION_DENIED;
    }
    if(!std::filesystem::is_directory(path)) return ResultType::NOT_DIRECTORY;
    if(!CheckPermissions(path)) return ResultType::PERMISSION_DENIED;

    return std::nullopt;
  }
}

#endif //DIRECTORYACCESSCHECKER_SRC_PATHCHECKER_H_
