#include <cstdlib>
#include <iostream>
#include <ctime>
#include "randomalgorithm.h"

int RandomAlgorithm::player()
{
    return p->id();
}

RandomAlgorithm::RandomAlgorithm(Player *q)
{
    std::srand(std::time(0));
    p = q;    
}

int RandomAlgorithm::move(Board b)
{
    for (int i = 0; i < 1000; i++)
    {
        int x = 1 + std::rand() % 9;

        std::cout << "Selected position" << x;

        if (b.get(x) == 2) {
            std::cout << "returning" << x;
            return x;
        }
    }
    return -1;
}
