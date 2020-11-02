//
// Created by Rodion Shyshkin on 02.11.2020.
//

#include <iostream>
#include "ConsoleIO.h"

std::string ConsoleIO::Input() {
  std::string stringInput;
  std::getline(std::cin, stringInput);
  return stringInput;
}

void ConsoleIO::Output(const std::string &string) {
  std::cout << string;
  std::cout << std::endl;
}