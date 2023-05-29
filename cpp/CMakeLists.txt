cmake_minimum_required(VERSION 3.16)

include(cmake/cpp-paranoic-debug-flags.cmake)

project(utils-cpp CXX)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(tests)
