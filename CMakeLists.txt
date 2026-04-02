cmake_minimum_required(VERSION 3.16)
project(Sand)

# set (CMAKE_CXX_STANDARD 11)
# set (CMAKE_CXX_STANDARD_REQUIRED true)
# set (CMAKE_BUILD_TYPE Debug)

# This chunk of code exists to make my clangd LSP in Helix work with external headers
# https://mzhang.io/posts/2022-03-03-clangd-in-nix/
# Generate the `compile_commands.json` file.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
    ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()


project(Plots)

add_subdirectory(matplotplusplus)

add_executable(game main.cpp)

target_link_libraries(game PUBLIC matplot)
