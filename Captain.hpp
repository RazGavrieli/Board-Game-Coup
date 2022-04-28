#include "Player.hpp"
#include "Game.hpp"

#include <iostream>

namespace coup
{
    class Captain : public Player
    {
        /* private fields */
        int didSteal = 0;
        Player *stolenPlayer = nullptr;

    public:
        /* --- constructors --- */
        using Player::Player;

        /* --- getters --- */
        std::string role() const override;
        int isSteal() const;
        Player* getStolenPlayer() const;

        /* --- setters --- */
        void resetPlayer() override;

        /* --- functions --- */
        void steal(Player &) override;
        void block(Player &) override;
    };

}

