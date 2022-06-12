#include "Player.h"


#include <algorithm>
#include "Exception.h"
using std::string;
using std::string;
using std::ostream;

/*
 * isValidName checks if the name contains only English letters.
 *
 * @param name - The name to be checked.
 *
 * @return
 *      true - if the name contains only English letters, or false - otherwise.
 */
Player::Player(const string& name) : m_name(name), m_level(INITIAL_LEVEL), m_force(INITIAL_FORCE),
                                     m_healthPoints(MAX_HEALTH_POINTS), m_coins(INITIAL_COINS)
{
    if (!isValidName(name)){
        throw InvalidPlayerName();
    }
}

void Player::levelUp()
{
    if (m_level < MAX_LEVEL){
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int forcePointsAddition)
{
    if (forcePointsAddition > 0){
        m_force += forcePointsAddition;
    }
}

void Player::heal(int healthPointsAddition)
{
    if (healthPointsAddition > 0){
        m_healthPoints += healthPointsAddition;
    }
    if (m_healthPoints > MAX_HEALTH_POINTS){
        m_healthPoints = MAX_HEALTH_POINTS;
    }
}

void Player::damage(int healthPointsLoss)
{
    if (healthPointsLoss > 0){
        m_healthPoints -= healthPointsLoss;
    }
    if (m_healthPoints < 0){
        m_healthPoints = MIN_HEALTH_POINTS;
    }
}

bool Player::isKnockedOut() const
{
    return (m_healthPoints == MIN_HEALTH_POINTS);
}

void Player::addCoins(int coinsAddition)
{
    if (coinsAddition > 0){
        m_coins += coinsAddition;
    }
}

bool Player::pay(int payment)
{
    if (payment > 0){
        if (m_coins >= payment){
            m_coins -= payment;
            return true;
        }
        return false;
    }
    return true;
}

int Player::getAttackStrength() const
{
    return (m_force + m_level);
}


string Player::getName() const {
    return m_name;
}

bool isValidName(const string &name) {
    return (name.size() <= Player::MAX_NAME_SIZE) && (std::all_of(name.begin(), name.end(),
                                                                  [](char const &c) {
                                                                      return std::isalpha(c);}));
}


std::ostream &operator<<(ostream &os, const Player &player) {
    return player.printPlayerInfo(os);
}

bool Player::isWon() const {
    return m_level == MAX_LEVEL;
}
