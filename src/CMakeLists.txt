# Gather source files
file(GLOB SOURCES "*.cpp")

# Define the main executable
add_executable(main.out ${SOURCES})

# Include headers
target_include_directories(main.out PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Define a custom target to copy data/ on every build
add_custom_target(copy_data ALL
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/src/data
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/data
            ${CMAKE_BINARY_DIR}/src/data
    COMMENT "Copying fresh data directory every build"
)
