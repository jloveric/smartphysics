cmake_minimum_required(VERSION 3.0.0)
project(smartphysics)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

#set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
find_package (OpenMP REQUIRED)


## All this just to get the variables right.  Ouch
execute_process(COMMAND which mpicc OUTPUT_VARIABLE CMAKE_C_COMPILER)
execute_process(COMMAND which mpif90 OUTPUT_VARIABLE CMAKE_Fortran_COMPILER)
execute_process(COMMAND which mpiCC OUTPUT_VARIABLE CMAKE_CXX_COMPILER)

string(STRIP ${CMAKE_C_COMPILER} CMAKE_C_COMPILER)
string(STRIP ${CMAKE_CXX_COMPILER} CMAKE_CXX_COMPILER)
string(STRIP ${CMAKE_Fortran_COMPILER} CMAKE_Fortran_COMPILER)

message("compiler ${CMAKE_C_COMPILER}")
message("compiler ${CMAKE_CXX_COMPILER}")
message("compiler ${CMAKE_Fortran_COMPILER}")

set(OTHER_LIBS 
 smart error_handling geometry mesh simple_mesh mstk_mesh
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


if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

link_directories(jali/inst-jali/lib)
include_directories(src jali/inst-jali/include)
add_subdirectory(src)
add_subdirectory(test)
add_executable(smartphysics src/main.cc)
target_link_libraries(smartphysics error_handling geometry jali_state mesh_factory mesh mstk_mesh)

enable_testing()
add_test(testNearestNeighbor test/testNearestNeighbor)
add_test(testRegistry test/testRegistry)
add_test(testAdvectionUpdater test/testAdvectionUpdater)
