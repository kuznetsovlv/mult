add_library(arguments STATIC path.cpp arg_exception.cpp)

target_include_directories(arguments INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(arguments PUBLIC argslib)