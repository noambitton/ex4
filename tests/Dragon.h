#ifndef CARD_H_DRAGON_H
#define CARD_H_DRAGON_H


class Dragon : protected Battle{
public:
    Dragon();

    virtual void applyLoss(Player& player) const override;
private:
    static const string DRAGON_NAME = "Dragon";
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_DEFAULT_HEALTH_POINTS_DAMAGE_UPON_LOSS = 0;
};


#endif //CARD_H_DRAGON_H