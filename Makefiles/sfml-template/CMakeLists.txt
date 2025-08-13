cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ==== online fetch ====
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# ==== src files ====
set(MY_DIR ${CMAKE_SOURCE_DIR}/src)
file(GLOB MY_FILES CONFIGURE_DEPENDS "${MY_DIR}/*.cpp")

# ==== executable ====
add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

if(MY_FILES)
    add_library(my_lib ${MY_FILES})
    target_include_directories(my_lib PUBLIC "${CMAKE_SOURCE_DIR}/include")
    target_link_libraries(main PRIVATE my_lib)
endif()

