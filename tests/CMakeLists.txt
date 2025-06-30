# Collect all test source files
file(GLOB TEST_SOURCES "*.cpp")

# Create test executable
add_executable(OrderBookTests ${TEST_SOURCES})

# Include project headers
target_include_directories(OrderBookTests PRIVATE ${PROJECT_SOURCE_DIR}/src)

# Link GTest and your source files
target_link_libraries(OrderBookTests
  gtest_main
)

# Link your actual project code (optional if needed by tests)
target_link_libraries(OrderBookTests 
    gtest_main
    LimitOrderBook)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(OrderBookTests)