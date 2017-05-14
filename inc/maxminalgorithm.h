#ifndef MAXMINALGORITHM_H
#define MAXMINALGORITHM_H

#include <string>
#include "player.h"
#include "algorithm.h"

namespace tictactoe
{
    struct MaxMinResult
    {
        public:
            int index;
            int value;
    };

    class MaxMinAlgorithm : public Algorithm
    {
        public:
            MaxMinAlgorithm(const Player& q, const Player& opp);
            virtual int player() const;
            virtual int move(const Board& b) const;
        private:
            const Player p;
            const Player opp;
            Board clone_board(Board b) const;
            MaxMinResult bestmove(Board b) const;
    };
}

#endif
