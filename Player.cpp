#include "Player.hpp"
#include "Game.hpp"

#include <iostream>
using namespace coup;

Player::Player() { 
    // for default constructor of a game
}
Player::Player(Game game, std::string name) {
    this->nickname = name;
    game.addPlayer(*this);
}

int Player::coins() {
    return this->amountOfCoins;
}

void Player::income() {
    // CHECK FOR WHOS TURN IS IT -- TODO --

    // CHECK IF THE PLAYER HAS MORE THAN 10 COINS (HE MUST COUP) -- TODO --

    this->amountOfCoins+=1;
}

void Player::foreign_aid() {
    // CHECK FOR WHOS TURN IS IT -- TODO --

    // ADD IMPLEMENTATION OF BLOCKING FOREGIN AID -- TODO --
    this->amountOfCoins+=2;
}

void Player::coup(Player coup) {
    // CHECK FOR WHOS TURN IS IT -- TODO --
    if (this->amountOfCoins<7) {
        throw std::runtime_error("Not enough coins");
    }
    // coup a player -- TODO --
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
    // ADD IMPLEMENTATION THAT CHECKS WHICH ACTION IS BEING BLOCKED (IF ANY)  -- TODO --
    // AND ACT ACCORDINGLY -- TODO --

    throw std::runtime_error("This Player can't block "); // this exception is temporary -- TODO --
}