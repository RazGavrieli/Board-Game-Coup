#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

#include "doctest.h"

TEST_CASE("GAME SCENARIO 1") {
    Game scenario1{};

    Duke PlayerONE{scenario1, "Player ONE"};
	Assassin PlayerTWO{scenario1, "Player TWO"};
	Duke PlayerTHREE{scenario1, "Player THREE"};
	Contessa PlayerFOUR{scenario1, "Player FOUR"};
    vector<Player*> Players = {&PlayerONE, &PlayerTWO, &PlayerTHREE, &PlayerFOUR};

    CHECK_EQ(PlayerTWO.role(), "Assassin");
    CHECK_EQ(PlayerONE.role(), PlayerTHREE.role());
    CHECK_NE(PlayerONE.getNickname(), PlayerTHREE.getNickname());

    CHECK_EQ(scenario1.players().size(), 4);
    CHECK_NOTHROW(PlayerONE.income());
    CHECK_THROWS(PlayerTHREE.income());

    CHECK_EQ(PlayerONE.coins(), 1);
    CHECK_EQ(PlayerTHREE.coins(), 0);
    //PlayerTWO.income();
    for (size_t i = 1; i < Players.size(); i++)
    {
        CHECK_NOTHROW(Players.at(i)->income());
    }
    for (size_t j = 0; j < 2; j++)
    {
        for (size_t i = 0; i < Players.size(); i++)
        {
            CHECK_NOTHROW(Players.at(i)->income());
        }
    }

    for (size_t i = 0; i < Players.size(); i++)
    {
        CHECK_EQ(Players.at(i)->coins(), 3);
    }

    CHECK_THROWS(PlayerONE.coup(PlayerTWO));
    CHECK_NOTHROW(PlayerONE.tax());
    CHECK_NOTHROW(PlayerTWO.coup(PlayerONE));
    CHECK_EQ(scenario1.players().size(), 3);
    CHECK_EQ(PlayerTHREE.coins(), 3);
    CHECK_NOTHROW(PlayerTHREE.tax());
    CHECK_EQ(PlayerTHREE.coins(), 6);
    CHECK_THROWS(PlayerTWO.income());
    CHECK_NOTHROW(PlayerFOUR.block(PlayerTWO));
    CHECK_EQ(scenario1.players().size(), 4);
    CHECK_THROWS(PlayerTWO.income());
    CHECK_EQ(PlayerONE.coins(), 6);
    PlayerFOUR.foreign_aid();
    CHECK_NOTHROW(PlayerONE.income());
    CHECK_EQ(PlayerONE.coins(), 7);
    CHECK_THROWS(PlayerTWO.coup(PlayerFOUR)); // not enough coins
    CHECK_THROWS(PlayerTWO.tax());
    CHECK_NOTHROW(PlayerTWO.foreign_aid());
    CHECK_THROWS(PlayerTHREE.block(PlayerONE));
    CHECK_NOTHROW(PlayerTHREE.block(PlayerTWO));
    CHECK_NOTHROW(PlayerTHREE.tax());
    PlayerFOUR.foreign_aid();
    PlayerONE.income();
    PlayerTWO.income();
    PlayerTHREE.income();
    CHECK_NOTHROW(PlayerFOUR.coup(PlayerONE));
    CHECK_NOTHROW(PlayerTWO.foreign_aid());
    CHECK_NOTHROW(PlayerTHREE.block(PlayerTWO));
    PlayerTHREE.coup(PlayerFOUR);
    PlayerTWO.foreign_aid();
    PlayerTHREE.tax();
    PlayerTWO.coup(PlayerTHREE);
    CHECK_EQ(scenario1.players().size(), 1);
    CHECK_EQ(scenario1.winner(), "Player TWO");
}

TEST_CASE("GAME SCENARIO 2") {
    Game scenario2{};

    Duke PlayerONE{scenario2, "Player ONE"};
	Assassin PlayerTWO{scenario2, "Player TWO"};
	Captain PlayerTHREE{scenario2, "Player THREE"};
    vector<Player*> Players = {&PlayerONE, &PlayerTWO, &PlayerTHREE};

    CHECK_EQ(PlayerTHREE.role(), "Captain");

    CHECK_EQ(scenario2.players().size(), 3);
    CHECK_NOTHROW(PlayerONE.tax()); // 3 (COINS)
    CHECK_THROWS(PlayerTWO.tax()); 
    CHECK_THROWS(PlayerTHREE.income()); 
    CHECK_NOTHROW(PlayerTWO.income());// 1 (COINS)
    CHECK_EQ(PlayerTWO.coins(), 1);
    CHECK_NOTHROW(PlayerTHREE.steal(PlayerTWO));  // THREE 1, TWO 0 (COINS)
    CHECK_EQ(PlayerONE.coins(), 3);
    CHECK_EQ(PlayerTHREE.coins(), 1);
    CHECK_EQ(PlayerTWO.coins(), 0);
    for (size_t j = 0; j < 5; j++)
    {
        for (size_t i = 0; i < Players.size(); i++)
        {
            CHECK_NOTHROW(Players.at(i)->income()); // ADD 5 TO EACH PLAYER (COINS)
        }
    }
    CHECK_EQ(PlayerTHREE.coins(), 6);
    CHECK_EQ(PlayerTWO.coins(), 5);
    CHECK_EQ(PlayerONE.coins(), 8);
    CHECK_NOTHROW(PlayerONE.coup(PlayerTHREE));
    CHECK_THROWS(scenario2.winner());
    CHECK_EQ(PlayerONE.coins(), 1);
    CHECK_EQ(scenario2.players().size(), 2);
    CHECK_THROWS(PlayerTWO.coup(PlayerTHREE)); // PLAYER THREE ALREADY DEAD
    CHECK_EQ(scenario2.players().size(), 2);
    CHECK_NOTHROW(PlayerTWO.coup(PlayerONE));
    CHECK_EQ(scenario2.players().size(), 1);
    CHECK_THROWS(PlayerONE.coup(PlayerTWO)); // PLAYER ONE ALREADY DEAD
    CHECK_EQ(scenario2.winner(), "Player TWO");
}

TEST_CASE("GAME SCENARIO 3") {
    Game scenario3{};

    Ambassador PlayerONE{scenario3, "Player ONE"};
	Contessa PlayerTWO{scenario3, "Player TWO"};
    Duke PlayerTHREE{scenario3, "Player THREE"};
    vector<Player*> Players = {&PlayerONE, &PlayerTWO, &PlayerTHREE};

    for (size_t j = 0; j < 8; j++)
    {
        for (size_t i = 0; i < Players.size(); i++)
        {
            CHECK_NOTHROW(Players.at(i)->income());
        }
        CHECK_EQ(PlayerONE.coins(), j+1);
        CHECK_EQ(PlayerTWO.coins(), j+1);
        CHECK_EQ(PlayerTHREE.coins(), j+1);
    }

    CHECK_NOTHROW(PlayerONE.transfer(PlayerTWO, PlayerTHREE));
    CHECK_EQ(PlayerTWO.coins(), 7);
    CHECK_EQ(PlayerTHREE.coins(), 9);
    CHECK_NOTHROW(PlayerTWO.coup(PlayerTHREE));
    CHECK_THROWS(PlayerONE.coup(PlayerTHREE)); // player three already dead
    CHECK_NOTHROW(PlayerONE.coup(PlayerTWO));
    CHECK_EQ(scenario3.winner(), "Player ONE");
}