cmake_minimum_required(VERSION 3.22)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(tiger-compiler)

# Set Debug mode for this project.
set(CMAKE_BUILD_TYPE Debug)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++2a")
enable_testing()

add_executable(tiger_compiler)
add_subdirectory(chap1)

target_link_libraries(tiger_compiler chap1)

target_link_libraries(
        tiger_compiler
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tiger_compiler)