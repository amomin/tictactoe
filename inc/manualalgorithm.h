#ifndef MANUALALGORITHM_H
#define MANUALALGORITHM_H

#include "player.h"
#include "console.h"
#include "algorithm.h"
#include <cstdlib>
#include <ctime>

class ManualAlgorithm : public Algorithm
{
    public:
        ManualAlgorithm(Player *q, Console *c);
        virtual int player();
        virtual int move(Board b);
    private:
        Player *p;
        Console *console;
};

#endif
