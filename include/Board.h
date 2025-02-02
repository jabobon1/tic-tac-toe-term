//
// Board Headers
//

#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board {
    std::vector<std::vector<int> > board;

    std::pair<int, int> getCellFromIndex(int i) const;

public:
    explicit Board(int size);

    ~Board() = default;

    void SetCell(int idx, int value);

    int GetCell(int idx) const;

    std::vector<std::vector<int> > GetBoard();
};


#endif //BOARD_H
