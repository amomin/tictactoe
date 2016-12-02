#include "player.h"

namespace tictactoe
{
    Player::Player(int id)
    {
        player_id = id;;
    }

    int Player::id()
    {
        return player_id;
    }
}
