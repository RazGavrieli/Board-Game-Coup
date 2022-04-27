#include "Player.hpp"
#include "Game.hpp"

#include <iostream>
namespace coup {
    class Contessa : public Player {
        public:
            using Player::Player;
            void block(Player&) override;
            std::string role() override;
    };

}