#ifndef LIBPRIME_H
#define LIBPRIME_H

#include <vector>
#include <algorithm>

namespace prime_util {
class PrimeUtil {

public:
  PrimeUtil();
  ~PrimeUtil();

  auto is_prime(size_t target) -> bool;

}; 
} //prime_util

#endif // LIBPRIME_H  
