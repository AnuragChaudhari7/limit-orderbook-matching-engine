# Get the source files
file(GLOB SOURCES
    "*.cpp")

# Make executable
add_executable(main.out ${SOURCES})

# Copy all data files from project root data/ directory to the build output directory after build
file(GLOB DATA_FILES "${CMAKE_SOURCE_DIR}/data/*")
add_custom_command(TARGET main.out POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:main.out>/data
)
foreach(datafile ${DATA_FILES})
    add_custom_command(TARGET main.out POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${datafile}
        $<TARGET_FILE_DIR:main.out>/data)
endforeach()

# Include headers
target_include_directories(main.out PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})