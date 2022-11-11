#include "prog1.h"
#include <iostream>
#include <gtest/gtest.h>

#if 0
int main() {
  A_stm myProg = prog();
  int printStmArgs = maxArgs(myProg);

  std::cout << myProg << '\n';
  std::cout << "The maximum argument number of any print sub-statement is"
            << printStmArgs << '\n';
  return 0;
}
#endif