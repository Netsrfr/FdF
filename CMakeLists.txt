cmake_minimum_required(VERSION 3.6)
project(fdf)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES generate_map.c validation.c fdf.h draw.c window.c fdf.c)
add_executable(fdf ${SOURCE_FILES})