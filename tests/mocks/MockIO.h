//
// Created by Rodion Shyshkin on 03.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_TESTS_MOCKS_MOCKIO_H_
#define DIRECTORYACCESSCHECKER_TESTS_MOCKS_MOCKIO_H_

#include <gmock/gmock.h>
#include <access_checker/IO/IOInterface.h>

class MockIO : public IOInterface {
 public:
  MOCK_METHOD(std::string, Input, (), (override));
  MOCK_METHOD(void, Output, (const std::string&), (override));
};

#endif //DIRECTORYACCESSCHECKER_TESTS_MOCKS_MOCKIO_H_
