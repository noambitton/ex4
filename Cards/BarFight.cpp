#include "BarFight.h"

class Fairy : protected HealthPointsChanger{
    Fairy : Card(FAIRY_NAME), m_healthPointsChange(FAIRY_HEALTH_POINTS_CHANGE),
            m_specialPlayerType(FAIRY_SPECIAL_PLAYER_TYPE);

    virtual void applyEncounter(Player& player) const override;

private:
    static const string FAIRY_NAME = "Fairy";
    static const int FAIRY_HEALTH_POINTS_CHANGE = 10;
    static const string FAIRY_SPECIAL_PLAYER_TYPE = "Wizard";
};
