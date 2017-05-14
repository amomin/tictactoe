#ifndef MANUALALGORITHM_H
#define MANUALALGORITHM_H

#include "player.h"
#include "console.h"
#include "algorithm.h"
#include <cstdlib>
#include <ctime>

namespace tictactoe
{
    class ManualAlgorithm : public Algorithm
    {
        public:
            ManualAlgorithm(const Player& q, Console *c);
            virtual int player() const;
            virtual int move(const Board& b) const;
        private:
            const Player& p;
            Console *console;
    };
}

#endif
