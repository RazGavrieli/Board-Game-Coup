#include "Player.hpp"
#include "Game.hpp"

#include <iostream>
namespace coup {
    class Ambassador : public Player {
        Player* payer = nullptr;
        Player* receiver = nullptr;
        bool didTransfer = false;

        public:
            using Player::Player;
            void transfer (Player&, Player&) override;
            void resetPlayer () override;
            std::string role() override;
            void block(Player&) override;
            
    };

}