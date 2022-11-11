#include "util.h"
#include <iostream>

void *checked_malloc(int len) {
  auto *p = std::malloc(len);
  if (!p) {
    std::cerr << "\nRan out of memory!\n";
    std::exit(1);
  }
  return p;
}

U_boolList U_BoolList(bool head, U_boolList tail) {
  auto list = static_cast<U_boolList>(checked_malloc(sizeof(U_boolList)));
  list->head = head;
  list->tail = tail;
  return list;
}