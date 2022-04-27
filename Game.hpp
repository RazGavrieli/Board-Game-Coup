#ifndef Game_H
#define Game_H

#include <iostream>
#include <vector>

#include "Player.hpp"

namespace coup {
    class Game {
        std::vector<Player*> onlinePlayers;
        Player *playerTurn; 
        bool gameStarted;
        bool gameFinished;
        
        public:
            Game();
            //~Game();
            void revivePlayer(Player*);
            void addPlayer(Player*);
            void removePlayer(Player*);
            std::vector<std::string> players(); 
            std::string turn(); 
            Player* turnPlayer();
            void nextTurn();
            bool checkForWin();
            std::string winner();
    };

}
#endif