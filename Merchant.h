#ifndef CARD_H_MERCHANT_H
#define CARD_H_MERCHANT_H

class Merchant : protected Card{
public:
    virtual void applyEncounter(Player& player) const override;

    /**      Execption!!!!!!!!!!!!     **/
};



#endif //CARD_H_MERCHANT_H
