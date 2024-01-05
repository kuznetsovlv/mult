cmake_minimum_required(VERSION 3.10)

project(mult VERSION 1.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_REQUIRED True)

configure_file(env.h.in env.h)

add_subdirectory(random)

add_executable(mult mult.cpp)

target_link_libraries(mult PUBLIC random)
target_include_directories(random PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/random")
