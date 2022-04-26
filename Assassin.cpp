#include "Assassin.hpp"
using namespace coup;
#include <iostream>

void Assassin::coup(Player coup) {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (this->coins()<3) {
        throw std::runtime_error("Not enough coins");
    }
    getCurrGame()->removePlayer(coup);
    getCurrGame()->nextTurn();
}