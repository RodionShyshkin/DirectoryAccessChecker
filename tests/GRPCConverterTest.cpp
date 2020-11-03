//
// Created by Rodion Shyshkin on 03.11.2020.
//

#include <access_checker/utils/GRPCConverter.h>
#include <gtest/gtest.h>

class GRPCConverterTest : public ::testing::Test {

};

TEST_F(GRPCConverterTest, shouldConvertPathToRequestCorrectly) {
  std::filesystem::path path{"usr/local/"};
  auto request = grpc_converter::PathToRequest(path);
  ASSERT_TRUE(request->has_dir());
  ASSERT_EQ(request->dir().path(), "usr/local/");
}