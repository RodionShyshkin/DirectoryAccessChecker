//
// Created by Rodion Shyshkin on 02.11.2020.
//

#ifndef DIRECTORYACCESSCHECKER_SRC_RESULTTYPE_H_
#define DIRECTORYACCESSCHECKER_SRC_RESULTTYPE_H_

/*
 * \brief Enum of possible result codes of checking directory.
 *
 * @author Rodion Shyshkin
 */

enum ResultType {
  SUCCESS = 0,
  PATH_IS_NOT_ABSOLUTE,
  NOT_DIRECTORY,
  PERMISSION_DENIED,
  DIRECTORY_LOCKED
};

#endif //DIRECTORYACCESSCHECKER_SRC_RESULTTYPE_H_
