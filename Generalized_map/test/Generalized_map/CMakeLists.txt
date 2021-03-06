#  cd debug; cmake .. -DCMAKE_BUILD_TYPE=Debug
#  cd release; cmake .. -DCMAKE_BUILD_TYPE=Release

project( Generalized_map_test )

CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)

if ( COMMAND cmake_policy )
  cmake_policy( SET CMP0003 NEW )
endif()

####################################################################################
OPTION(BUILD_TESTS "Build tests." ON)

if (BUILD_TESTS)
  ENABLE_TESTING()
  INCLUDE(CTest)

  if (CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -W -Wshadow -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual -Wwrite-strings -fprofile-arcs -ftest-coverage -frounding-math")
  endif (CMAKE_COMPILER_IS_GNUCXX)
  if (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -Wall -W -fprofile-arcs -ftest-coverage -frounding-math")
  endif (CMAKE_COMPILER_IS_GNUCC)
endif (BUILD_TESTS)
####################################################################################

find_package(CGAL QUIET COMPONENTS Core )

if ( NOT CGAL_FOUND )
    message(FATAL_ERROR "This program requires the CGAL library, and will not be compiled.")
endif ( NOT CGAL_FOUND )

include( ${CGAL_USE_FILE} )

# Try to use gcov but does not work... TODO
#set(CMAKE_CXX_FLAGS "-g -frounding-math")
#set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS})
#add_definitions(-fprofile-arcs -ftest-coverage)

#include( CGAL_CreateSingleSourceCGALProgram )
include_directories(BEFORE  ../../include)
add_executable(Generalized_map_test
  GMap_test_insertions.h
  Generalized_map_2_test.h
  Generalized_map_3_test.h
  Generalized_map_4_test.h
  Generalized_map_test.cpp)
#create_single_source_cgal_program( "Generalized_map_test.cpp" )
target_link_libraries(Generalized_map_test ${CGAL_LIBRARIES}
                                             ${CGAL_3RD_PARTY_LIBRARIES} )

if (BUILD_TESTS)
  ADD_TEST(Generalized_map_test "./Generalized_map_test")
endif (BUILD_TESTS)
