#include "randomalgorithm.h"

namespace tictactoe
{
    int RandomAlgorithm::player() const
    {
        return p.id();
    }

    RandomAlgorithm::RandomAlgorithm(const Player& q) : p(q)
    {
        std::srand(std::time(0));
    }

    int RandomAlgorithm::move(const Board& b) const
    {
        for (int i = 0; i < 1000; i++)
        {
            int x = 1 + std::rand() % 9;

            if (!b.is_set(x)) {
                return x;
            }
        }
        return -1;
    }
}
