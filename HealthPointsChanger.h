#ifndef CARD_H_HEALTHPOINTSCHANGER_H
#define CARD_H_HEALTHPOINTSCHANGER_H

class HealthPointsChanger : protected Card{
public:
    virtual void applyEncounter(Player& player) const = 0;
private:
    int m_healthPointsChange;
    string m_specialPlayerType;

    bool isSpecialPlayerType(Player& player) const;
};


#endif //CARD_H_HEALTHPOINTSCHANGER_H