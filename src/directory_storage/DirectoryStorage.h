//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_DIRECTORYSTORAGE_H_
#define DIRECTORYACCESSCHECKER_SRC_DIRECTORYSTORAGE_H_

#include <set>
#include <filesystem>

class DirectoryStorage {
 public:

 public:
  bool AddDir(const std::filesystem::path& path);
  bool RemoveDir(const std::filesystem::path& path);

 private:
  std::set<std::filesystem::path> dirs_;
};

#endif //DIRECTORYACCESSCHECKER_SRC_DIRECTORYSTORAGE_H_
