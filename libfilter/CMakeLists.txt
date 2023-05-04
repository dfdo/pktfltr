add_library(libpktfltr STATIC src/expr_parser.cpp)

target_include_directories(libpktfltr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)