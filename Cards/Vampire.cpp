#include "Vampire.h"


Vampire::Vampire() : Battle(VAMPIRE_NAME, VAMPIRE_FORCE, VAMPIRE_LOOT, VAMPIRE_HEALTH_POINTS_DAMAGE_UPON_LOSS) {}

void Vampire::applyLoss(Player& player) const
{
    player.damage(healthPointsDamageUponLoss);
    player.LossForcePoint();
    printLossBattle(player.getName(), m_monsterName);
}