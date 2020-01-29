cmake_minimum_required(VERSION 3.12)
project(pruebas C)

set(CMAKE_C_STANDARD 99)

add_executable(pruebas objects.h Juego.h Principal.c)
target_link_libraries(pruebas -lmingw32 -lallegro-5.0.10-monolith-md-debug)