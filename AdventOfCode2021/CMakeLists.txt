# CMakeList.txt : CMake project for AdventOfCode2021, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

project ("AdventOfCode2021")

set(CMAKE_CXX_STANDARD 20)

# Add source to this project's executable.

foreach(DAY RANGE 1 3)
	if(DAY LESS 10)
		string(PREPEND DAY "0")
	endif()
	configure_file("day${DAY}.txt" "day${DAY}.txt" COPYONLY)
	add_executable (day${DAY} "day${DAY}.cpp" "AdventOfCode2021.h")
endforeach()

# TODO: Add tests and install targets if needed.
