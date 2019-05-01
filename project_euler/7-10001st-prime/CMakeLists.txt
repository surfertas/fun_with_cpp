cmake_minimum_required(VERSION 2.8.9)

project (10001st-prime)

set(CMAKE_CXX_STANDARD 11)

find_library(PRIMEUTIL_LIB libPrimeUtil.so)
message(STATUS ${PRIMEUTIL_LIB})

add_executable(10001st-prime src/main.cpp)

target_link_libraries(10001st-prime PRIVATE ${PRIMEUTIL_LIB})

