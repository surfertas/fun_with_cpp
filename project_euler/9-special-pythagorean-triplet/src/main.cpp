// @author Tasuku Miura

#include <iostream>
#include <tuple>

auto isPythogoreanTriplet(const size_t a, const size_t b, const size_t c)
    -> bool {
  auto testOne = a < b && b < c;
  auto testTwo = (a*a + b*b) == c*c;
  return testOne && testTwo;
}

auto generatePythogoreanTriplet(const size_t m, const size_t n)
    ->  std::tuple<size_t, size_t, size_t> {
  auto a = 2 * m * n;
  auto b = m * m - n * n;
  auto c = m * m + n * n;
  std::cout << "a:" << a << " " << b << " "  << c << "\n";
  std::tuple<size_t, size_t, size_t> triplet(a,b,c);

  return triplet;
}

int main(int argc, char** argv)
{
  auto m = 2;
  while (true) {
    for (auto n = 1; n <= m; n++) {
      auto triplet = generatePythogoreanTriplet(m,n);
      auto a = std::get<0>(triplet);
      auto b = std::get<1>(triplet);
      auto c = std::get<2>(triplet);

      auto isTriplet = isPythogoreanTriplet(a, b, c);
      if (isTriplet) {
        std::cout << a << " " << b << " "  << c << "\n";
        if ((a + b + c) == 1000) {
          std::cout  << " Solution: " << a * b * c << "\n";
          break;
        }
      }
    }
    break;
    m++;
  }
}
