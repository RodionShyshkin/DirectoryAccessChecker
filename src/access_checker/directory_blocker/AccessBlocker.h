//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_ACCESSBLOCKER_H_
#define DIRECTORYACCESSCHECKER_SRC_ACCESSBLOCKER_H_

#include <access_checker/directory_blocker/DirectoryHolderClient.h>

class AccessBlocker {
 public:
  explicit AccessBlocker(std::filesystem::path&& path);
  ~AccessBlocker();

  bool                    GetResult() const;

 private:
  bool                    Block();
  bool                    Unblock();

 private:
  std::filesystem::path   path_;
  bool                    result_;
  DirectoryHolderClient   client_;
};

#endif //DIRECTORYACCESSCHECKER_SRC_ACCESSBLOCKER_H_
