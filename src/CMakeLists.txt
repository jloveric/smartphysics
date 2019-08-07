cmake_minimum_required (VERSION 2.6)

#list( APPEND CMAKE_CXX_FLAGS "-std=c++11 -O3 -fopenmp ${CMAKE_CXX_FLAGS}")


#find_package(Boost COMPONENTS math_c99)
#find_package(BoostCompute)

include_directories(${Boost_INCLUDE_DIRS})

message(STATUS "Source Boost include directories: " ${Boost_INCLUDE_DIRS})
message(STATUS "Source Boost libs: " ${Boost_LIBRARIES})

set(CMAKE_CXX_FLAGS "-O3 -march=native --std=c++17 ${CMAKE_CXX_FLAGS}")
add_library (
  smart
  SHARED
  main.cc
)