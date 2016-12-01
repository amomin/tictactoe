#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

class Board
{
    public:
        Board();
        int set(int c, int v);
        bool is_set(int c);
        int get(int x);
        bool in_bounds(int c);
        bool has_won();
        bool is_full();
    private:
        int board[9];
        void check_error(int x);
};
#endif
