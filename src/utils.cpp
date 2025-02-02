//
// Useful functions
//

#include <map>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>

#include "../include/utils.h"
#include "../include/Board.h"
#include "../include/Game.h"


const std::map<int, std::string> figureMap = {
    {0, " "},
    {1, "X"},
    {2, "O"},
};

std::string getFigure(int val) {
    return figureMap.find(val)->second;
};


ftxui::Color getCursorColor(int state, int idx, int cursor) {
    ftxui::Color curColor;
    if (cursor == idx) {
        curColor = ftxui::Color::Green;
    } else if (state == PLAYER_1) {
        curColor = ftxui::Color::Red;
    } else if (state == PLAYER_2) {
        curColor = ftxui::Color::Blue;
    } else {
        curColor = ftxui::Color::Black;
    }
    return curColor;
};

ftxui::Component FromTableToComponent(Board &board, int &cursor, bool &player1Turn) {
    auto component = ftxui::Renderer([&board,&cursor,&player1Turn] {
        const int rowSize = static_cast<int>(board.GetBoard().size());
        ftxui::Elements children;
        ftxui::Elements row;
        for (int i = 0; i < rowSize * rowSize; i++) {
            auto cell = board.GetCell(i);
            ftxui::Color curColor = getCursorColor(cell, i, cursor);


            row.push_back(ftxui::text(getFigure(cell)) | ftxui::bold | ftxui::center |
                          ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 10) | ftxui::border |
                          ftxui::color(curColor));

            if ((i + 1) % rowSize == 0) {
                children.push_back(ftxui::hbox(std::move(row)));
                children.push_back(ftxui::separator());
            }
        }

        return window(ftxui::text(" Player " + std::string(player1Turn ? "1" : "2")), vbox(std::move(children)));
    });
    return component;
};
