#include "Merchant.h"

virtual void applyEncounter(Player& player) const override
{
    ostream os();
    cout << printMerchantInitialMessageForInteractiveEncounter(os, player.getName(), player.getCoins());
}