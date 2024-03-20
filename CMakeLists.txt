cmake_minimum_required(VERSION 3.27)

project(UVPlayground VERSION 0.1 LANGUAGES CXX)
option(CMAKE_VERBOSE_MAKEFILE "show compilation process" ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "compile_commands.json generate")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(example_idle examples/Idle.cpp)
target_compile_features(example_idle PUBLIC cxx_std_23)
find_package(libuv REQUIRED)
target_link_libraries(example_idle PRIVATE libuv::uv)
target_include_directories(example_idle
  PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  "$<INSTALL_INTERFACE:include>"
  "/usr/local/include"
  "/usr/include"
)
