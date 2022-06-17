//
// Created by User on 09/06/2022.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>
using std::string;

class Player
{
public:
    /*
    * C'tor of Player class.
     *
     * @param name - The name of the player.
     * The name must contain only letters in english without spaces, the maximum letters allowed is 15
     * otherwise an InvalidPlayerName exception will be thrown
     * @return
     *      A new instance of Player.
    */
    explicit Player(const string& name);

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    /*
     * Copy C'tor of Player class.
     *
     * @param other - An existing instance of the class.
     *
     * @return
     *      A new instance of Player (which is a copy of the given instance).
     */
    Player(const Player& other) = default;

    virtual Player* clone() const = 0;

    /*
     * D'tor of Player class.
     *
     * (Destroys the instance of player).
     */
    virtual ~Player() = default;

    /*
     * Assignment operator of the Player class.
     * @param other - an existing instance of the class.
     *
     * @return
     *      A reference to an existing instance of the class (which points to the given instance other).
     */
    Player& operator=(const Player& other) = default;

    /*
     *  levelUp upgrades the level of the player, until level 10.
     */
    void levelUp();

    /*
     * buff increases the number of force points by  forcePointsAddition.
     *
     * @param forcePointsAddition - the number of new points the player earned.
     *
     */
    void buff(int forcePointsAddition);

    /*
     * heal increases the number of health points of the player by healthPointsAddition, until the maximal number
     * of health points that the player can have (maxHP).
     *
     * @param healthPointsAddition - the number of new health points that the player earned.
     *
     */
    virtual void heal(int healthPointsAddition);

    /*
     * damage decreases the number of health points of the player, by healthPointsLoss, until 0.
     *
     * @param healthPointsLoss - the number of points that the player lost.
     *
     */
    void damage(int healthPointsLoss);

    /*
     * isKnockedOut checks if the number of health points of the player reached to 0.
     *
     * @return
     *      true - if the number health points of the player reached to 0, or false - otherwise.
     */
    bool isKnockedOut() const;

    /*
     * isWin checks if the level of the player reached to 0.
     *
     * @return
     *      true - if the number health points of the player reached to 0, or false - otherwise.
     */
    bool isWon() const;

    /*
     * addCoins adds coinsAddition coins to the total number of coins that the player has.
     *
     * @param coinsAddition - the number of new coins that the player earned.
     */
    virtual void addCoins(int coinsAddition);

    /*
     * pay decreases the number of coins that the player has by payment.
     * In case that there are not enough coins, the total number of coins will remain as it is.
     *
     * @param payment - the number of coins that the player payed.
     *
     * @return
     *      true - if the payment was successful or false - otherwise.
     */
    bool pay(int payment);

    /*
     * getAttackStrength returns the attack strength (force + level).
     *
     * @return
     *      the attack strength of the player.
     */
    virtual int getAttackStrength() const;

    /*
     * getLevel returns the level of the player.
     *
     * @return
     *      the level of the player.
     */
    int getLevel() const;

    /**
     *
     * @return the name of the player
     */
    string getName() const;

    /**
     *
     * @return the force of the player
     */
    int getForce() const;

    /**
     *
     * @return the health points of the player
     */
    int getHealthPoints() const;

    /**
     *
     * @return the coins of the player
     */
    int getCoins() const;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    static const int MAX_NAME_SIZE = 15; //TODO: MOVE TO PRIVATE?

    /**
     * Decreases the force in 1
     */
    void LossForcePoint();
protected:
    virtual std::ostream &printPlayerInfo(std::ostream &os) const=0;

private:
    string m_name;
    int m_level;
    int m_force;
    int m_healthPoints;
    int m_coins;

    static const int INITIAL_LEVEL = 1;
    static const int MAX_LEVEL = 10;
    static const int INITIAL_COINS = 10;
    static const int INITIAL_FORCE = 5;
    static const int MAX_HEALTH_POINTS = 100;
    static const int MIN_HEALTH_POINTS = 0;
};

/**
 * @param name - The name of the player.
 * The name must contain only letters in english without spaces, the maximum letters allowed is 15
 * @return true if the name meets the conditions, otherwise false
 */
bool isValidName(const string& name);


#endif //EX4_PLAYER_H
