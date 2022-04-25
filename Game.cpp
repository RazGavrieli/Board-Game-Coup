#include "Game.hpp"
#include "Player.hpp"
using namespace coup;

Game::Game() {
    // idk -- TODO --
    
}

void Game::addPlayer(Player newPlayer) {
    if(gameRunning) {
        throw std::runtime_error("can't add new players, game already running!");
    }
    onlinePlayers.push_back(newPlayer);
}

void Game::removePlayer(Player losingPlayer) {
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        // SEARCH FOR THE losingPlayer IN onlinePlayers -- TODO --
    }
    // AFTER REMOVAL OF THE PLAYER:
    if (onlinePlayers.size() == 1) {
        // THE ONLY PLAYER LEFT IS THE WINNER, ANNOUNCE IT -- TODO --
        gameRunning = false;
    }
}

std::vector<std::string> Game::players() {
    std::vector<std::string> playerNicknames; 
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        playerNicknames.push_back(onlinePlayers.at(i).getNickname());
    }
    return playerNicknames;
}

std::string Game::turn() {
    return playerTurn.getNickname();
}

std::string Game::winner() {
    if (gameRunning) {
        throw std::runtime_error("game is still running");
    }
    return onlinePlayers.at(0).getNickname();
}