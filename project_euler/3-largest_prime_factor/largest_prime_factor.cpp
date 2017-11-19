#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <math.h>

// 1. Had to move away from initializing large vectors, as resulted in bad_alloc
// and out of memory situation.
// 2. Had to hard code scale_max as using the input as the initializer variable
// to scale resulted in memory issues.

void usage()
{
  std::cout << "Need to enter a target number.\n";
  exit(1);
}

bool is_prime(size_t target) {
  using namespace std;
  bool is_bool;
  vector<size_t> scale(target-1);
  iota(scale.begin(), scale.end(), 2);
  auto it = scale.begin();
  while ((target % *it) != 0) {
    it++;
  }
  if (it == scale.end()) {
    is_bool = true;
  } else {
    is_bool =  false;
  }
  return is_bool;
}

int main(int argc, char** argv)
{
  // Arbitrarily set. Need to find a programmatic way to handle.
  const auto scale_max = 5000000;

  using namespace std;
  if (argc < 2) { usage(); }
  auto start = 2;
  auto target = atoll(argv[1]);
  vector<size_t> scale(scale_max);
  iota(scale.begin(), scale.end(), 2);
  unordered_set<size_t> primes;
  vector<size_t> factors;

  for (auto x : scale) {
    if (is_prime(x) == 0) {
      primes.insert(x);
      while ((target % x) == 0) {
        factors.emplace_back(x);
        target = target / x;
      }
      if (target==1) { break; }
    }
  } 
  std::cout << "Largest prime factor is: " << *(factors.end()-1) << "\n";
}
