#include "Game.hpp"
#include "Player.hpp"
using namespace coup;

Game::Game() {
    gameStarted = false;
    gameFinished = false;
    playerTurn = nullptr;
}

void Game::revivePlayer(Player *revivedPlayer) {
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        if (onlinePlayers.at(i)==nullptr) {
            onlinePlayers[i] = revivedPlayer;
        }
    }
    std::cout << "\t\tGAME MESSAGE: Reviving " << revivedPlayer->getNickname() << "\n";
    revivedPlayer->setAlive(true);
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
    } 
    return false;
    
}

void Game::removePlayer(Player *losingPlayer) {
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        if (onlinePlayers.at(i)==losingPlayer) {
            std::cout << "\t\t GAME MESSAGE: Removing " << losingPlayer->getNickname() << " from the game!\n";
            onlinePlayers[i] = nullptr;
            break;
        }
    }
    losingPlayer->setAlive(false);
    if (checkForWin()) {
        gameFinished = true;
    }
}

std::vector<std::string> Game::players() const{
    std::vector<std::string> playerNicknames; 
    for (size_t i = 0; i < onlinePlayers.size(); i++)
    {
        if (onlinePlayers.at(i)!=nullptr) {
             playerNicknames.push_back(onlinePlayers.at(i)->getNickname());
        }
    }
    return playerNicknames;
}

std::string Game::turn() const{
    return playerTurn->getNickname();;
}

Player* Game::turnPlayer() const{
    return playerTurn;
}

void Game::nextTurn() {
    gameStarted = true; 
    if (checkForWin()) {
        gameFinished = true;
    }
    size_t i = 0;
    while (onlinePlayers.at(i)!=playerTurn) {i++;}
    playerTurn = onlinePlayers.at(++i%onlinePlayers.size());
    if (playerTurn==nullptr&&!gameFinished) {
        nextTurn();
        return;
    } 
    if (gameFinished) {
        for (size_t i = 0; i < onlinePlayers.size(); i++)
        {
            if (onlinePlayers.at(i)!=nullptr) {
                playerTurn = onlinePlayers.at(i);
                break;
            }
        }
    }
    if (playerTurn!=nullptr) {
        std::cout << "\t\tGAME MESSAGE: " << playerTurn->getNickname() << "'s(" << playerTurn->role() << ") turn\n";
    }
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