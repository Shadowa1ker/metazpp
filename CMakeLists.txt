# CMakeList.txt : CMake project for metazpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.13)

project (metazpp)

# Add source to this project's executable.
add_executable (metazpp App/src/main.cpp)

add_subdirectory(Framework)

# TODO: Add tests and install targets if needed.
