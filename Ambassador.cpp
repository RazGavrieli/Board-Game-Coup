#include "Ambassador.hpp"
#include "Captain.hpp"

using namespace coup;
class Captain;
void Ambassador::transfer(Player &payer, Player &receiver) {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (coins()>=10) {
        throw std::runtime_error("Player must coup!");
    }
    if (!isInGame(payer)||!isInGame(receiver)) {
        throw std::runtime_error("Player not in game!");
    }
    if (payer.coins()<1) {
        throw std::runtime_error("Payer Player does not have enough coins!");
    }
    payer.incrementCoins(-1);
    receiver.incrementCoins(1);
    
    this->payer = &payer;
    this->receiver = &receiver;
    didTransfer = true;
    getCurrGame()->nextTurn();
}

std::string Ambassador::role() {     return "Ambassador";}

void Ambassador::resetPlayer() {
    didTransfer = false;
    payer = receiver = nullptr;
}

void Ambassador::block(Player &blockedPlayer) {
    if (!isInGame(blockedPlayer)) {
        throw std::runtime_error("Player not in game!");
    }
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
