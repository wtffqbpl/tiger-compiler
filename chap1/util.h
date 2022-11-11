#pragma once

#include <cassert>

void *checked_malloc(int);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_ {
  bool head;
  U_boolList tail;
};
U_boolList U_BoolList(bool head, U_boolList tail);