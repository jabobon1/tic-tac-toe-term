cmake_minimum_required(VERSION 3.29)
project(tic_tac_toe_term)

set(CMAKE_CXX_STANDARD 14)

add_executable(tic_tac_toe_term
    cmd/main.cpp
        include/Board.h
        include/Game.h
        include/Renderer.h
        src/Board.cpp
        src/Game.cpp
        src/Game.cpp
        src/Game.cpp)
