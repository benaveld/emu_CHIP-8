cmake_minimum_required(VERSION 3.11...3.14)

#set the project name
project(chip-8 
	LANGUAGES CXX)

set(default_build_type "Debug")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
  src/main.cpp
  src/emulator.cpp
  src/io.cpp
  src/window.cpp
  )

find_package(SDL2 REQUIRED)

#add the executable
add_executable(chip-8 ${SOURCES})

target_link_libraries(chip-8 PRIVATE SDL2::SDL2)

#include all header files in dir include
target_include_directories(chip-8 PRIVATE include)
