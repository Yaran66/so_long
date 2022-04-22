cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 99)

include_directories(./includes)

add_executable(so_long
        so_long.c
        so_long_utils.c
        parser.с
        so_long_utils.c
        gnl/get_next_line.c
        gnl/get_next_line_utils.c draw_map.c play.c)

SET(CMAKE_C_FLAGS  " ${CMAKE_C_FLAGS} -Wall -Wextra")

#target_link_libraries(_so_long_2
#        includes)