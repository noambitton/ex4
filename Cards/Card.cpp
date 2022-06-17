#include "Card.h"


std::ostream &Card::createCardDescription(std::ostream& os) const
{
    printCardDetails(os, m_cardName);
    printEndOfCardDetails(os);
    return os;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    return card.createCardDescription(os);
}