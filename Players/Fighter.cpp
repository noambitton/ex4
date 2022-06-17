#include "Fighter.h"
#include "utilities.h"
using std::string;
using std::ostream;

Fighter::Fighter(const string &name) : Player(name) { }

int Fighter::getAttackStrength() const {
    return (2*getForce() + getLevel());
}

Player *Fighter::clone() const {
    return new Fighter(*this);
}

std::ostream &Fighter::printPlayerInfo(ostream &os) const
{
    printPlayerDetails(os, getName(), JOB, getLevel(), getForce(), getHealthPoints(),
                       getCoins());
    return os;
}