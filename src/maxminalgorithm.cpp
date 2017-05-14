#include "maxminalgorithm.h"

namespace tictactoe
{
    MaxMinAlgorithm::MaxMinAlgorithm(const Player& q, const Player& qopp) :
        p(q),
        opp(qopp) {}

    int MaxMinAlgorithm::player() const
    {
        return p.id();
    }

    int MaxMinAlgorithm::move(const Board& b) const
    {
        MaxMinResult result = bestmove(b);
        return result.index;
    }

    MaxMinResult MaxMinAlgorithm::bestmove(Board b) const
    {
        //2 = win, 1 = draw, 0 = lose
        MaxMinResult result;
        result.value = -1;
        result.index = -1;

        for (int i = 1; i < 10; i++)
        {
            if (b.is_set(i)) continue;
            Board clone = clone_board(b);
            clone.set(i, p.id() - 1);

            // If win by playing here, return that.
            if (clone.has_won()) {
                result.index = i;
                result.value = 2;
                return result;
            }
            // If fill the board by playing here, return a draw.
            // (We know we haven't won, there's nowhere else to go,
            // and we can't lose since our opponent can't play.)
            if (clone.is_full()) {
                result.index = i;
                result.value = 1;
                return result;
            }

            // Run the same algorithm for our opponent, find their best move
            // and change our move if it is worse (for them) than their
            // best move against our current move.
            MaxMinAlgorithm a = MaxMinAlgorithm(opp, p);
            MaxMinResult oppresult = a.bestmove(clone);
            if (oppresult.value < 2 - result.value) {
                result.value = 2 - oppresult.value;
                result.index = i;
            }
        }
        return result;
    }

    Board MaxMinAlgorithm::clone_board(Board b) const
    {
        Board result = Board();
        for (int i = 1; i < 10; i++)
        {
            if (b.is_set(i))
            {
                result.set(i, b.get(i));
            }
        }
        return result;
    }
}
