cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(Application VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE SRC_CLIENT_FILES Testing/*.cpp)

add_library(PixTerm STATIC ${SRC_FILES})
target_include_directories(PixTerm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/Vendor)
target_precompile_headers(PixTerm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Pixterm.h)

add_executable(Application ${SRC_CLIENT_FILES})
target_include_directories(Application PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/Vendor )
target_precompile_headers(Application PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Pixterm.h)
target_link_libraries(Application PUBLIC PixTerm)



