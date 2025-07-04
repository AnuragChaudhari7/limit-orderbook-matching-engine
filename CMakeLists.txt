cmake_minimum_required(VERSION 3.10)

# Name project (and versions/lang) and force std=c++17
project(LimitOrderBook VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Allow testing
include(CTest)
enable_testing()

# Download GTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Only download in top-level build
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Set compiler flags
add_compile_options(-Werror)

# Add subdirs
add_subdirectory(src)
#TODO: Add this back later...
#add_subdirectory(tests)