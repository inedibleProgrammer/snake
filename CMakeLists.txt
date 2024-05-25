cmake_minimum_required(VERSION 3.5)

project(snake C)

add_compile_options("-g")

add_subdirectory(vendor)
add_subdirectory(test)
add_subdirectory(src)
