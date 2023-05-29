cmake_minimum_required(VERSION 3.16)

include(cmake/c-paranoic-debug-flags.cmake)

project(utils-c C)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(tests)
