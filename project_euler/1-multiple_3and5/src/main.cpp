#include <iostream>
#include <vector>
#include <algorithm>

void usage() {
  std::cout << "Enter natural number > 0 \n";
  exit(1);
}

int main(int argc, char** argv)
{
  if (argc < 2) { usage(); }

  auto ub = std::stoi(argv[1]);
  auto sum = 0;

  std::vector<size_t> lst(ub);

  // Build vector of sequentially increasing size_t numbers.
  std::iota(lst.begin(), lst.end(), 0);

  auto test = [&](size_t number) {
    if (number % 3 == 0 || number % 5 == 0) {
      sum += number;
    }
  };
  for_each(lst.begin(), lst.end(), test);
  std::cout << sum << "\n";
}
