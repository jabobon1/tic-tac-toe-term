cmake_minimum_required(VERSION 3.28)
project(tic_tac_toe_term)

set(CMAKE_CXX_STANDARD 14)

# Find FTXUI package
find_package(ftxui REQUIRED)

add_executable(tic_tac_toe_term
        cmd/main.cpp
        include/Board.h
        include/Game.h
        include/Renderer.h
        src/Board.cpp
        src/Game.cpp
        src/Game.cpp
        src/Game.cpp
        src/utils.cpp
        src/Renderer.cpp
        include/utils.h)

# Link FTXUI libraries
target_link_libraries(tic_tac_toe_term
        PRIVATE
        ftxui::screen
        ftxui::dom
        ftxui::component
)