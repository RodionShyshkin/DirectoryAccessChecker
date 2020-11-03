//
// Created by Rodion Shyshkin on 03.11.2020.
//

#include <access_checker/utils/PathChecker.h>
#include <gtest/gtest.h>

class PathCheckerTest : public ::testing::Test {

};

TEST_F(PathCheckerTest, shouldReturnTrueIfFileHasOwnerWritePerm) {
  std::filesystem::path path{"testdir/"};
  std::filesystem::create_directories(path);

  std::filesystem::permissions(path, std::filesystem::perms::owner_write,
                               std::filesystem::perm_options::remove);
  ASSERT_FALSE(path_checker::CheckPermissions(path));

  std::filesystem::permissions(path, std::filesystem::perms::owner_write,
                               std::filesystem::perm_options::add);
  ASSERT_TRUE(path_checker::CheckPermissions(path));
  std::filesystem::remove(path);
}

TEST_F(PathCheckerTest, shouldCreateDirectoryIfItIsNotExist) {
  std::filesystem::path path{"unexistdir/"};
  path_checker::CheckDirectoryExistence(path);

  ASSERT_TRUE(std::filesystem::exists(path));
  std::filesystem::remove(path);
}

TEST_F(PathCheckerTest, shouldReturnErrorIfPathIsNotAbsolute) {
  std::filesystem::path path{"~/"};
  auto result = path_checker::Check(path);

  ASSERT_EQ(result, ResultType::PATH_IS_NOT_ABSOLUTE);
  std::filesystem::remove(path);
}

TEST_F(PathCheckerTest, shouldReturnErrorWithFile) {
  std::filesystem::path path{"/usr/local/file.txt"};
  auto result = path_checker::Check(path);

  ASSERT_EQ(result, ResultType::NOT_DIRECTORY);
  std::filesystem::remove(path);
}

TEST_F(PathCheckerTest, shouldReturnErrorWithoutPermissions) {
  std::filesystem::path path{"/Users/rodion/testdir/"};
  std::filesystem::create_directories(path);
  std::filesystem::permissions(path, std::filesystem::perms::owner_write,
                               std::filesystem::perm_options::remove);
  auto result = path_checker::Check(path);

  ASSERT_EQ(result, ResultType::PERMISSION_DENIED);
  std::filesystem::remove(path);
}

TEST_F(PathCheckerTest, shouldNotReturnErrorIfCorrect) {
  std::filesystem::path path{"/Users/rodion/testdir/"};
  std::filesystem::create_directories(path);
  auto result = path_checker::Check(path);

  ASSERT_FALSE(result.has_value());
  std::filesystem::remove(path);
}