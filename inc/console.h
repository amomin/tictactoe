#ifndef CONSOLE_H
#define CONSOLE_H

#include "board.h"
#include "player.h"
#include <string>

class Console
{
    public:
        Console();
        void print(Board b, Player *p);
        void read();
        bool read_yn();
        void wait();
        int get_selection();
        bool has_quit();
        void print(std::string str);
    private:
        bool user_quit;
        int selection;
        std::string board_to_string(Board b);
        std::string x_or_o(Board b, int x);
};

#endif
