cmake_minimum_required(VERSION 2.8.9)

project (largest_prime_factor)

set(CMAKE_CXX_STANDARD 11)

find_library(PRIMEUTIL_LIB libPrimeUtil.so)
message(STATUS ${PRIMEUTIL_LIB})

add_executable(largest_prime_factor src/main.cpp)

target_link_libraries(largest_prime_factor PRIVATE ${PRIMEUTIL_LIB})

