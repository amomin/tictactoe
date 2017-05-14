#include "manualalgorithm.h"

namespace tictactoe
{
    int ManualAlgorithm::player() const
    {
        return p->id();
    }

    ManualAlgorithm::ManualAlgorithm(Player *q, Console *c)
    {
        p = q;
        console = c;
    }

    int ManualAlgorithm::move(const Board& b)
    {
        console->read();
        return console->get_selection();
    }
}
