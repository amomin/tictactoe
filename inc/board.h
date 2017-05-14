#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

namespace tictactoe
{
    class Board
    {
        public:
            Board();
            int set(int c, int v);
            bool is_set(int c) const;
            int get(int x) const;
            bool in_bounds(int c) const;
            bool has_won() const;
            bool is_full() const;
        private:
            int board[9];
            void check_error(int x) const;
    };
}
#endif
