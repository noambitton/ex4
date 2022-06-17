#ifndef CARD_H_VAMPIRE_H
#define CARD_H_VAMPIRE_H

class Vampire : protected Battle{
public:
    Vampire();

    virtual void applyLoss(Player& player) const override;
private:
    static const string VAMPIRE_NAME = "Vampire";
    static const int VAMPIRE_FORCE = 10;
    static const int VAMPIRE_LOOT = 2;
    static const int VAMPIRE_HEALTH_POINTS_DAMAGE_UPON_LOSS = 10;
};

#endif //CARD_H_VAMPIRE_H