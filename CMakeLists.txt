cmake_minimum_required(VERSION 3.10)
project(RayTracer)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(raytracer ${SOURCES})
