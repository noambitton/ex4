#ifndef CARD_H_TREASURE_H
#define CARD_H_TREASURE_H

class Treasure : protected Card{
public:
    Treasure() : Card(TREASURE_NAME), m_loot(TREASURE_LOOT);
    virtual void applyEncounter(Player& player) const override;
private:
    int m_loot;

    static const string TREASURE_NAME = "Treasure";
    static const int TREASURE_LOOT = 10;
};


#endif //CARD_H_TREASURE_H