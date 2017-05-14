#ifndef RANDOMALGORITHM_H
#define RANDOMALGORITHM_H

#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "algorithm.h"

namespace tictactoe
{
    class RandomAlgorithm : public Algorithm
    {
        public:
            RandomAlgorithm(Player *q);
            virtual int player() const;
            virtual int move(const Board& b);
        private:
            Player *p;
    };
}

#endif
