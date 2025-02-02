//
// Created by jabobon on 1/27/25.
//

#ifndef UTILS_H
#define UTILS_H

#pragma once

#include <string>
#include <ftxui/component/component.hpp>
#include "Board.h"

std::string getFigure(int val);

ftxui::Component FromTableToComponent(Board &board, int &cursor, bool &player1Turn);

ftxui::Color getCursorColor(int state);


#endif //UTILS_H
