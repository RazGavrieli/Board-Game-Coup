#include "Game.hpp"
#include "Player.hpp"
using namespace coup;

Game::Game() {
    std::cout << "HERE\n";
    // idk -- TODO --
    gameRunning = false;
    playerTurn = nullptr;
}

// Game::~Game() {
//     std::cout << "here\n";
//     //onlinePlayers->resize(0);
//     //delete onlinePlayers;
// }

void Game::addPlayer(Player *newPlayer) {
    if(gameRunning) {
        throw std::runtime_error("can't add new players, game already running!");
    }
    if (onlinePlayers.empty()) {
        playerTurn = newPlayer;
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
    gameRunning = true;
    std::vector<std::string> playerNicknames; 
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        playerNicknames.push_back(onlinePlayers.at(i)->getNickname());
    }
    return playerNicknames;
}

std::string Game::turn() {
    return playerTurn->getNickname();;
}

Player* Game::turnPlayer() {
    return playerTurn;
}

void Game::nextTurn() {
    size_t i = 0;
    while (onlinePlayers.at(i)!=playerTurn) i++;
    playerTurn = onlinePlayers.at(++i%onlinePlayers.size());
    std::cout << "\t\t\tGAME MESSAGE: " << playerTurn->getNickname() << "'s turn\n";
}

std::string Game::winner() {
    if (gameRunning) {
        throw std::runtime_error("game is still running");
    }
    return onlinePlayers.at(0)->getNickname();
}