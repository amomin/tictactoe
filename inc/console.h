#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include "board.h"
#include "player.h"

namespace tictactoe
{
    class Console
    {
        public:
            Console();
            void print(const Board& b, const Player& p) const;
            void read();
            bool read_yn();
            void wait() const;
            int get_selection() const;
            bool has_quit() const;
            void print(const std::string& str) const;
        private:
            bool user_quit;
            int selection;
            static std::string board_to_string(const Board& b);
            static std::string x_or_o(const Board& b, int x);
    };
}

#endif
