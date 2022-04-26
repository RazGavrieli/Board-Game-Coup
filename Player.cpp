#include "Player.hpp"
#include "Game.hpp"

#include <iostream>
using namespace coup;

#define INIT_COINS 0
// Player::Player() { 
//     // for default constructor of a game
// }
Player::Player(Game & game, std::string name) {
    this->nickname = name;
    this->amountOfCoins = INIT_COINS;
    game.addPlayer(this);
    currGame = &game;
}

void Player::incrementCoins(int increment) {
    this->amountOfCoins+=increment;
}

Game* Player::getCurrGame() { return currGame;}

std::string Player::getNickname() {  return this->nickname;}

bool Player::isPlaying() {
    if (currGame->turnPlayer()!=this) {
        std::cout << currGame->turn() << "!=" << nickname << std::endl;
        return false;
    }
    return true;
}

int Player::coins() {  return this->amountOfCoins;}

void Player::income() {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (coins()>=10) {
        throw std::runtime_error("Player must coup!");
    }
    
    incrementCoins(1);
    currGame->nextTurn();
}

void Player::foreign_aid() {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (coins()>=10) {
        throw std::runtime_error("Player must coup!");
    }

    // ADD IMPLEMENTATION OF BLOCKING FOREGIN AID -- TODO --
    incrementCoins(2);
    currGame->nextTurn();
}

void Player::coup(Player coup) {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (this->amountOfCoins<7) {
        throw std::runtime_error("Not enough coins");
    }
    currGame->removePlayer(coup);
    currGame->nextTurn();
}

void Player::transfer(Player a, Player b) {
    throw std::runtime_error("This Player can't transfer");
}

void Player::tax() {
    throw std::runtime_error("This Player can't tax");
}

void Player::steal(Player a) {
    throw std::runtime_error("This Player can't steal");
}

void Player::block(Player a) {
    // CHECK FOR WHOS TURN IS IT -- TODO --
    // CHECK IF THE PLAYER HAS MORE THAN 10 COINS (HE MUST COUP) -- TODO --
    // ADD IMPLEMENTATION THAT CHECKS WHICH ACTION IS BEING BLOCKED (IF ANY)  -- TODO --
    // AND ACT ACCORDINGLY -- TODO --

    throw std::runtime_error("This Player can't block "); // this exception is temporary -- TODO --
}
