#pragma once

#include <cassert>
#include <string>

#define TRUE 1
#define FALSE 0
#define max(a, b) ((a) > (b) ? (a) : (b))

void *checked_malloc(int);
std::string String(char *);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_ {
  bool head;
  U_boolList tail;
};
U_boolList U_BoolList(bool head, U_boolList tail);