#include "Assassin.hpp"
using namespace coup;
#include <iostream>

void Assassin::coup(Player &coup) {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (this->coins()<3) {
        throw std::runtime_error("Not enough coins");
    }
    if (!isInGame(coup)) {
        throw std::runtime_error("Player not in game!");
    }
    getCurrGame()->removePlayer(&coup);
    didCoup = true;
    coupedPlayer = &coup;
    incrementCoins(-3);
    getCurrGame()->nextTurn();
}
std::string Assassin::role() {     return "Assassin";}

void Assassin::resetPlayer () {
    didCoup = false;
    coupedPlayer = nullptr;
}