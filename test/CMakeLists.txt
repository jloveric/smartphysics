cmake_minimum_required(VERSION 3.0.0)

MESSAGE( STATUS "Boost paths:         " ${Boost_LIBRARIES} )

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

#link_directories(jali/inst-jali/lib)
#include_directories(src jali/inst-jali/include)


#-lerror_handling -lgeometry -lmesh -lsimple_mesh -lmstk_mesh 
#-L/home/john/KUIPER/jali/inst-tpl/lib -lmstk -lmesh_factory -ljali_state

set(OTHER_LIBS 
 error_handling geometry mesh simple_mesh mstk_mesh
 boost_filesystem
 boost_graph
 boost_program_options
 boost_regex
 boost_system
 exodus
 exoIIv2for
 hdf5
 hdf5_hl
 hdf5_tools
 metis
 mstk
 netcdf
 UnitTest++
 z
 mesh_factory jali_state
)

set(OTHER_LIBS 
 mesh mstk_mesh
 boost_filesystem
 boost_graph
 boost_program_options
 boost_regex
 boost_system
 exodus
 exoIIv2for
 hdf5
 hdf5_hl
 hdf5_tools
 metis
 mstk
 netcdf
 UnitTest++
 z
 mesh_factory jali_state
)


#include_directories(${Boost_INCLUDE_DIRS})
#include_directories(${BoostCompute_INCLUDE_DIRS})
#message(STATUS "Unit Boost include directories: " ${Boost_INCLUDE_DIRS})
#message(STATUS "Unit Boost libs: " ${Boost_LIBRARIES})

set(CMAKE_CXX_FLAGS "-g -march=native --std=c++17 ${CMAKE_CXX_FLAGS}")

#add_executable(testNearestNeighbor testNearestNeighbor.cc)
#target_link_libraries(testNearestNeighbor ${OTHER_LIBS} ${Boost_LIBRARIES} )

#add_executable(testRegistry testRegistry.cc)
#target_link_libraries(testRegistry ${OTHER_LIBS} ${Boost_LIBRARIES} )

add_executable(testAdvectionUpdater testAdvectionUpdater.cc)
target_link_libraries(testAdvectionUpdater ${OTHER_LIBS} ${Boost_LIBRARIES} )
#target_link_libraries(testAdvectionUpdater ${OTHER_LIBS} ${Boost_LIBRARIES} )