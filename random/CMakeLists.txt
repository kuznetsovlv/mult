add_library(random STATIC random.cpp)

target_include_directories(random INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(random PUBLIC rndlib)
