#include <vector>
#include <numeric>
#include <algorithm>

#include "libprime.h"

namespace prime_util {
PrimeUtil::PrimeUtil() {};
PrimeUtil::~PrimeUtil() {};

size_t PrimeUtil::is_prime(size_t target)
{
  size_t is_bool;
  std::vector<size_t> scale(target-1);
  std::iota(scale.begin(), scale.end(), 2);
  auto it = scale.begin();
  while ((target % *it++) != 0) {}
  if (it == scale.end()) {
    is_bool = 0;
  } else {
    is_bool = 1;
  }
  return is_bool;
}
} //prime_util


