//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_ACCESSCHECKER_H_
#define DIRECTORYACCESSCHECKER_SRC_ACCESSCHECKER_H_

#include "ResultType.h"
#include <access_checker/directory_blocker/AccessBlocker.h>
#include <access_checker/IO/ConsoleIO.h>
#include <access_checker/utils/ConsoleUtils.h>
#include <access_checker/utils/PathChecker.h>

namespace access_checker {
  static int Check(std::unique_ptr<IOInterface> io) {
    auto path = console_utils::GetPath(*io);

    auto path_error = path_checker::Check(path);
    if(path_error.has_value()) return console_utils::ShowResult(path_error.value(), *io);

    AccessBlocker block{std::move(path)};
    auto result = block.GetResult();
    if(!result) return console_utils::ShowResult(ResultType::DIRECTORY_LOCKED, *io);

    console_utils::Wait(*io);
    return console_utils::ShowResult(ResultType::SUCCESS, *io);
  }
}

#endif //DIRECTORYACCESSCHECKER_SRC_ACCESSCHECKER_H_
