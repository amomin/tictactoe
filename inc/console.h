#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include "board.h"
#include "player.h"

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
        static std::string board_to_string(Board b);
        static std::string x_or_o(Board b, int x);
};

#endif
