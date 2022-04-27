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
        bool didForeign_aid = false;
        bool alive = true;
            Player();
            Player(Game &, std::string);

            Game* getCurrGame();
            std::string getNickname();
            void incrementCoins(int);
            bool isPlaying();
            virtual void resetPlayer(); // to be called after every move except special blockable moves

            virtual std::string role();
            int coins();
            void income();
            void foreign_aid();
            virtual void coup(Player&);
            // std::string role(); // STILL NEEDS IMPLEMENTATION -- TODO --

            /*specific role actions (these function are overridden by the relevant role)*/ 
            virtual void transfer(Player&, Player&);
            virtual void tax();
            virtual void steal(Player&);
            virtual void block(Player&);
        


    };
} // namespace coup
#endif