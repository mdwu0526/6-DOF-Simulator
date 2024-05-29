cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(mySim VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 REQUIRED)

include_directories(include)

set(SOURCES
    src/main.cxx
    src/MassSpringDamper.cxx
    src/RK4.cxx
    src/System.cxx
)

add_executable(mySim ${SOURCES})

target_include_directories(mySim PRIVATE ${EIGEN3_INCLUDE_DIR})

