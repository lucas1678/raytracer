cmake_minimum_required(VERSION 3.10)
project(RayTracer VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Find all source files in the src directory
file(GLOB SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cc
    ${PROJECT_SOURCE_DIR}/main.cc
)

# Create executable
add_executable(raytracer ${SOURCES})

# Add compiler warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(raytracer PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(raytracer PRIVATE /W4)
endif()

# Optional: Add debug symbols in Debug mode
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Optional: Enable optimizations in Release mode
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")