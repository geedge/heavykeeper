cmake_minimum_required(VERSION 3.16)
project(heavykeeper LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-std=c++14 -fpermissive -O3)

add_subdirectory(/home/zhang/桌面/heavykeeper/third-party/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

include_directories(../tools)
include_directories(../include)
aux_source_directory(../tools ALL_SRCS)
aux_source_directory(../HeavyKeeper ALL_SRCS)



add_executable(main ${ALL_SRCS} gtest.cpp)
target_link_libraries(main gtest gtest_main)
