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
            const int player_id_;
    };
}

#endif
