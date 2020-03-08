cmake_minimum_required (VERSION 3.15)
project(variational_autoencoder)

set(CMAKE_DISABLE_SOURCE_CHANGES OFF)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_CXX_STANDARD 17)
set(USE_OPENCV ON)

OPTION (USE_OpenMP "Use OpenMP" ON)
IF(USE_OpenMP)
  FIND_PACKAGE(OpenMP)
  IF(OPENMP_FOUND)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  ENDIF()
ENDIF()

set(OpenCV_DIR ~/gits/opencv/build)
add_subdirectory(3rd-party/pytorch)
add_subdirectory(3rd-party/docopt.cpp)
add_subdirectory(3rd-party/mnist/example)
add_subdirectory(src)

