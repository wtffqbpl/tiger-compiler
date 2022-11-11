/*
 * util.c - commonly used utility functions.
 */

#include "util.h"
#include <string>
void *checked_malloc(int len) {
  void *p = malloc(len);
  if (!p) {
    fprintf(stderr, "\nRan out of memory!\n");
    exit(1);
  }
  return p;
}

std::string String(char *s) {
  std::string p = std::string(s);
  return p;
}

U_boolList U_BoolList(bool head, U_boolList tail) {
  auto list = static_cast<U_boolList>(checked_malloc(sizeof(U_boolList)));
  list->head = head;
  list->tail = tail;
  return list;
}
