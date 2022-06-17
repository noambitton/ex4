//
// Created by User on 09/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H


#include <string>
#include "Players/Player.h"
using std::string;

class Wizard : public Player{
public:
    /*
    * C'tor of Wizard class.
     *
     * @param name - The name of the wizard (that is type of player).
     * The name must contain only letters in english without spaces, the maximum letters allowed is 15
     * otherwise an InvalidPlayerName exception will be thrown
     * @return
     *      A new instance of Wizard.
    */
    explicit Wizard(const string& name);

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    /*
     * Copy C'tor of Wizard class.
     *
     * @param other - An existing instance of the class.
     *
     * @return
     *      A new instance of Wizard (which is a copy of the given instance).
     */
    Wizard(const Wizard& other) = default;

    Player* clone() const override;

    /*
     * D'tor of Wizard class.
     *
     * (Destroys the instance of Wizard).
     */
    ~Wizard() override = default;

    /*
     * Assignment operator of the Wizard class.
     * @param other - an existing instance of the class.
     *
     * @return
     *      A reference to an existing instance of the class (which points to the given instance other).
     */
    Wizard& operator=(const Wizard& other) = default;

    /*
     * heal increases the number of health points of the player by healthPointsAddition, until the maximal number
     * of health points that the player can have (maxHP).
     *
     * @param healthPointsAddition - the number of new health points that the player earned.
     *
     */
    void heal(int healthPointsAddition) override;

private:
    const string JOB= "Wizard";

    /**
     * function that prints the wizrd information
     * This function is used in the operator << of player
     * @param os input channel
     * @return
     */
    std::ostream &printPlayerInfo(std::ostream& os) const override;
};

#endif //EX4_WIZARD_H



