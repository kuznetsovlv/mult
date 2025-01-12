add_library(process STATIC process.cpp init.cpp test.cpp)

target_include_directories(process INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(process PUBLIC processlib)

target_link_libraries(process PUBLIC input)
