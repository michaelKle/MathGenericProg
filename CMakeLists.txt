project(MathGenericProgramming)

set(PROJECT_VERSION 1.0)
cmake_minimum_required(VERSION 3.18)

find_package(Catch2 3 REQUIRED)

add_subdirectory(LeetCode)
add_subdirectory(GeeksForGeeks)

enable_testing()