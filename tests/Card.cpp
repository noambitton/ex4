#include "Card.h"

void Card::createCardDescription(std::ostream& os)
{
    printCardDetails(os, m_cardName);
    printEndOfCardDetails(os);
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    createCardDescription(os);
    return os;
}