#include "Treasure.h"

virtual void applyEncounter(Player& player) const
{
    player.addCoins(m_llot);
    printTreasureMessage();
}