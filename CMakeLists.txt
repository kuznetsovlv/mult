cmake_minimum_required(VERSION 3.10)

project(mult VERSION 2.2)

add_library(inputlib INTERFACE)
target_compile_features(inputlib INTERFACE cxx_std_20)
add_library(processlib INTERFACE)
target_compile_features(processlib INTERFACE cxx_std_20)
add_library(argslib INTERFACE)
target_compile_features(argslib INTERFACE cxx_std_20)
add_library(helplib INTERFACE)
target_compile_features(helplib INTERFACE cxx_std_20)

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

target_compile_options(argslib INTERFACE
        "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
        "$<${msvc_cxx}:-W3>"
)
target_compile_options(argslib INTERFACE
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

target_compile_options(helplib INTERFACE
        "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
        "$<${msvc_cxx}:-W3>"
)
target_compile_options(helplib INTERFACE
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

configure_file(env.h.in env.h)

add_subdirectory(input_reader)
add_subdirectory(process)
add_subdirectory(arguments)
add_subdirectory(print_help)

add_executable(mult main.cpp)

target_link_libraries(mult PUBLIC input inputlib)
target_include_directories(input PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries(mult PUBLIC process processlib)
target_include_directories(process PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries(mult PUBLIC arguments argslib)
target_include_directories(arguments PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries(mult PUBLIC print_help helplib)
target_include_directories(print_help PUBLIC "${PROJECT_BINARY_DIR}")

install(TARGETS mult RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB;RPM;TGZ;7Z")
set(CPACK_PACKAGE_NAME "mult")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "kuznetsovlv1981@gmail.com")
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr/local")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Multiplication table tests.")
set(CPACK_PACKAGE_VENDOR "Kuznetsov Leonid")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Kuznetsov Leonid <kuznetsovlv1981@gmail.com>")

include(CPack)
