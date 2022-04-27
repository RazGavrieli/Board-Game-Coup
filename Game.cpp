#include "Game.hpp"
#include "Player.hpp"
using namespace coup;

Game::Game() {
    gameRunning = false;
    playerTurn = nullptr;
}

// Game::~Game() {
//     std::cout << "here\n";
//     //onlinePlayers->resize(0);
//     //delete onlinePlayers;
// }

void Game::revivePlayer(Player *revivedPlayer) {
    //ADD REVIVE PLAYER IMPLEMENTATION -- TODO --
    //THIS FUNCTION IS CALLED WHEN CONTESSA SAVES A PLAYER
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        if (onlinePlayers.at(i)==nullptr) {
            onlinePlayers[i] = revivedPlayer;
        }
    }
    
}

void Game::addPlayer(Player *newPlayer) {
    if(gameRunning) {
        throw std::runtime_error("can't add new players, game already running!");
    }
    if (onlinePlayers.empty()) {
        playerTurn = newPlayer;
    }
    onlinePlayers.push_back(newPlayer);
}

bool Game::checkForWin() {
    size_t numOfplayers = 0;
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        if (onlinePlayers.at(i)!=nullptr) {
            numOfplayers++;
        }
    }
    
    if (numOfplayers == 1) {
        return true;
    } else {
        return false;
    }
}

void Game::removePlayer(Player *losingPlayer) {
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        if (onlinePlayers.at(i)==losingPlayer) {
            std::cout << "Removing " << losingPlayer->getNickname() << " from the game!\n";
            onlinePlayers[i] = nullptr;
            break;
        }
    }

    if (checkForWin()) {
        // THERE IS A WINNER STOP THE GAME
        gameRunning = false;
    }
}

std::vector<std::string> Game::players() {
    gameRunning = true; // ADD BETTER IMPLEMENTATION OF GAME INITIATION -- TODO --
    std::vector<std::string> playerNicknames; 
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        if (onlinePlayers.at(i)!=nullptr) {
             playerNicknames.push_back(onlinePlayers.at(i)->getNickname());
        }
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
    if (checkForWin()) {
        //THERE IS A WINNER DO SOMETHING
        gameRunning = false;
    }
    size_t i = 0;
    while (onlinePlayers.at(i)!=playerTurn) i++;
    playerTurn = onlinePlayers.at(++i%onlinePlayers.size());
    if (playerTurn==nullptr) {
        std::cout << "HERE";
        nextTurn();
        return;
    }
    std::cout << "\t\tGAME MESSAGE: " << playerTurn->getNickname() << "'s(" << playerTurn->role() << ") turn\n";
}

std::string Game::winner() {
    if (gameRunning) {
        throw std::runtime_error("game is still running");
    }
    return onlinePlayers.at(0)->getNickname();
}