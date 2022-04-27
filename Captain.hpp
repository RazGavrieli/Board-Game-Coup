#include "Player.hpp"
#include "Game.hpp"

#include <iostream>

namespace coup {
    class Captain : public Player{

        public:
        bool didSteal = false;
        Player* stolenPlayer = nullptr;
            using Player::Player;
            void steal(Player&) override; 
            void block(Player&) override;
            void resetPlayer () override;
            std::string role() override;
    };

}