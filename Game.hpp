#ifndef Game_H
#define Game_H

#include <iostream>
#include <vector>

#include "Player.hpp"

namespace coup {
    class Game {
        std::vector<Player*> onlinePlayers;
        Player *playerTurn; 
        bool gameRunning;
        
        public:
            Game();
            //~Game();
            void addPlayer(Player*);
            void removePlayer(Player);
            std::vector<std::string> players(); 
            std::string turn(); 
            Player* turnPlayer();
            void nextTurn();
            std::string winner();
    };

}
#endif