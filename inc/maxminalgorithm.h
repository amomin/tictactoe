#ifndef MAXMINALGORITHM_H
#define MAXMINALGORITHM_H

#include <string>
#include "player.h"
#include "algorithm.h"

struct MaxMinResult
{
    public:
        int index;
        int value;
};

class MaxMinAlgorithm : public Algorithm
{
    public:
        MaxMinAlgorithm(Player *q, Player *opp);
        virtual int player();
        virtual int move(Board b);
    private:
        Player *p;
        Player *opp;
        Board clone_board(Board b);
        MaxMinResult bestmove(Board b);
};

#endif
