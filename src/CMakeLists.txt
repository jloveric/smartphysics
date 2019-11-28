cmake_minimum_required (VERSION 2.6)

INCLUDE_DIRECTORIES(
${PROJECT_SOURCE_DIR}/src
${PROJECT_SOURCE_DIR}/jali/inst-jali/include
${PROJECT_SOURCE_DIR}/jali/inst-tpl/include
)

link_directories(
${PROJECT_SOURCE_DIR}/src
${PROJECT_SOURCE_DIR}/jali/inst-jali/lib
${PROJECT_SOURCE_DIR}/jali/inst-tpl/lib
)

message(STATUS "Source Boost include directories: " ${Boost_INCLUDE_DIRS})
message(STATUS "Source Boost libs: " ${Boost_LIBRARIES})

set(CMAKE_CXX_FLAGS "-g -march=native --std=c++2a ${CMAKE_CXX_FLAGS}")
add_library (
  smart
  SHARED
  main.cc
)