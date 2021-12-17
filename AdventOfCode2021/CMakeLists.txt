cmake_minimum_required (VERSION 3.18.2)

project ("AdventOfCode2021")

set(CMAKE_CXX_STANDARD 20)

foreach(DAY RANGE 1 6)
	if(DAY LESS 10)
		string(PREPEND DAY "0")
	endif()
	configure_file("day${DAY}.txt" "day${DAY}.txt" COPYONLY)
	add_executable(day${DAY} "day${DAY}.cpp")
	target_precompile_headers(day${DAY} PUBLIC "AdventOfCode2021.h")
endforeach()
