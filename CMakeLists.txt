cmake_minimum_required(VERSION 3.10)

project(mult VERSION 1.2)

add_library(rndlib INTERFACE)
target_compile_features(rndlib INTERFACE cxx_std_20)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(rndlib INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-W3>"
)
target_compile_options(rndlib INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)


configure_file(env.h.in env.h)

add_subdirectory(random)

add_executable(mult mult.cpp)

target_link_libraries(mult PUBLIC random rndlib)
target_include_directories(random PUBLIC "${PROJECT_BINARY_DIR}")
