#include "Treasure.h"
#include "Player.h"

virtual void applyEncounter(Player& player) const
{
    player.addCoins(m_loot);
    printTreasureMessage();
}