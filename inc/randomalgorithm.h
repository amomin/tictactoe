#ifndef RANDOMALGORITHM_H
#define RANDOMALGORITHM_H

#include <string>
#include "player.h"
#include "algorithm.h"

class RandomAlgorithm : public Algorithm
{
    public:
        RandomAlgorithm(Player *q);
        virtual int player();
        virtual int move(Board b);
    private:
        Player *p;
};

#endif
