#include "Duke.hpp"

using namespace coup;

void Duke::tax() {  
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (coins()>=10) {
        throw std::runtime_error("Player must coup!");
    }
    incrementCoins(3);
    getCurrGame()->nextTurn();
}

std::string Duke::role() {     return "Duke";}

void Duke::block(Player &blockedPlayer) {
    if (!blockedPlayer.didForeign_aid) {
        throw std::runtime_error("this player didn't foreign aid!");
    }
    blockedPlayer.incrementCoins(-2);
 }