#ifndef Player_H
#define Player_H


#include <iostream>
namespace coup
{
    class Game;
    class Player {
        int amountOfCoins;
        std::string nickname;
        Game *currGame;

        public:   
        Player();
        Player(Game &, std::string);

        Game* getCurrGame();
        std::string getNickname();
        void incrementCoins(int);
        bool isPlaying();

        int coins();
        void income();
        void foreign_aid();
        void coup(Player); // overridden by assassin
        // std::string role(); // STILL NEEDS IMPLEMENTATION -- TODO --

        /*specific role actions (these function are overridden by the relevant role)*/ 
        void transfer(Player, Player);
        void tax();
        void steal(Player);
        void block(Player);
        


    };
} // namespace coup
#endif