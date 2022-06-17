#include "Rogue.h"
#include "utilities.h"
using std::string;
using std::ostream;

Rogue::Rogue(const string &name) : Player(name) { }


void Rogue::addCoins(int coinsAddition) {
    Player::addCoins(2*coinsAddition);
}


Player *Rogue::clone() const {
    return new Rogue(*this);
}

std::ostream &Rogue::printPlayerInfo(std::ostream &os) const {
    printPlayerDetails(os, getName(), JOB, getLevel(), getForce(), getHealthPoints(),
                       getCoins());
    return os;
}

