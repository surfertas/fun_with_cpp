#include <iostream>
#include <vector>
#include <algorithm>

void usage() {
  std::cout << "Enter natural number > 0 \n";
  exit(1);
}

int main(int argc, char** argv)
{
  using namespace std;

  if (argc < 2) { usage(); }

  auto ub = stoi(argv[1]);
  auto sum = 0;

  vector<size_t> lst(ub);

  // Build vector of sequentially increasing size_t numbers.
  iota(lst.begin(), lst.end(), 0);

  auto test = [&](size_t number) {
    if (number % 3 == 0 || number % 5 == 0) {
      sum += number;
    }
  };
  for_each(lst.begin(), lst.end(), test);
  cout << sum << "\n";
}
