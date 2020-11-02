//
// Created by Rodion Shyshkin on 02.11.2020.
//

#include "AccessBlocker.h"

AccessBlocker::AccessBlocker(std::filesystem::path &&path) : path_(std::move(path)),
                                  client_(grpc::CreateChannel("0.0.0.0:50051",
                                  grpc::InsecureChannelCredentials())) {
  result_ = Block();
}

AccessBlocker::~AccessBlocker() {
  if(result_) {
    Unblock();
  }
}

bool AccessBlocker::Block() {
  return client_.AddDirectory(path_);
}

bool AccessBlocker::Unblock() {
  return client_.RemoveDirectory(path_);
}

bool AccessBlocker::GetResult() const {
  return result_;
}