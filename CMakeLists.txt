cmake_minimum_required(VERSION 3.9)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Games_Engineering)

### Setup Directories ###
# Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Output all DLLs from all libs into main build folder
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

### Add External Deps ###
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

### Build ###
file(GLOB_RECURSE SOURCES source/*.cpp source/*.h)
add_executable(MAIN ${SOURCES})
target_include_directories(MAIN PRIVATE ${SFML_INCS})
target_link_libraries(MAIN sfml-graphics)
set_target_properties(MAIN PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration))
add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/res" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/res)
add_dependencies(MAIN copy_resources)
