#include "slp.h"

#include <utility>
#include "util.h"

A_stm A_CompoundStm(A_stm stm1, A_stm stm2) {
  auto s = static_cast<A_stm>(checked_malloc(sizeof(A_stm)));
  s->kind = A_stm_::A_compoundStm;
  s->u.compound.stm1 = stm1;
  s->u.compound.stm2 = stm2;
  return s;
}

A_stm A_AssignStm(std::string id, A_exp exp) {
  auto s = static_cast<A_stm>(checked_malloc(sizeof(A_stm)));
  s->kind = A_stm_::A_assignStm;
  s->u.assign.id = std::move(id);
  s->u.assign.exp = exp;
  return s;
}

A_stm A_PrintStm(A_expList exps) {
  auto s = static_cast<A_stm>(checked_malloc(sizeof(A_stm)));
  s->kind = A_stm_::A_printStm;
  s->u.print.exps = exps;
  return s;
}

A_exp A_IdExp(std::string id) {
  auto e = static_cast<A_exp>(checked_malloc(sizeof(A_exp)));
  e->kind = A_exp_::A_idExp;
  e->u.id = std::move(id);
  return e;
}

A_exp A_NumExp(int num) {
  auto e = static_cast<A_exp>(checked_malloc(sizeof(A_exp)));
  e->kind = A_exp_::A_numExp;
  e->u.num = num;
  return e;
}

A_exp A_OpExp(A_exp left, A_binop oper, A_exp right) {
  auto e = static_cast<A_exp>(checked_malloc(sizeof(A_exp)));
  e->kind = A_exp_::A_opExp;
  e->u.op.left = left;
  e->u.op.oper = oper;
  e->u.op.right = right;
  return e;
}

A_exp A_EseqExp(A_stm stm, A_exp exp) {
  auto e = static_cast<A_exp>(checked_malloc(sizeof(A_exp)));
  e->kind = A_exp_::A_eseqExp;
  e->u.eseq.stm = stm;
  e->u.eseq.exp = exp;
  return e;
}

A_expList A_PairExpList(A_exp head, A_expList tail) {
  auto e = static_cast<A_expList>(checked_malloc(sizeof(A_expList)));
  e->kind = A_expList_::A_pairExpList;
  e->u.pair.head = head;
  e->u.pair.tail = tail;
  return e;
}

A_expList A_LastExpList(A_exp last) {
  auto e = static_cast<A_expList>(checked_malloc(sizeof(A_expList)));
  e->kind = A_expList_::A_lastExpList;
  e->u.last = last;
  return e;
}
