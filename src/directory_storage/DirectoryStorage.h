//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_DIRECTORYSTORAGE_H_
#define DIRECTORYACCESSCHECKER_SRC_DIRECTORYSTORAGE_H_

#include <set>
#include <directory_storage/StorageInterface.h>

/*
 * \brief Storage with all busy directories.
 *
 * @author Rodion Shyshkin
 */

class DirectoryStorage : public StorageInterface {
 public:
  /*
   * Adds new directory in the set of busy directories.
   *
   * @param std::filesystem::path path to the directory.
   *
   * @return bool True if directory was added successfully,
   *              False if directory with this path is already busy.
   */
  bool AddDir(const std::filesystem::path& path) override;

  /*
   * Remove directory from the set of busy directories.
   *
   * @param std::filesystem::path path to the directory.
   *
   * @return bool True if directory was freed successfully,
   *              False if directory with this path does not busy.
   */
  bool RemoveDir(const std::filesystem::path& path) override;

 private:
  std::set<std::filesystem::path> dirs_;
};

#endif //DIRECTORYACCESSCHECKER_SRC_DIRECTORYSTORAGE_H_
