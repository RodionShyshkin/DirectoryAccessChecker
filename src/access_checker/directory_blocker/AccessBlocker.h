//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_ACCESSBLOCKER_H_
#define DIRECTORYACCESSCHECKER_SRC_ACCESSBLOCKER_H_

#include <access_checker/directory_blocker/DirectoryHolderClient.h>

/*
 * \brief Class which blocks access to the directory for
 * other instances of program, when its instance is created,
 * and unlock directory when it destroys.
 *
 * @author Rodion Shyshkin
 */

class AccessBlocker {
 public:
  explicit AccessBlocker(std::filesystem::path&& path);
  ~AccessBlocker();

  /*
   * Gets the result of blocking.
   *
   * @return bool True if success, False if
   * directory is already busy.
   */
  bool                    GetResult() const;

 private:
  /*
   * Blocks access to the directory.
   *
   * @return bool True if success, False if
   * directory is already busy.
   */
  bool                    Block();

  /*
   * Free access to the directory.
   *
   * @return bool True if success, False if
   * directory is already free.
   */
  bool                    Unblock();

 private:
  std::filesystem::path   path_;
  bool                    result_;
  DirectoryHolderClient   client_;
};

#endif //DIRECTORYACCESSCHECKER_SRC_ACCESSBLOCKER_H_
