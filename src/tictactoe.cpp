#include "tictactoe.h"

void toggle_player(tictactoe::Player *p1,
                   tictactoe::Player *p2,
                   tictactoe::Player **curr)
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
    tictactoe::Board b;
    tictactoe::Player p1(1), p2(2), *current;
    tictactoe::Console console;
    tictactoe::Algorithm *a1, *a2;

    console.print("Set player 1 as computer?");
    if (console.read_yn())
    {
        console.print("Optimal algorithm?");
        if (console.read_yn())
        {
            a1 = new tictactoe::MaxMinAlgorithm(p1, p2);
        }
        else
        {
            a1 = new tictactoe::RandomAlgorithm(p1);
        }
    }
    else
    {
        a1 = new tictactoe::ManualAlgorithm(p1, &console);
    }
    console.print("Set player 2 as computer?");
    if (console.read_yn())
    {
        console.print("Optimal algorithm?");
        if (console.read_yn())
        {
            a2 = new tictactoe::MaxMinAlgorithm(p2, p1);
        }
        else
        {
            a2 = new tictactoe::RandomAlgorithm(p2);
        }
    }
    else
    {
        a2 = new tictactoe::ManualAlgorithm(p2, &console);
    }

    current = &p1;
    bool user_quit = false;

    while (!user_quit)
    {
        console.print(b, *current);

        int selection;

        if (current->id() == a2->player())
        {
            selection = a2->move(b);
            console.print(std::to_string(selection));
            console.wait();
        }
        else if (current->id() == a1->player())
        {
            selection = a1->move(b);
            console.print(std::to_string(selection));
            console.wait();
        }

        if (console.has_quit()) break;
        if (selection == -1) continue;

        try
        {
            b.set(selection, current->id() - 1);
        }
        catch (std::invalid_argument const &ex)
        {
            console.print(ex.what());
            console.wait();
            continue;
        }

        if (b.has_won())
        {
            console.print(b, *current);
            console.print("Player " + std::to_string(current->id()) + " has won.");
            break;
        }
        if (b.is_full())
        {
            console.print(b, *current);
            console.print("Game ended in a draw.");
            break;
        }
        toggle_player(&p1, &p2, &current);
    }
    return 0;
}
