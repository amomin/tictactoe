#include "randomalgorithm.h"

namespace tictactoe
{
    int RandomAlgorithm::player() const
    {
        return p->id();
    }

    RandomAlgorithm::RandomAlgorithm(Player *q)
    {
        std::srand(std::time(0));
        p = q;    
    }

    int RandomAlgorithm::move(const Board& b)
    {
        for (int i = 0; i < 1000; i++)
        {
            int x = 1 + std::rand() % 9;

            if (b.get(x) == 2) {
                return x;
            }
        }
        return -1;
    }
}
