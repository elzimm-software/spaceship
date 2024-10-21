cmake_minimum_required(VERSION 3.26)
project(spaceship)

set(CMAKE_CXX_STANDARD 20)

add_executable(spaceship main.cpp
        vector_sprite.hpp
        point.hpp
        util.hpp
        controllable_body.hpp
        vector2.hpp)

target_compile_options(spaceship PUBLIC -w)
target_link_options(spaceship PUBLIC -lSDL2)
