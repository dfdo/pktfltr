cmake_minimum_required(VERSION 3.24)
project(pktfltr)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

FILE(GLOB GlobAllSrc src/*.cpp)

add_library(pktfltr library.cpp ${GlobAllSrc})
