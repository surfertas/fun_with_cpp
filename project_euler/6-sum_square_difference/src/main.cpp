#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main ()
{
  auto target = 100;
  std::vector<size_t> range(target);
  std::iota(range.begin(), range.end(), 1);
  auto sum_of_square = 0;
  auto square_of_sum = 0;

  // Calculate sum of squares.
  std::for_each(range.begin(), range.end(), [&](size_t x) {
    sum_of_square += x*x;
  });
  
  // Calculate square of sums.
  auto sum = std::accumulate(range.begin(), range.end(), 0);
  square_of_sum = sum * sum;

  auto result = square_of_sum - sum_of_square;
  std::cout << "Difference: " << result << std::endl;
}
