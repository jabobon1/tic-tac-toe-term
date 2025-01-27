//
// Created by jabobon on 1/26/25.
//

#include "../include/Game.h"


Game::Game(const int boardSize): board(Board(boardSize)), boardSize(boardSize) {
}


std::function<bool(ftxui::Event)> Game::EventHandler() {
    return [this](const ftxui::Event &event) {
        if (event == ftxui::Event::ArrowLeft || event.input() == "a") {
            this->MoveCursor(LEFT);
        } else if (event == ftxui::Event::ArrowRight || event.input() == "d") {
            this->MoveCursor(RIGHT);
        } else if (event == ftxui::Event::ArrowUp || event.input() == "w") {
            this->MoveCursor(UP);
        } else if (event == ftxui::Event::ArrowDown || event.input() == "s") {
            this->MoveCursor(DOWN);
        } else if (event == ftxui::Event::Return || event.input() == "f") {
            this->SelectThis();
        } else {
            return false;
        }
        return true;
    };
};


void Game::MoveCursor(Direction direction) {
    switch (direction) {
        case LEFT:
            if (boardCellSelector % boardSize == 0) {
                boardCellSelector += boardSize;
            } else {
                boardCellSelector--;
            }
            break;
        case RIGHT:
            if ((boardCellSelector + 1) % boardSize == 0) {
                boardCellSelector -= boardSize - 1;
            } else {
                boardCellSelector++;
            }
            break;
        case UP:
            if (boardCellSelector / boardSize == 0) {
                const int lastRow = boardSize * boardSize - boardSize;
                boardCellSelector = lastRow + boardCellSelector % boardSize;
            } else {
                boardCellSelector -= 3;
            }
            break;
        case DOWN:
            if (boardCellSelector / boardSize == boardSize - 1) {
                boardCellSelector = boardCellSelector % boardSize;
            } else {
                boardCellSelector += boardSize;
            }
            break;
        default:
            break;
    }
}

void Game::SelectThis() {
    auto cell = board.GetCell(boardCellSelector);
    if (cell != EMPTY) {
        return;
    }
    if (player1Turn) {
        board.SetCell(boardCellSelector, PLAYER_2);
    } else {
        board.SetCell(boardCellSelector, PLAYER_1);
    }
    player1Turn = !player1Turn;
};


void Game::Run() {
    auto component = renderer.ComponentFromBoard(board.GetBoard());
    renderer.Render(component, EventHandler());
}
