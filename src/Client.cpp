//
// Created by Rodion Shyshkin on 02.11.2020.
//

#include <memory>
#include <access_checker/AccessChecker.h>

int main() {
  return access_checker::Check(std::make_unique<ConsoleIO>());
}