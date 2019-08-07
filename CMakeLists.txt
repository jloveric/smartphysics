cmake_minimum_required(VERSION 3.0.0)
project(smartphysics)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS system filesystem unit_test_framework date_time regex log thread)
find_package (OpenMP REQUIRED)

if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

include_directories(src)
add_subdirectory(src)
add_subdirectory(test)
add_executable(smartphysics src/main.cc)

enable_testing()
add_test(testNearestNeighbor test/testNearestNeighbor)
