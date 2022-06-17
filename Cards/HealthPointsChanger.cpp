#include "HealthPointsChnager"

bool HealthPointsChanger::isSpecialPlayerType(Player& player) const
{
    return (player.getNAme() == m_specialPlayerType);
}