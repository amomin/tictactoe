#include <iostream>
#include <string>
#include "console.h"


Console::Console()
{
    selection = -1;
    user_quit = false;
}

void print_head()
{
    std::cout << "Tic Tac Toe" << std::endl;
    std::cout << "Type 'q' to quit." << std::endl;
}

void unix_clear()
{
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

void Console::read()
{
    std::string error_message = "Invalid row: please enter number 1-9.";

    std::string line;
    std::getline(std::cin, line);
    if (line == "q")
    {
        user_quit = true;
        selection = -1;
        return;
    }
    int x;
    try
    {
        x = std::stoi(line);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << error_message << std::endl;
        selection = -1;
        return;
    }
    try
    {
        x = std::stoi(line);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << error_message << std::endl;
        selection = -1;
        return;
    }
    selection = x;
}

void Console::wait()
{
    std::cout << "Press any key to continue" << std::endl;
    std::string l;
    std::getline(std::cin, l);
}

bool Console::has_quit()
{
    return user_quit;
}

int Console::get_selection()
{
    return selection;
}

void Console::print(Board b, Player *p)
{
    unix_clear();
    print_head();
    std::cout << board_to_string(b) << std::endl;
    std::cout << "Player " + std::to_string(p->id()) + " turn." << std::endl;
}

void Console::print(std::string str)
{
    std::cout << str << std::endl;
}

std::string Console::board_to_string(Board b)
{
    std::string output = "";
    output = output + " -------------\n";
    output = output + " | " + x_or_o(b, 1)
                    + " | " + x_or_o(b, 2)
                    + " | " + x_or_o(b, 3)
                    + " | \n";
    output = output + " -------------\n";
    output = output + " | " + x_or_o(b, 4)
                    + " | " + x_or_o(b, 5)
                    + " | " + x_or_o(b, 6)
                    + " | \n";
    output = output + " -------------\n";
    output = output + " | " + x_or_o(b, 7)
                    + " | " + x_or_o(b, 8)
                    + " | " + x_or_o(b, 9)
                    + " | \n";
    output = output + " -------------\n";
    return output;
}

std::string Console::x_or_o(Board b, int idx)
{
    if (b.get(idx) == 0)
    {
        return "O";
    }
    if (b.get(idx) == 1)
    {
        return "X";
    }
    return std::to_string(idx);
}