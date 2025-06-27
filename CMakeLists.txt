cmake_minimum_required(VERSION 3.10)

# Name project (and versions/lang) and force std=c++17
project(LimitOrderBook VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set compiler flags
add_compile_options(-Werror)

# Add src/ subdir
add_subdirectory(src)