#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include "board.h"

namespace tictactoe
{
    class Algorithm
    {
        public:
            virtual int player() const = 0;
            virtual int move(const Board& b) = 0;
    };
}

#endif
