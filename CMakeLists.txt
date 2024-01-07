cmake_minimum_required(VERSION 3.10)

project(mult VERSION 1.2)

add_library(rndlib INTERFACE)
target_compile_features(rndlib INTERFACE cxx_std_20)

configure_file(env.h.in env.h)

add_subdirectory(random)

add_executable(mult mult.cpp)

target_link_libraries(mult PUBLIC random rndlib)
target_include_directories(random PUBLIC "${PROJECT_BINARY_DIR}")
