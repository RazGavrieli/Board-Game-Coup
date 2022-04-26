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