#include "Captain.hpp"
using namespace coup;

void Captain::steal(Player &stealFrom) {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (coins()>=10) {
        throw std::runtime_error("Player must coup!");
    }
    if (stealFrom.coins()<2) {
        throw std::runtime_error("Stolen player does not have enough coins!");
    }
    stealFrom.incrementCoins(-2);
    incrementCoins(2);
    didSteal = true;
    stolenPlayer = &stealFrom;
    getCurrGame()->nextTurn();
}

std::string Captain::role() {     return "Captain";}

void Captain::resetPlayer () {
    didSteal = false;
    stolenPlayer = nullptr;
}

void Captain::block(Player &blockedPlayer) {
    if (blockedPlayer.role()!="Captain") {
        throw std::runtime_error("This Player can't block that!");
    }
    Captain *blockedCaptain = dynamic_cast<Captain*>(&blockedPlayer);
    if (!blockedCaptain->didSteal) {
        throw std::runtime_error("The blocked Player didn't steal!");
    }
    blockedCaptain->incrementCoins(-2);
    blockedCaptain->stolenPlayer->incrementCoins(2); // CHECK IF THE STOLEN PLAYER IS STILL IN THE GAME!!!!! -- TODO --
    blockedCaptain->resetPlayer();

}