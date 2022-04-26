#ifndef Game_H
#define Game_H

#include <iostream>
#include <vector>

#include "Player.hpp"

namespace coup {
    class Game {
        std::vector<Player> onlinePlayers;
        Player playerTurn; 
        bool gameRunning;
        
        public:
            Game();
            void addPlayer(Player);
            void removePlayer(Player);
            std::vector<std::string> players(); 
            std::string turn(); 
            std::string winner();
    };

}
#endif