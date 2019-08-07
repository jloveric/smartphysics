cmake_minimum_required(VERSION 3.0.0)

MESSAGE( STATUS "Boost paths:         " ${Boost_LIBRARIES} )

INCLUDE_DIRECTORIES(
${PROJECT_SOURCE_DIR}/src
)

link_directories(
${PROJECT_SOURCE_DIR}/src
)

set(OTHER_LIBS smart)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${BoostCompute_INCLUDE_DIRS})
message(STATUS "Unit Boost include directories: " ${Boost_INCLUDE_DIRS})
message(STATUS "Unit Boost libs: " ${Boost_LIBRARIES})

set(CMAKE_CXX_FLAGS "-g -march=native --std=c++17 ${CMAKE_CXX_FLAGS}")

add_executable(testNearestNeighbor testNearestNeighbor.cc)
target_link_libraries(testNearestNeighbor ${OTHER_LIBS} ${Boost_LIBRARIES})

add_executable(testRegistry testRegistry.cc)
target_link_libraries(testRegistry ${OTHER_LIBS} ${Boost_LIBRARIES})

add_executable(testAdvectionUpdater testAdvectionUpdater.cc)
target_link_libraries(testAdvectionUpdater ${OTHER_LIBS} ${Boost_LIBRARIES})