#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    public:
        Player(int id);
        int id();
    private:
        int player_id;
};

#endif