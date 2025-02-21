add_library(input STATIC input_reader.cpp stop_exception.cpp)

target_include_directories(input INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(input PUBLIC inputlib)
