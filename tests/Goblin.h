#ifndef CARD_H_GOBLIN_H
#define CARD_H_GOBLIN_H

class Goblin : protected Battle{
public:
    Goblin();

    virtual void applyLoss(Player& player) const override;
private:
    static const string GOBLIN_NAME = "Goblin";
    static const int GOBLIN_FORCE = 6;
    static const int GOBLIN_LOOT = 2;
    static const int GOBLIN_HEALTH_POINTS_DAMAGE_UPON_LOSS = 10;
};


#endif //CARD_H_GOBLIN_H