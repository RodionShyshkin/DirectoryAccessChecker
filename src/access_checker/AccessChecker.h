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

/*
 * \brief Entry point to check the concrete directory.
 *
 * @see IO/IOInterface.h
 * @see ResultType.h
 *
 * @author Rodion Shyshkin
 */

namespace access_checker {
/*
 * Gets directory path from user, check it and take if it is free.
 *
 * @param IOInterface ptr Interface for input-output
 *
 * @return ResultType Code of the running result.
 */
  static ResultType Check(std::unique_ptr<IOInterface> io) {
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
