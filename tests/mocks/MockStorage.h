//
// Created by Rodion Shyshkin on 03.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_TESTS_MOCKS_MOCKSTORAGE_H_
#define DIRECTORYACCESSCHECKER_TESTS_MOCKS_MOCKSTORAGE_H_

#include <directory_storage/StorageInterface.h>
#include <gmock/gmock.h>

class MockStorage : public StorageInterface {
 public:
  MOCK_METHOD(bool, AddDir, (const std::filesystem::path&), (override));
  MOCK_METHOD(bool, RemoveDir, (const std::filesystem::path&), (override));
};

#endif //DIRECTORYACCESSCHECKER_TESTS_MOCKS_MOCKSTORAGE_H_
