//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_IO_IOINTERFACE_H_
#define DIRECTORYACCESSCHECKER_SRC_IO_IOINTERFACE_H_

#include <string>

class IOInterface {
 public:
  virtual ~IOInterface() {}

 public:
  virtual std::string Input() = 0;
  virtual void Output(const std::string&) = 0;
};

#endif //DIRECTORYACCESSCHECKER_SRC_IO_IOINTERFACE_H_
