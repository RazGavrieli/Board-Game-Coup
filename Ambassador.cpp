#include "Ambassador.hpp"
using namespace coup;

void Ambassador::transfer(Player payer, Player receiver) {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (coins()>=10) {
        throw std::runtime_error("Player must coup!");
    }
    //IMPLEMENT TRANFER -- TODO --
    getCurrGame()->nextTurn();
}

