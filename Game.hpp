#ifndef Game_H
#define Game_H

#include <vector>

#include "Player.hpp"

namespace coup
{
    class Game
    {   
        /* --- private fields --- */
        std::vector<Player *> onlinePlayers;
        Player *playerTurn;
        bool gameStarted;
        bool gameFinished;

    public:
            /* --- constructors --- */
        Game();

            /* --- getters --- */
        std::vector<std::string> players() const;
        std::string turn() const;
        Player *turnPlayer() const;

            /* --- setters --- */

            /* --- functions --- */
        void revivePlayer(Player *);
        void addPlayer(Player *);
        void removePlayer(Player *);
        bool checkForWin();
        std::string winner();
        void nextTurn();
    };

}
#endif