//
// Created by Rodion Shyshkin on 03.11.2020.
//

#include <directory_storage/GRPCServer.h>
#include <gtest/gtest.h>
#include <mocks/MockStorage.h>

 class GRPCServerTest : public ::testing::Test {

};

TEST_F(GRPCServerTest, shouldNotAddEmptyDirectory) {
  auto storage = std::make_unique<MockStorage>();

  auto request = DirRequest::default_instance().New();
  auto response = DirResponse::default_instance().New();

  auto server = GRPCServer{std::move(storage)};

  grpc::Status result;
  EXPECT_NO_THROW(result = server.SaveDirectory(nullptr, request, response));
  ASSERT_TRUE(result.ok());
  ASSERT_FALSE(response->status());
}

TEST_F(GRPCServerTest, shouldAddDirectoryCorrectly) {
  auto storage = std::make_unique<MockStorage>();

  EXPECT_CALL(*storage, AddDir).Times(1).WillOnce(::testing::Return(true));

  auto request = DirRequest::default_instance().New();
  auto dir = Directory::default_instance().New();
  dir->set_path("/usr/local/");
  request->set_allocated_dir(dir);
  auto response = DirResponse::default_instance().New();

  auto server = GRPCServer{std::move(storage)};

  grpc::Status result;
  EXPECT_NO_THROW(result = server.SaveDirectory(nullptr, request, response));
  ASSERT_TRUE(result.ok());
  ASSERT_TRUE(response->status());
}

TEST_F(GRPCServerTest, shouldNotAddBusyDirectory) {
  auto storage = std::make_unique<MockStorage>();

  EXPECT_CALL(*storage, AddDir).Times(1).WillOnce(::testing::Return(false));

  auto request = DirRequest::default_instance().New();
  auto dir = Directory::default_instance().New();
  dir->set_path("/usr/local/");
  request->set_allocated_dir(dir);
  auto response = DirResponse::default_instance().New();

  auto server = GRPCServer{std::move(storage)};

  grpc::Status result;
  EXPECT_NO_THROW(result = server.SaveDirectory(nullptr, request, response));
  ASSERT_TRUE(result.ok());
  ASSERT_FALSE(response->status());
}

TEST_F(GRPCServerTest, shouldNotRemoveEmptyDirectory) {
  auto storage = std::make_unique<MockStorage>();

  auto request = DirRequest::default_instance().New();
  auto response = DirResponse::default_instance().New();

  auto server = GRPCServer{std::move(storage)};

  grpc::Status result;
  EXPECT_NO_THROW(result = server.RemoveDirectory(nullptr, request, response));
  ASSERT_TRUE(result.ok());
  ASSERT_FALSE(response->status());
}

TEST_F(GRPCServerTest, shouldNotRemoveUnexistingDirectory) {
  auto storage = std::make_unique<MockStorage>();

  EXPECT_CALL(*storage, RemoveDir).Times(1).WillOnce(::testing::Return(false));

  auto request = DirRequest::default_instance().New();
  auto dir = Directory::default_instance().New();
  dir->set_path("/usr/local/");
  request->set_allocated_dir(dir);
  auto response = DirResponse::default_instance().New();

  auto server = GRPCServer{std::move(storage)};

  grpc::Status result;
  EXPECT_NO_THROW(result = server.RemoveDirectory(nullptr, request, response));
  ASSERT_TRUE(result.ok());
  ASSERT_FALSE(response->status());
}

TEST_F(GRPCServerTest, shouldRemoveDirectoryCorrectly) {
  auto storage = std::make_unique<MockStorage>();

  EXPECT_CALL(*storage, RemoveDir).Times(1).WillOnce(::testing::Return(true));

  auto request = DirRequest::default_instance().New();
  auto dir = Directory::default_instance().New();
  dir->set_path("/usr/local/");
  request->set_allocated_dir(dir);
  auto response = DirResponse::default_instance().New();

  auto server = GRPCServer{std::move(storage)};

  grpc::Status result;
  EXPECT_NO_THROW(result = server.RemoveDirectory(nullptr, request, response));
  ASSERT_TRUE(result.ok());
  ASSERT_TRUE(response->status());
}