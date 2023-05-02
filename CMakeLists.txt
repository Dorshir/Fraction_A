cmake_minimum_required(VERSION 3.24)
project(FractionTests)

set(CMAKE_CXX_STANDARD 14)

add_executable(FractionTests Demo.cpp sources/Fraction.hpp doctest.h TestCounter.cpp Test.cpp sources/Fraction.cpp)
