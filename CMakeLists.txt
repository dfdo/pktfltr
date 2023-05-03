cmake_minimum_required(VERSION 3.25)
project(pktfltr)

set(CMAKE_CXX_STANDARD 20)

add_executable(pktfltr main.cpp tests/dummy_tests.cpp)

add_subdirectory(tests EXCLUDE_FROM_ALL)
