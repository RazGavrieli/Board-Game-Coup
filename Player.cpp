#include "Player.hpp"
#include "Game.hpp"

#include <iostream>
using namespace coup;

#define INIT_COINS 0
Player::Player() { 
    // for default constructor of a game
}
Player::Player(Game & game, std::string name) {
    this->nickname = name;
    this->amountOfCoins = INIT_COINS;
    this->alive = true;
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

void Player::resetPlayer() {
    didForeign_aid = false;
}

std::string Player::role() {     return "This player still has no role";}

int Player::coins() {  return this->amountOfCoins;}

void Player::income() {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (coins()>=10) {
        throw std::runtime_error("Player must coup!");
    }
    
    incrementCoins(1);
    resetPlayer();
    currGame->nextTurn();
}

void Player::foreign_aid() {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (coins()>=10) {
        throw std::runtime_error("Player must coup!");
    }

    incrementCoins(2);
    resetPlayer();
    didForeign_aid = true;
    currGame->nextTurn();
}
bool Player::isInGame(Player &coup) {
    std::cout << "the coup.alive is " << coup.alive;
    if (coup.currGame!=currGame||!coup.alive) {
        return false; 
    } else {
        std::cout << " returned true\n!";
        return true;
    }
}
void Player::coup(Player &coup) {
    if (!isPlaying()) {
        throw std::runtime_error("this isn't the player's turn!");
    }
    if (this->amountOfCoins<7) {
        throw std::runtime_error("Not enough coins");
    }
    if (!isInGame(coup)) {
        throw std::runtime_error("Player not in game!");
    }
    currGame->removePlayer(&coup);
    resetPlayer();
    incrementCoins(-7);
    currGame->nextTurn();
}

void Player::transfer(Player &payer, Player &receiver) {
    throw std::runtime_error("This Player can't transfer");
}

void Player::tax() {
    throw std::runtime_error("This Player can't tax");
}

void Player::steal(Player &a) {
    throw std::runtime_error("This Player can't steal");
}

void Player::block(Player &a) {
    throw std::runtime_error("This Player can't block "); 
}