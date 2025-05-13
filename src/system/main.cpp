#include "head.h"

#define STRINGIFY(x) #x
#define INCLUDE_PATH(x) STRINGIFY(x)
#include INCLUDE_PATH(ALGORITHM)
#include INCLUDE_PATH(CHECKER)

int main(int args, char** argv) {
  ifstream fin(argv[1]);
  int q;
  fin >> q;
  while(q --) {
    checker(fin, cout);
  }
}