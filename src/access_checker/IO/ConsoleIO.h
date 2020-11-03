//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_IO_CONSOLEIO_H_
#define DIRECTORYACCESSCHECKER_SRC_IO_CONSOLEIO_H_

#include <access_checker/IO/IOInterface.h>

/*
 * \brief Console implementation of IO.
 *
 * @author Rodion Shyshkin
 */

class ConsoleIO : public IOInterface {
 public:
  /*
   * Gets string from user.
   *
   * @return std::string
   */
  std::string Input() override;

  /*
   * Shows string to user with line break.
   *
   * @param const-ref std::string
   */
  void Output(const std::string &) override;
};

#endif //DIRECTORYACCESSCHECKER_SRC_IO_CONSOLEIO_H_
