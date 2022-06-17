#include "Fairy.h"

virtual void applyEncounter(Player& player) const override{
    bool isWizard = isSpecialPlayerType(player);
    if (isWizard){
        player.heal(m_healthPointsChange);
    }

    printFairyMessage(isWizard);
}