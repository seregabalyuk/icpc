#include "head.h"
#include "../../trash/standard.ii"
#include "../../trash/test.ii"



int main(int args, char** argv) {
  ifstream fin(argv[1]);
  while(fin) {
    stringstream ssstandart, sstest;
    auto pos = fin.tellg();
    standard::checker(fin, ssstandart);
    fin.seekg(pos);
    test::checker(fin, sstest);
    if (ssstandart.str() != sstest.str()) {
      auto end = fin.tellg();
      fin.seekg(pos);
      cout << "\033[1;31mwrong answer!\033[0m\nTest: ";
      while (fin.tellg() != end) cout << (char)fin.get();
      cout << "\ncorrect answer: " << ssstandart.str();
      cout << "your answer: " << sstest.str();
      return 1;
    }
  }
  cout << "\033[1;32mTests passed\033[0m\n";
}
