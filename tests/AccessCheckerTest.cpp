//
// Created by Rodion Shyshkin on 03.11.2020.
//

#include <access_checker/AccessChecker.h>
#include <access_checker/IO/IOInterface.h>
#include <gtest/gtest.h>
#include <mocks/MockIO.h>
#include <fstream>

 class AccessCheckerTest : public ::testing::Test {

};


TEST_F(AccessCheckerTest, shouldNotWorkWithNotAbsolutePath) {
  std::unique_ptr<MockIO> io = std::make_unique<MockIO>();

  EXPECT_CALL(*io, Input).Times(1).WillOnce(::testing::Return("~/Documents/"));
  EXPECT_CALL(*io, Output).Times(2);

  auto result = access_checker::Check(std::move(io));
  ASSERT_EQ(result, ResultType::PATH_IS_NOT_ABSOLUTE);
}

TEST_F(AccessCheckerTest, shouldNotWorkWithFile) {
  std::string filename = "/usr/local/testfile.txt";
  std::fstream file(filename, std::ios::out);
  file.close();
  std::unique_ptr<MockIO> io = std::make_unique<MockIO>();

  EXPECT_CALL(*io, Input).Times(1).WillOnce(::testing::Return(filename));
  EXPECT_CALL(*io, Output).Times(2);

  auto result = access_checker::Check(std::move(io));
  ASSERT_EQ(result, ResultType::NOT_DIRECTORY);

  std::filesystem::remove(filename);
}

TEST_F(AccessCheckerTest, shouldNotWorkWithoutPermission) {
  std::string path = "/Users/rodion/sasdf/";
  std::filesystem::create_directories(path);
  std::filesystem::permissions(path, std::filesystem::perms::owner_write,
                               std::filesystem::perm_options::remove);
  std::unique_ptr<MockIO> io = std::make_unique<MockIO>();

  EXPECT_CALL(*io, Input).Times(1).WillOnce(::testing::Return(path));

  EXPECT_CALL(*io, Output).Times(2);

  auto result = access_checker::Check(std::move(io));
  ASSERT_EQ(result, ResultType::PERMISSION_DENIED);
  std::filesystem::remove(path);
}