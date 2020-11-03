//
// Created by Rodion Shyshkin on 03.11.2020.
//

#include <gtest/gtest.h>
#include <directory_storage/DirectoryStorage.h>

 class DirectoryStorageTest : public ::testing::Test {
 public:
  void SetUp() override {
    path_ = std::filesystem::path{"testfile.txt"};
  }

  void TearDown() override {

  }

 protected:
  std::filesystem::path path_;
};

TEST_F(DirectoryStorageTest, shouldAddDirCorrectly) {
  DirectoryStorage storage;
  ASSERT_TRUE(storage.AddDir(path_));
}

TEST_F(DirectoryStorageTest, shouldNotAddExistingDir) {
  DirectoryStorage storage;
  storage.AddDir(path_);
  ASSERT_FALSE(storage.AddDir(path_));
}

TEST_F(DirectoryStorageTest, shouldRemoveDirCorrectly) {
  DirectoryStorage storage;
  storage.AddDir(path_);
  ASSERT_TRUE(storage.RemoveDir(path_));
}

TEST_F(DirectoryStorageTest, shouldNotRemoveUnexistingDir) {
  DirectoryStorage storage;
  ASSERT_FALSE(storage.RemoveDir(path_));
}

TEST_F(DirectoryStorageTest, shouldAddDirAfterRemovingCorrectly) {
  DirectoryStorage storage;
  storage.AddDir(path_);
  storage.RemoveDir(path_);
  ASSERT_FALSE(storage.RemoveDir(path_));
  ASSERT_TRUE(storage.AddDir(path_));
}