cmake_minimum_required(VERSION 3.22)
project(ayed_01)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
include_directories(src)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

