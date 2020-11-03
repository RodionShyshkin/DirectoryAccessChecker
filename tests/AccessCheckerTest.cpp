//
// Created by Rodion Shyshkin on 03.11.2020.
//

#include <access_checker/AccessChecker.h>
#include <access_checker/IO/IOInterface.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockIO : public IOInterface {
 public:
  MOCK_METHOD(std::string, Input, (), (override));
  MOCK_METHOD(void, Output, (const std::string&), (override));
};

 class AccessCheckerTest : public ::testing::Test {
 public:
  void SetUp() override {

  }

  void TearDown() override {

  }

 protected:

};

TEST_F(AccessCheckerTest, )