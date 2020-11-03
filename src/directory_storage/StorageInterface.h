//
// Created by Rodion Shyshkin on 03.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_DIRECTORY_STORAGE_STORAGEINTERFACE_H_
#define DIRECTORYACCESSCHECKER_SRC_DIRECTORY_STORAGE_STORAGEINTERFACE_H_

#include <filesystem>

/*
 * \brief Interface of storage,
 * which contains all busy directories.
 *
 * @author Rodion Shyshkin
 */

class StorageInterface {
 public:
  virtual ~StorageInterface() = default;

 public:
  virtual bool AddDir(const std::filesystem::path& path) = 0;
  virtual bool RemoveDir(const std::filesystem::path& path) = 0;
};

#endif //DIRECTORYACCESSCHECKER_SRC_DIRECTORY_STORAGE_STORAGEINTERFACE_H_
