#include "Player.hpp"
#include "Game.hpp"

#include <iostream>

namespace coup {
    class Duke : public Player{
        
        public:
            using Player::Player;
            //Duke(Game, std::string);
            void tax() override; 
            void block(Player&) override;
            // CAN ALSO BLOCK FOREGIN_AID, 
            //BLOCKED PLAYER PAYS 2 COINS TO BANK -- TODO --
            std::string role() override;
            

    };

}