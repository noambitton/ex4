#ifndef CARD_H_BATTLE_H
#define CARD_H_BATTLE_H
#include "Card.h"

//enum class BattleCardType {Vampire, Goblin, Dragon}; // The type of the Battle card.

class Battle : protected Card{
public:
    /*
     * C'tor of Battle (Card) object.
     */
    Battle(string name, /**string monsterName, **/int force, int loot, int healthPointsDamageUponLoss);

    /*
     * When encountering a battle card, applyEncounterBattle applies a battle between the player and a monster, and the
     * player can either win and get and move one level up and earn more coins or loose and loose health points.
     *
     * @param player - the player that encounters the battle card.
     */
    virtual void applyEncounter(Player& player) const override;
private:
    //string m_monsterName;//BattleCardType m_cardName;
    int m_force;
    int m_healthPointsdDamageUponLoss;
    int m_loot;

    /*
    * Creates description of a Card instance: for printing (card details and a separating line).
    */
    virtual void createCardDescription(std::ostream& ostream, const Card& card) const override;

    /*
     * When encountering a battle card and loosing, applyLoss updates the player details according to the requirements
     * of the monster to which the player lost.
     *
     * @param player - the player that lost to the monster of the Battle card.
     *
     * @return
     *      void
     */
    virtual void applyLoss(Player& player) const = 0;
};
#endif //CARD_H_BATTLE_H