#include "Game.hpp"
#include "Player.hpp"
using namespace coup;

Game::Game() {
    gameStarted = false;
    gameFinished = false;
    playerTurn = nullptr;
}

// Game::~Game() {
//     std::cout << "here\n";
//     //onlinePlayers->resize(0);
//     //delete onlinePlayers;
// }

void Game::revivePlayer(Player *revivedPlayer) {
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        if (onlinePlayers.at(i)==nullptr) {
            onlinePlayers[i] = revivedPlayer;
        }
    }
    revivedPlayer->alive = true;
}

void Game::addPlayer(Player *newPlayer) {
    if(gameStarted||gameFinished) {
        throw std::runtime_error("can't add new players, game already initiated!");
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
        gameFinished = true;
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
    losingPlayer->alive = false;
    std::cout << "removed a player, ";
    if (checkForWin()) {
        std::cout << "it was the 2nd last player!\n";
        gameFinished = true;
    } else std::cout << "\n";
}

std::vector<std::string> Game::players() {
    gameStarted = true; // ADD BETTER IMPLEMENTATION OF GAME INITIATION -- TODO --
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
        gameFinished = true;
    }
    size_t i = 0;
    while (onlinePlayers.at(i)!=playerTurn) i++;
    playerTurn = onlinePlayers.at(++i%onlinePlayers.size());
    if (playerTurn==nullptr&&!gameFinished) {
        std::cout << "HERE";
        nextTurn();
        return;
    } else if (gameFinished) {
        for (size_t i = 0; i < onlinePlayers.size(); i++)
        {
            if (onlinePlayers.at(i)!=nullptr) {
                playerTurn = onlinePlayers.at(i);
                break;
            }
        }
        
    }
    std::cout << "\t\tGAME MESSAGE: " << playerTurn->getNickname() << "'s(" << playerTurn->role() << ") turn\n";
}

std::string Game::winner() {
    if (!gameFinished) {
        throw std::runtime_error("game did not finish");
    }
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        if (onlinePlayers.at(i)!=nullptr) {
            return onlinePlayers.at(i)->getNickname();
        }
    }
    
    return "fatal error";
}