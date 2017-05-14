#ifndef PLAYER_H
#define PLAYER_H

#include <string>

namespace tictactoe
{
    class Player
    {
        public:
            Player(int id);
            int id() const;
        private:
            int player_id_;
    };
}

#endif
