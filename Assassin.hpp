#include "Player.hpp"
#include "Game.hpp"

#include <iostream>

namespace coup {
    class Assassin : public Player {

        public:
            using Player::Player;
            //Assassin(Game, std::string);
            void coup(Player); /*overridng*/
    };

}