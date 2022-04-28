#include "Player.hpp"
#include "Game.hpp"

#include <iostream>
namespace coup
{
    class Ambassador : public Player
    {
        /* private fields */
        Player *payer = nullptr;
        Player *receiver = nullptr;
        bool didTransfer = false;

    public:
        /* --- constructors --- */
        using Player::Player;

        /* --- getters --- */
        std::string role() const override;

        /* --- setters --- */
        void resetPlayer() override;

        /* --- functions --- */
        void transfer(Player &, Player &) override;
        void block(Player &) override;
    };

}