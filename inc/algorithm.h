#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include "board.h"

class Algorithm
{
    public:
        virtual int player() = 0;
        virtual int move(Board b) = 0;
};

#endif
