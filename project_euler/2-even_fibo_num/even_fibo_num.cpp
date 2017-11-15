// author: Tasuku Miura
// By considering the terms in the Fibonacci sequence whose values do not exceed
// four million, find the sum of the even-valued terms.

#include <iostream>

void usage() {
  std::cout << "Need a natural number as upper bound.\n";
  exit(1);
}

int main(int argc, char** argv) {
  if (argc < 2) { usage(); }
  auto ub = atoi(argv[1]);
  auto f0 = 0;
  auto f1 = 1;
  auto sum = 0;

  while (f1 < ub) {
    auto f2 = 0;
    f2 = f0 + f1;
    if (f2 % 2 == 0) {
      sum+=f2;
    }
    f0 = f1;
    f1 = f2; 
  }
  std::cout << "Sum is: " << sum << "\n";
}

