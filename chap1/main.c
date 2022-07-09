#include "prog1.h"
#include <stdio.h>

int main() {
  /*
   * Testcase:
   *    a := 5 + 3;
   *    b := (print(a , a - 1), 10 * a);
   *    print (b)
   */
  A_stm myProg = A_CompoundStm(
          A_AssignStm("a", A_OpExp(A_NumExp(5), A_plus, A_NumExp(3))),
          A_CompoundStm(
                  A_AssignStm("b", A_EseqExp(
                          A_PrintStm(A_PairExpList(
                                  A_IdExp("a"),
                                  A_LastExpList(A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1)))
                                  )),
                          A_OpExp(A_NumExp(10), A_times, A_IdExp("a"))
                          )),
                  A_PrintStm(A_LastExpList(A_IdExp("b")))
                  )
          );

  printf("%p\n", myProg);
  printf("Hello world\n");

  return 0;
}
