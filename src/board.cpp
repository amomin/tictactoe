#include "board.h"

namespace tictactoe
{
    Board::Board()
    {
        for(int i = 0; i < 9; i++)
        {
            board[i] = 2;
        }
    }

    bool Board::is_set(int c)
    {
       return board[c-1] != 2; 
    }

    int Board::set(int c, int v)
    {
        check_error(c);
        if (is_set(c))
        {
            throw std::invalid_argument("Aleady taken, choose another square..");
        }
        board[c-1] = v;
        return 0;
    }

    int Board::get(int c)
    {
        check_error(c);
        return board[c-1];
    }

    bool Board::in_bounds(int c)
    {
        return c > 0 && c < 10;
    }

    bool Board::has_won()
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[3*i] != 2 &&
                board[3*i] == board[3*i+1] &&
                board[3*i] == board[3*i+2])
            {
                return true;
            }
            if (board[i] != 2 &&
                board[i] == board[i+3] &&
                board[i] == board[i+6])
            {
                return true;
            }
        }
        if (board[0] != 2 &&
            board[0] == board[4] &&
            board[0] == board[8])
        {
            return true;
        }
        if (board[2] != 2 &&
            board[2] == board[4] &&
            board[2] == board[6])
        {
            return true;
        }
        return false;
    }

    bool Board::is_full()
    {
        for (int i : board)
        {
            if (i == 2) return false;
        }
        return true;
    }

    void Board::check_error(int c)
    {
        if (!in_bounds(c))
        {
            throw std::invalid_argument("Please enter a number 1-9...");
        }
    }
}
