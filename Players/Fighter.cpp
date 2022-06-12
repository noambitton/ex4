#include "Fighter.h"
#include "utilities.h"
using std::string;
using std::ostream;

Fighter::Fighter(const string &name) : Player(name) { }

int Fighter::getAttackStrength() const {
    return (2*m_force + m_level);
}

Player *Fighter::clone() const {
    return new Fighter(*this);
}

std::ostream &Fighter::printPlayerInfo(ostream &os) const
{
    printPlayerDetails(os, m_name, m_job, m_level, m_force, m_healthPoints, m_coins);
    return os;
}