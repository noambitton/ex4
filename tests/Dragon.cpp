#include "Dragon.h"

Dragon::Dragon() : Battle(DRAGON_NAME, DRAGON_FORCE, DRAGON_LOOT, DRAGON_DEFAULT_HEALTH_POINTS_DAMAGE_UPON_LOSS) {}

virtual void Dragon::applyLoss(Player& player) const override
{
    player.kill();
    printLossBattle(player.getName(), m_monsterName);
}