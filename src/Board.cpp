//
// Created by jabobon on 1/26/25.
//

#include "../include/Board.h"

Board::Board(int size) {
    board.resize(size);
    for (int i = 0; i < size; i++) {
        board[i].resize(size);
    }
};

std::pair<int, int> Board::getCellFromIndex(int i) const {
    return std::make_pair(i / board.size(), i % board.size());
};


void Board::SetCell(int idx, int value) {
    const auto cell = getCellFromIndex(idx);
    board[cell.first][cell.second] = value;
};

int Board::GetCell(int idx) const {
    const auto cell = getCellFromIndex(idx);
    return board[cell.first][cell.second];
}

std::vector<std::vector<int> > Board::GetBoard() {
    return board;
};
