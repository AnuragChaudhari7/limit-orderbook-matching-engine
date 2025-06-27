# Get the source files
set(SOURCES
    main.cpp
    Order.cpp
    LimitOrder.cpp
    OrderBook.cpp)

# Make executable
add_executable(main.out ${SOURCES})

# Include headers
target_include_directories(main.out PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})