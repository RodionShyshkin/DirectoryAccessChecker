//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_CONSOLEUTILS_H_
#define DIRECTORYACCESSCHECKER_SRC_CONSOLEUTILS_H_

#include <filesystem>
#include <access_checker/IO/IOInterface.h>
#include <map>

namespace console_utils {
  static std::filesystem::path GetPath(IOInterface& io) {
    io.Output("Enter the path: ");
    return std::filesystem::path{io.Input()};
  }

  static void Wait(IOInterface& io) {
    io.Output("Press Enter... ");
    io.Input();
  }

  static std::map<ResultType, std::string> GetResultsMap() {
    std::map<ResultType, std::string> results_map;
    results_map[ResultType::SUCCESS] = "Work was finished.";
    results_map[ResultType::PATH_IS_NOT_ABSOLUTE] = "The path is not absolute.";
    results_map[ResultType::NOT_DIRECTORY] = "It is not a directory.";
    results_map[ResultType::PERMISSION_DENIED] = "Permission denied.";
    results_map[ResultType::DIRECTORY_LOCKED] = "Directory is busy.";

    return results_map;
  }

  static int ShowResult(const ResultType& result, IOInterface& io) {
    auto results_map = GetResultsMap();
    if(results_map.find(result) == results_map.end()) return -1;

    io.Output(results_map[result]);
    return result;
  }
}

#endif //DIRECTORYACCESSCHECKER_SRC_CONSOLEUTILS_H_
