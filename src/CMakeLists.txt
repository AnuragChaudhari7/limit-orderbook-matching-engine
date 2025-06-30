# Gather all logic files except main.cpp
file(GLOB LOGIC_SOURCES 
    "Order.cpp"
    "OrderBook.cpp"
    "LimitOrder.cpp"
    "CSVParser.cpp"
)

# Create a static library for reuse
add_library(LimitOrderBook STATIC ${LOGIC_SOURCES})
target_include_directories(LimitOrderBook PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Build the main sanity-testing binary
add_executable(main.out main.cpp)
target_link_libraries(main.out PRIVATE LimitOrderBook)

# Always copy the latest version of data/ into build/src/
add_custom_target(copy_data ALL
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/src/data
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/data
            ${CMAKE_BINARY_DIR}/src/data
    COMMENT "Copying fresh data directory every build"
)
