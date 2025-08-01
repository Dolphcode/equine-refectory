cmake_minimum_required(VERSION 3.15)
project(EquineRefectory VERSION	0.1
	DESCRIPTION "Optimized 3D tower defense game"
	LANGUAGES C CXX)

# GLFW package
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  find_package(glfw3 REQUIRED)
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  add_subdirectory("extern/glfw")
endif()

# OpenGL
find_package(OpenGL REQUIRED)

# Build GLAD at config time
set(GLAD_SOURCE_DIR "${PROJECT_SOURCE_DIR}/extern/glad")
add_subdirectory("${GLAD_SOURCE_DIR}/cmake" glad_cmake)
glad_add_library(glad_gl_core_46 REPRODUCIBLE API gl:core=4.6)

# fmt
add_subdirectory("extern/fmt") 

# Add all subdirectories or sub libraries from lower level CMakeLists.txt files
add_subdirectory("${PROJECT_SOURCE_DIR}/src")

add_executable(equine_refectory src/main.cpp)

target_include_directories(equine_refectory PUBLIC include)

target_link_libraries(equine_refectory
	PUBLIC
		glad_gl_core_46
		glfw
		fmt::fmt
		rendering
	)

