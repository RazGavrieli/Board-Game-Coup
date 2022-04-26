#include "Captain.hpp"
using namespace coup;

void Captain::steal(Player stealFrom) {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (coins()>=10) {
        throw std::runtime_error("Player must coup!");
    }
    // IMPLEMENT STEAL FUNCTION -- TODO --
    getCurrGame()->nextTurn();
}