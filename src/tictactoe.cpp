#include <stdexcept>
#include "tictactoe.h"
#include "board.h"
#include "player.h"
#include "console.h"

void toggle_player(Player *p1, Player *p2, Player **curr)
{
    if ((*curr)->id() == p1->id())
    {
        *curr = p2;
    }
    else
    {
        *curr = p1;
    }
}

int main()
{
    Board b;
    Player p1(1), p2(2), *current;
    Console console;

    current = &p1;

    bool user_quit = false;

    while (!user_quit)
    {
        console.print(b, current);
        console.read();

        if (console.has_quit()) break;
        if (console.get_selection() == -1) continue;

        try
        {
            b.set(console.get_selection(), current->id() - 1);
        }
        catch (std::invalid_argument const &ex)
        {
            console.print(ex.what());
            console.wait();
            continue;
        }

        if (b.has_won())
        {
            console.print(b, current);
            console.print("Player " + std::to_string(current->id()) + " has won.");
            break;
        }
        if (b.is_full())
        {
            console.print(b, current);
            console.print("Game ended in a draw.");
            break;
        }
        toggle_player(&p1, &p2, &current);
    }
    return 0;
}
