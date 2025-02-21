add_library(print_help STATIC print_help.cpp)

target_include_directories(print_help INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(print_help PUBLIC helplib)