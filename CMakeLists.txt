cmake_minimum_required(VERSION 3.12)

project(peepee)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(deps)

add_library(peepee
    init.cpp
    request.cpp
)
target_include_directories(peepee PUBLIC include)
target_link_libraries(peepee
    PUBLIC CURL::libcurl e
)

add_subdirectory(example)
