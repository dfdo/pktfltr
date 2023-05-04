cmake_minimum_required(VERSION 3.25)

project(pktfltr VERSION 0.1
                DESCRIPTION "Network Packet Filter"
                LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libfilter)
add_subdirectory(tests EXCLUDE_FROM_ALL)

add_executable(pktfltr main.cpp)

target_link_libraries(pktfltr libpktfltr)
