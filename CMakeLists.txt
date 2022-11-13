cmake_minimum_required(VERSION 3.16)
project(heavykeeper LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-std=c++14 -fpermissive -O3)

include_directories(include)
include_directories(HeavyKeeper)
include_directories(init)

aux_source_directory(./HeavyKeeper ALL_SRCS)
aux_source_directory(./init ALL_SRCS)

add_executable(main ${ALL_SRCS} main.cpp)










