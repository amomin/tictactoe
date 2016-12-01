#include "manualalgorithm.h"

int ManualAlgorithm::player()
{
    return p->id();
}

ManualAlgorithm::ManualAlgorithm(Player *q, Console *c)
{
    p = q;
    console = c;
}

int ManualAlgorithm::move(Board b)
{
    console->read();
    return console->get_selection();
}
