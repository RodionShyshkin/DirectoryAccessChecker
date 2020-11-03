//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_CONSOLEUTILS_H_
#define DIRECTORYACCESSCHECKER_SRC_CONSOLEUTILS_H_

#include <filesystem>
#include <access_checker/IO/IOInterface.h>
#include <map>

/*
 * \brief Toolkit which contains functions
 * responsible for input-output.
 *
 * @author Rodion Shyshkin
 */

namespace console_utils {
/*
 * Asks user to enter a path to a directory when program starts.
 *
 * @param IOInterface&
 *
 * @return std::filesystem::path Entered path.
 */
  static std::filesystem::path GetPath(IOInterface& io) {
    io.Output("Enter the path: ");
    return std::filesystem::path{io.Input()};
  }

  /*
   * Asks user to press enter and waits for
   * it when program taked some directory, when it
   * happens program finishes its work and free its directory.
   *
   * @param IOInterface&
   */
  static void Wait(IOInterface& io) {
    io.Output("Press Enter... ");
    io.Input();
  }

  /*
   * Gets the map of user messages for different
   * result codes.
   *
   * @return std::map Result code and user message for it.
   */
  static std::map<ResultType, std::string> GetResultsMap() {
    std::map<ResultType, std::string> results_map;
    results_map[ResultType::SUCCESS] = "Work was finished.";
    results_map[ResultType::PATH_IS_NOT_ABSOLUTE] = "The path is not absolute.";
    results_map[ResultType::NOT_DIRECTORY] = "It is not a directory.";
    results_map[ResultType::PERMISSION_DENIED] = "Permission denied.";
    results_map[ResultType::DIRECTORY_LOCKED] = "Directory is busy.";

    return results_map;
  }

  /*
   * Shows user message after getting some result code
   * and gives this code.
   *
   * @param const-ref ResultType
   * @param IOInterface&
   *
   * @return ResultType
   */
  static ResultType ShowResult(const ResultType& result, IOInterface& io) {
    auto results_map = GetResultsMap();

    io.Output(results_map[result]);
    return result;
  }
}

#endif //DIRECTORYACCESSCHECKER_SRC_CONSOLEUTILS_H_
