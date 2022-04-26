#ifndef Player_H
#define Player_H


#include <iostream>
namespace coup
{
    class Game;
    class Player {
        int amountOfCoins;
        std::string nickname;

        public:   
        Player();
        Player(Game, std::string);

        std::string getNickname();
        int coins();
        void income();
        void foreign_aid();
        void coup(Player); // overridden by assassin
        
        /*specific role actions (these function are overridden by the relevant role)*/ 
        void transfer(Player, Player);
        void tax();
        void steal(Player);
        void block(Player);
        


    };
} // namespace coup
#endif