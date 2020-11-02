//
// Created by Rodion Shyshkin on 02.11.2020.
//

#include "DirectoryStorage.h"

bool DirectoryStorage::AddDir(const std::filesystem::path &path) {
  if(dirs_.find(path) != dirs_.end()) return false;

  dirs_.insert(path);
  return true;
}

bool DirectoryStorage::RemoveDir(const std::filesystem::path &path) {
  if(dirs_.find(path) == dirs_.end()) return false;

  dirs_.erase(path);
  return true;
}