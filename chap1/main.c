#include "prog1.h"
#include <stdio.h>

int main() {
  A_stm myProg = prog();
  int printStmArgs = maxArgs(myProg);

  printf("%p\n", myProg);
  printf("The maximum argument number of any print sub-statement is %d.\n", printStmArgs);

  return 0;
}
