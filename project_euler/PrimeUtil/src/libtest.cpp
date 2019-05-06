#include <iostream>
#include "../include/primeutil.h"
#include "gtest/gtest.h"


TEST(PUTest, ModularExponentEvenTest) {
  auto base = 7;
  auto exponent = 256;
  auto mod = 13;

  prime_util::PrimeUtil p;

  auto result = p.mod_exponentiate(base,exponent,mod);
  EXPECT_EQ(result, 9);
}

TEST(PUTest, ModularExponentOddTest) {
  auto base = 2;
  auto exponent = 9;
  auto mod = 3;

  prime_util::PrimeUtil p;

  auto result = p.mod_exponentiate(base,exponent,mod);
  EXPECT_EQ(result, 2);
}
