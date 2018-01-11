#include <iostream>
#include <vector>
#include <algorithm>

// Solved with naive implementation as first pass.

int main(int argc, char** argv)
{
  auto up_bound = 20;
  
  std::vector<size_t> range(up_bound);
  std::iota(range.begin(), range.end(), 1);
  auto smallest = 0;
  auto candidate = up_bound;

  while (true) {
    auto found = find_if(range.begin(), range.end(), [&](size_t x) {
        return (candidate % x) != 0;
    });

    if (found == range.end()) {
      smallest = candidate;
      break;
    }
    candidate++;
  }     
  std::cout << "smallest " << smallest << std::endl;
}
