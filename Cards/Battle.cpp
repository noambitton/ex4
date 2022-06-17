#include "Battle.h"

Battle::Battle(CardType name, /**string monsterName, **/int force, int loot, int healthPointsDamageUponLoss) : Card(name),
                                                        /**m_monsterName(monaterName), **/m_force(force), m_loot(loot),
                                                        m_healthPointsDamageUponLoss(healthPointsdamageUponLoss) {};

void Battle::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_monsterName);
    }
    else{
        apllyLoss(player);
    }
}

void Battle::createCardDescription(std::ostream& ostream, const Card& card)
{
    bool isDragon = (m_name == "Dragon");
    printCardDetails(ostream, m_name);
    printMonsterDetails(ostream, m_force, m_healthPointsDamageUponLoss, m_loot, isDragon);
    printEndOfCardDetails(ostream);
}