cmake_minimum_required(VERSION 2.8.9)

project (summation_of_primes)

set(CMAKE_CXX_STANDARD 11)

find_library(PRIMEUTIL_LIB libPrimeUtil.so)
message(STATUS ${PRIMEUTIL_LIB})

add_executable(summation_of_primes src/main.cpp)

target_link_libraries(summation_of_primes PRIVATE ${PRIMEUTIL_LIB})

