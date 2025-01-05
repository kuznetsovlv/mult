cmake_minimum_required(VERSION 3.10)

project(mult VERSION 2.1)

add_library(inputlib INTERFACE)
target_compile_features(inputlib INTERFACE cxx_std_20)
add_library(processlib INTERFACE)
target_compile_features(processlib INTERFACE cxx_std_20)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(inputlib INTERFACE
        "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
        "$<${msvc_cxx}:-W3>"
)
target_compile_options(inputlib INTERFACE
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

target_compile_options(processlib INTERFACE
        "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
        "$<${msvc_cxx}:-W3>"
)
target_compile_options(processlib INTERFACE
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

configure_file(env.h.in env.h)

add_subdirectory(input)
add_subdirectory(process)

add_executable(mult main.cpp)

target_link_libraries(mult PUBLIC input inputlib)
target_include_directories(input PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries(mult PUBLIC process processlib)
target_include_directories(process PUBLIC "${PROJECT_BINARY_DIR}")
