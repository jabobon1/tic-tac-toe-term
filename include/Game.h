//
// Game headers
//

#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Renderer.h"

#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

enum Direction { UP, DOWN, LEFT, RIGHT };

enum CellState {
    EMPTY = 0,
    PLAYER_1 = 1,
    PLAYER_2 = 2,
};

class Game {
    Board board;
    Renderer renderer;
    bool player1Turn = true;
    int boardCellSelector = 0;
    int boardSize;

public:
    explicit Game(int boardSize);

    ~Game() = default;

    std::function<bool(ftxui::Event)> EventHandler();

    void MoveCursor(Direction direction);

    void SelectThis();
    void Run();
};


#endif //GAME_H
