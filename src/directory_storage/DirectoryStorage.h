//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_DIRECTORYSTORAGE_H_
#define DIRECTORYACCESSCHECKER_SRC_DIRECTORYSTORAGE_H_

#include <set>
#include <directory_storage/StorageInterface.h>

class DirectoryStorage : public StorageInterface {
 public:
  bool AddDir(const std::filesystem::path& path) override;
  bool RemoveDir(const std::filesystem::path& path) override;

 private:
  std::set<std::filesystem::path> dirs_;
};

#endif //DIRECTORYACCESSCHECKER_SRC_DIRECTORYSTORAGE_H_
