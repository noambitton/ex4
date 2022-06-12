
#ifndef PLAYERTRAIL_CARDS_H
#define PLAYERTRAIL_CARDS_H

#include <iostream>
using std::string;

class Card{
public:
    Card();

    void encounter();
private:
    string m_cardName;
};
#endif //PLAYERTRAIL_CARDS_H
