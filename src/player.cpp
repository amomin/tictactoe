#include "player.h"

namespace tictactoe
{
    Player::Player(int id)
    {
        player_id_ = id;;
    }

    int Player::id() const
    {
        return player_id_;
    }
}
