#include "prog1.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(chap1, test) {
  A_stm myProg = prog();
  int printStmArgs = maxArgs(myProg);

  std::cout << myProg << '\n';
  std::cout << "The maximum argument number of any print sub-statement is"
            << printStmArgs << '\n';
}