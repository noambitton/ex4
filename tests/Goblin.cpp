#include "Goblin.h"

Goblin::Goblin() : Battle(GOBLIN_NAME, GOBLIN_FORCE, GOBLIN_LOOT, GOBLIN_HEALTH_POINTS_DAMAGE_UPON_LOSS) {}

virtual void Goblin::applyLoss(Player& player) const override
{
    player.damage(healthPointsDamageUponLoss);
    printLossBattle(player.getName(), m_monsterName);
}



