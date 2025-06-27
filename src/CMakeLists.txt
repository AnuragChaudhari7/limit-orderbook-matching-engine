# Get the source files
set(LOGIC_SOURCES
    Order.cpp
    LimitOrder.cpp
    OrderBook.cpp)

# Build library
add_library(LimitOrderBook STATIC ${LOGIC_SOURCES})
target_include_directories(LimitOrderBook PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Main program for sanity/manual testing
add_executable(main.out main.cpp)
target_link_libraries(main.out PRIVATE LimitOrderBook)