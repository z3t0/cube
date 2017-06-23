cmake_minimum_required(VERSION 2.6)
project(cube)

# compilation databases
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

# OpenGL
find_package(OpenGL REQUIRED)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw-3.2.1/)

# kazmath
set(KAZMATH_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(KAZMATH_BUILD_JNI_WRAPPER OFF CACHE BOOL "" FORCE)
set(KAZMATH_BUILD_GL_UTILS OFF CACHE BOOL "" FORCE)
set(KAZMATH_BUILD_LUA_WRAPPER OFF CACHE BOOL "" FORCE)
include_directories(external/kazmath/)

# glad
add_subdirectory(external/glad/)
include_directories(external/glad/include)

SET(ALL_LIBRARIES
  glfw
  glad
)

add_executable(cube src/main.c)
target_link_libraries(cube ${ALL_LIBRARIES})
