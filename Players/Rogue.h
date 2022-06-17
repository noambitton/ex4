//
// Created by User on 09/06/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H


#include <string>
#include "Player.h"
using std::string;

class Rogue : public Player{
public:
    /*
    * C'tor of Rogue class.
     *
     * @param name - The name of the wizard (that is type of player).
     * The name must contain only letters in english without spaces, the maximum letters allowed is 15
     * otherwise an InvalidPlayerName exception will be thrown
     * @return
     *      A new instance of Rogue.
    */
    explicit Rogue(const string& name);

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    /*
     * Copy C'tor of Rogue class.
     *
     * @param other - An existing instance of the class.
     *
     * @return
     *      A new instance of Rogue (which is a copy of the given instance).
     */
    Rogue(const Rogue& other) = default;

    Player* clone() const override;
    /*
     * D'tor of Rogue class.
     *
     * (Destroys the instance of Rogue).
     */
    ~Rogue() override = default;

    /*
     * Assignment operator of the Rogue class.
     * @param other - an existing instance of the class.
     *
     * @return
     *      A reference to an existing instance of the class (which points to the given instance other).
     */
    Rogue& operator=(const Rogue& other) = default;

    /*
     * addCoins adds coinsAddition coins to the total number of coins that the player has.
     *
     * @param coinsAddition - the number of new coins that the player earned.
     */
    void addCoins(int coinsAddition) override;

private:
    const string JOB = "Rogue";

    std::ostream &printPlayerInfo(std::ostream &os) const override;
};

#endif //EX4_ROGUE_H
