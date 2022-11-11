#include "prog1.h"

A_stm prog() {
  /*
   * Testcase:
   *    a := 5 + 3;
   *    b := (print(a , a - 1), 10 * a);
   *    print (b)
   */
  auto astmt = A_AssignStm("a", A_OpExp(A_NumExp(5), A_plus, A_NumExp(3)));
  auto print_stmt = A_PrintStm(A_PairExpList(
      A_IdExp("a"),
      A_LastExpList(A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1)))));
  auto multiply_stmt = A_OpExp(A_NumExp(10), A_times, A_IdExp("a"));
  auto print_b_stmt = A_PrintStm(A_LastExpList(A_IdExp("b")));
  auto b_assign_stmt = A_AssignStm("b", A_EseqExp(print_stmt, multiply_stmt));

  return A_CompoundStm(astmt, A_CompoundStm(b_assign_stmt, print_b_stmt));
}

int maxStmPrintArgs(A_stm stm);

int maxExpPrintArgs(A_exp exp) {
  int res = 0;
  switch (exp->kind) {
    case A_exp_::A_opExp: {
      int leftNum = maxExpPrintArgs(exp->u.op.left);
      int rightNum = maxExpPrintArgs(exp->u.op.right);
      res = std::max(leftNum, rightNum);
      break;
    }
    case A_exp_::A_eseqExp: {
      int stmNum = maxStmPrintArgs(exp->u.eseq.stm);
      int expNum = maxExpPrintArgs(exp->u.eseq.exp);
      res = std::max(stmNum, expNum);
      break;
    }
    default:
      break;
  }
  return res;
}

int maxStmPrintArgs(A_stm stm) {
  int res = 0;
  switch (stm->kind) {
    case A_stm_::A_compoundStm: {
      int stm1 = maxStmPrintArgs(stm->u.compound.stm1);
      int stm2 = maxStmPrintArgs(stm->u.compound.stm2);
      res = std::max(stm1, stm2);
      break;
    }
    case A_stm_::A_assignStm: {
      res = maxExpPrintArgs(stm->u.assign.exp);
      break;
    }
    case A_stm_::A_printStm: {
      res = 2;
      break;
    }
  }
  return res;
}

// Find the argument numbers of any print sub-statement.
int maxArgs(A_stm stm) {
  return maxStmPrintArgs(stm);
}

typedef struct table *Table_;

struct table { std::string id; int value; Table_ tail; };
Table_ Table(std::string id, int value, struct table *tail) {
  auto t = static_cast<Table_>(checked_malloc(sizeof(Table_)));
  t->id = std::move(id);
  t->value = value;
  t->tail = tail;

  return t;
}

// interpret straight-line program.
void interp(A_stm stm) {
}

