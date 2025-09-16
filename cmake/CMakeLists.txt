cmake_minimum_required(VERSION 3.19)

project(x)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(main "${SRC}")

target_include_directories(main PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_compile_definitions(main PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/data/")
