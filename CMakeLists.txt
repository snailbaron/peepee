cmake_minimum_required(VERSION 3.12)

project(peepee VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(deps)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wno-missing-field-initializers)
endif()

add_library(peepee
    error.cpp
    headers.cpp
    init.cpp
    request.cpp
)
target_include_directories(peepee PUBLIC include)
target_link_libraries(peepee
    PUBLIC CURL::libcurl e
)

add_subdirectory(example)
