#ifndef CARD_H_CARD_H
#define CARD_H_CARD_H

#include <string>
#include "Players/Player.h"
#include "utilities.h"

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
//enum class CardType {Battle, Buff, Heal, Treasure}; // The type of the Card

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card(string cardName) : m_cardName(cardName);

    virtual ~Card() {};

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    string m_cardName;
    virtual std::ostream &createCardDescription(std::ostream& os) const;

};



#endif //CARD_H_CARD_H
