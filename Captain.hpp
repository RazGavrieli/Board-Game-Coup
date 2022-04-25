#include "Player.hpp"
#include "Game.hpp"

#include <iostream>

namespace coup {
    class Captain : public Player{

        public:
            using Player::Player;
            //Captain(Game, std::string);
            void steal(Player); /*overridng*/
            //CAN BLOCK STEAL -- TODO --
    };

}