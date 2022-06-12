#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H


#include <string>
#include "Player.h"
using std::string;

class Fighter : public Player{
public:
    /*
    * C'tor of Fighter class.
     *
     * @param name - The name of the wizard (that is type of player).
     * The name must contain only letters in english without spaces, the maximum letters allowed is 15
     * otherwise an InvalidPlayerName exception will be thrown
     * @return
     *      A new instance of Fighter.
    */
    explicit Fighter(const string& name);

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    /*
     * Copy C'tor of Fighter class.
     *
     * @param other - An existing instance of the class.
     *
     * @return
     *      A new instance of Fighter (which is a copy of the given instance).
     */
    Fighter(const Fighter& other) = default;

    Player* clone() const override;

    /*
     * D'tor of Fighter class.
     *
     * (Destroys the instance of Fighter).
     */
    ~Fighter() override = default;

    /*
     * Assignment operator of the Fighter class.
     * @param other - an existing instance of the class.
     *
     * @return
     *      A reference to an existing instance of the class (which points to the given instance other).
     */
    Fighter& operator=(const Fighter& other) = default;

    /*
     * getAttackStrength returns the attack strength (force + level).
     *
     * @return
     *      the attack strength of the player.
     */
    int getAttackStrength() const override;

private:
    string m_job = "Fighter";
    std::ostream &printPlayerInfo(std::ostream &os) const override;
};

#endif //EX4_FIGHTER_H
