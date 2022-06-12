#include "Wizard.h"
#include "utilities.h"
using std::string;
using std::ostream;

Wizard::Wizard(const string &name) : Player(name) { }

void Wizard::heal(int healthPointsAddition)
{
    Player::heal(2*healthPointsAddition);
}

Player *Wizard::clone() const
{
    return new Wizard(*this);
}

std::ostream &Wizard::printPlayerInfo(ostream &os) const
{
    printPlayerDetails(os, m_name, m_job, m_level, m_force, m_healthPoints, m_coins);
    return os;
}

