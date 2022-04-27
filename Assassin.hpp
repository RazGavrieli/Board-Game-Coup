#include "Player.hpp"
#include "Game.hpp"

#include <iostream>

namespace coup {
    class Assassin : public Player {

        public:
        bool didCoup = false;
        Player* coupedPlayer;
            using Player::Player;
            void coup(Player&) override; 
            void resetPlayer () override;
            std::string role() override;
    };

}