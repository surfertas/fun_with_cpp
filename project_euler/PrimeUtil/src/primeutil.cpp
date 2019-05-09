#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#include "primeutil.h"

namespace prime_util {
PrimeUtil::PrimeUtil() {};
PrimeUtil::~PrimeUtil() {};


auto PrimeUtil::mod_exponentiate(const size_t base, size_t exponent, const size_t mod) -> size_t
{
  if (mod == 1) { return 0; }
  auto c = 1;
  for (auto eprime = 0; eprime < exponent; eprime++) {
    c = (c * base) % mod;
  }
  return c;
}


auto PrimeUtil::naive_is_prime(const size_t n) -> bool
{
  if (n == 2 || n == 3) { return true; }  

  auto is_bool = false;
  auto scale = std::vector<size_t>(n-1);
  std::iota(scale.begin(), scale.end(), 2);
  auto it = scale.begin();
  while ((n % *it++) != 0) {}
  if (it == scale.end()) {
    is_bool = true;
  } 
  return is_bool;
}

// https://www.slideshare.net/prerna115/prime-10728467
// http://home.sandiego.edu/~dhoffoss/teaching/cryptography/10-Rabin-Miller.pdf
// https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
auto PrimeUtil::miller_rabin_is_prime(size_t n, size_t k) -> bool
{
  // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(2, n-2);

  if (n == 2 || n == 3) { return true; }  

  // write n as 2r·d + 1 with d odd (by factoring out powers of 2 from n − 1)
  auto d = n-1;
  auto r = 0;
  while (d % 2 == 0) {
    d>>=1;
    r+=1;
  }

  for (auto i=0; i < k; i++) {
    auto a = dis(gen);
    auto x = mod_exponentiate(a, d, n);
    if (!(x == 1 || x == (n-1))) {
      auto composite = true;
      for (auto j=0; j < r-1; j++) {
        x = mod_exponentiate(x, 2, n);
        if (x == (n-1)) {
            composite = false;
            break;
        }
      }
      if (composite) { return false; }
    }
  }
  return true;
}
} //prime_util


