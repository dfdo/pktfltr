project(GoogleTestUT)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        b5401fe # release-1.13.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(GoogleTestUT dummy_tests.cpp)

target_link_libraries(
        GoogleTestUT
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GoogleTestUT)


