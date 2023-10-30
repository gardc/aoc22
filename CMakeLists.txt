cmake_minimum_required(VERSION 3.26)
project(aoc_cpp)

set(CMAKE_CXX_STANDARD 20)

# Add executables
add_executable(day1 "day1/main.cpp"
        "day1/day1.h"
        "day1/day1.cpp"
)
# Copy required files to build directory, such as text files
add_custom_command(TARGET day1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/day1/cals.txt
        $<TARGET_FILE_DIR:day1>
)

# day 2
add_executable(day2 day2/day2.cpp
		day2/day2.h
		day2/rock-paper-scissor.h
		day2/rock-paper-scissor.cpp
)
add_custom_command(TARGET day2 POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_SOURCE_DIR}/day2/input.txt
		$<TARGET_FILE_DIR:day2>
)
add_custom_command(TARGET day2 POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_SOURCE_DIR}/day2/testinput.txt
		$<TARGET_FILE_DIR:day2>
)

# day 3
add_executable(day3-part1
		day3/part1.cpp
)
add_custom_command(TARGET day3-part1 POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_SOURCE_DIR}/day3/test-input.txt
		$<TARGET_FILE_DIR:day3-part1>
)
add_custom_command(TARGET day3-part1 POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_SOURCE_DIR}/day3/input.txt
		$<TARGET_FILE_DIR:day3-part1>
)
add_executable(day3-part2
		day3/part2.cpp
)
add_custom_command(TARGET day3-part2 POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_SOURCE_DIR}/day3/test-input.txt
		$<TARGET_FILE_DIR:day3-part2>
)
add_custom_command(TARGET day3-part2 POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_SOURCE_DIR}/day3/input.txt
		$<TARGET_FILE_DIR:day3-part2>
)

if(MSVC)
  add_compile_options(/W3 /WX)
else()
  add_compile_options(-Wall -Wpedantic -Werror)
endif()
