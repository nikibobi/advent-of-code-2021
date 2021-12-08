# CMakeList.txt : CMake project for AdventOfCode2021, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("AdventOfCode2021")

# Add source to this project's executable.
configure_file("day01.txt" "day01.txt" COPYONLY)
add_executable (day01 "day01.cpp" "AdventOfCode2021.h")

# TODO: Add tests and install targets if needed.
