#include <iostream>
#include <unordered_set>
#include <algorithm>

void usage()
{
  std::cout << "Need to enter a target number.\n";
  exit(1);
}

std::vector<size_t> get_prime_factors(size_t target)
{
  using namespace std;

  unordered_set<size_t> found;
  vector<size_t> factors;
  auto start = 2;
  vector<size_t> scale(target);
  iota(scale.begin(), scale.end(), start);
  auto base = start;
  auto multiple = 0;

  while (base < target) {
    auto fit = find_if(found.begin(), found.end(), [&](size_t x) {
      return x == base;
    });

    if (fit == found.end()) {
      factors.push_back(base);
    }
  
    auto sit = find_if(scale.begin(), scale.end(), [&](size_t x) {
      return x == base;
    });

    while (sit != scale.end()) {
      multiple = base * (*sit);
      auto fit = found.find(multiple);
      if (fit == found.end()) {
        found.insert(multiple);
      }
      sit++;
    }
    while (found.find(++base) != found.end()) {};
  }
  return factors;
}


int main(int argc, char** argv)
{
  using namespace std;
  if (argc < 2) { usage(); }
  auto start = 2;
  vector<size_t> primes = get_prime_factors(atoi(argv[1]));
  for (auto p : primes) {
    cout << p << "\n";
  }
}
