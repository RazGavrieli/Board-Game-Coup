#include "Contessa.hpp"
#include "Assassin.hpp"
using namespace coup;

std::string Contessa::role() {     return "Contessa";}

void Contessa::block(Player &blockedPlayer) {
    if (blockedPlayer.role()!="Assassin") {
        throw std::runtime_error("This Player can't block that!");
    }
    Assassin *blockedAssassin = dynamic_cast<Assassin*>(&blockedPlayer); 
    if (!blockedAssassin->didCoup) {
        throw std::runtime_error("The blocked Player didn't steal!");
    }

    getCurrGame()->revivePlayer(blockedAssassin->coupedPlayer); // TO IMPLEMENT
    blockedAssassin->didCoup = false;
    blockedAssassin->coupedPlayer = nullptr;
}