#include <vector>
#include <numeric>
#include <algorithm>

#include "primeutil.h"

namespace prime_util {
PrimeUtil::PrimeUtil() {};
PrimeUtil::~PrimeUtil() {};

auto PrimeUtil::is_prime(size_t target) -> bool
{
  auto is_bool { false };
  auto scale = std::vector<size_t>(target-1);
  std::iota(scale.begin(), scale.end(), 2);
  auto it = scale.begin();
  while ((target % *it++) != 0) {}
  if (it == scale.end()) {
    is_bool = true;
  } 
  return is_bool;
}
} //prime_util


