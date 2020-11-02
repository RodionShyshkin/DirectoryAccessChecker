//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_IO_CONSOLEIO_H_
#define DIRECTORYACCESSCHECKER_SRC_IO_CONSOLEIO_H_

#include <access_checker/IO/IOInterface.h>

class ConsoleIO : public IOInterface {
 public:
  std::string Input() override;
  void Output(const std::string &) override;
};

#endif //DIRECTORYACCESSCHECKER_SRC_IO_CONSOLEIO_H_
