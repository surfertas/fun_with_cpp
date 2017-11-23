#include <iostream>
#include <vector>


bool is_palindrome(size_t x)
{
  std::vector<size_t> number;
  auto temp = x;
  while (temp != 0) {
    number.emplace_back(temp % 10);
    temp = temp/10;
  }

  auto i = 0;
  for (auto rit = number.rbegin(); rit < number.rend(); rit++) {
    if (*rit != number[i++])
        return false; 
  }
  return true; 
}

int main(int argc, char** argv)
{
  auto largest = 0;
  for (auto i = 100; i < 999; i++) {
    for (auto j = 100; j < 999; j++) {
      auto candidate = i * j;
      if (is_palindrome(candidate) && (candidate > largest))
          largest = candidate;
    }
  }
  std::cout << largest << std::endl;
}
