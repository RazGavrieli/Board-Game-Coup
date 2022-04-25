#include "Player.hpp"
#include "Game.hpp"

#include <iostream>
namespace coup {
    class Ambassador : public Player {

        public:
            using Player::Player;
            //Ambassador(Game, std::string);
            void transfer(Player, Player); /*overridng*/
            //CAN BLOCK STEAL -- TODO --
    };

}