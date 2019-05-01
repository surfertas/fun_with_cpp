// @author Tasuku Miura
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that
// the 6th prime is 13.
// What is the 10 001st prime number?

#include <iostream>
#include <primeutil.h>

int main(int argc, char** argv)
{
  auto prime_count = 0;
  auto i = 2;
  prime_util::PrimeUtil p;
  while (true) {
    if (p.is_prime(i) == true) {
      prime_count++;
      if (prime_count == 10001) {
        break;
      }
    }
    i++;
  } 
  std::cout << "10001 prime is: " << i << "\n";
}
