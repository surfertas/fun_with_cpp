#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <math.h>

#include "libprime.h"

// 1. Had to move away from initializing large vectors, as resulted in bad_alloc
// and out of memory situation.
// 2. Had to hard code scale_max as using the input as the initializer variable
// to scale resulted in memory issues.

void usage()
{
  std::cout << "Need to enter a target number.\n";
  exit(1);
}

int main(int argc, char** argv)
{
  // Arbitrarily set. Need to find a programmatic way to handle.
  const auto scale_max { 50000 };//00000;

  if (argc < 2) { usage(); }
  auto target = std::atoll(argv[1]);
  auto scale = std::vector<size_t>(scale_max);
  std::iota(scale.begin(), scale.end(), 2);
  std::unordered_set<size_t> primes;
  std::vector<size_t> factors;

  prime_util::PrimeUtil p;
  for (auto x : scale) {
    if (p.is_prime(x)) {
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
