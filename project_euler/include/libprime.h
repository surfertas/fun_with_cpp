#ifndef LIBPRIME_H
#define LIBPRIME_H

#include <vector>
#include <algorithm>

namespace prime_util {
class PrimeUtil {

public:
  PrimeUtil();
  ~PrimeUtil();

  size_t is_prime(size_t target);

}; 
} //prime_util

#endif // LIBPRIME_H  
