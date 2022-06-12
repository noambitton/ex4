//
// Created by User on 10/06/2022.
//

#ifndef PLAYERTRAIL_MTMCHKIN_H
#define PLAYERTRAIL_MTMCHKIN_H

#include <memory>
#include "Card.h"
#include "Players/Player.h"
#include <queue>
#include <deque>
#include <vector>
using std::queue;
using std::deque;
using std::unique_ptr;
using std::string;
using std::vector;

class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param cardsFileName - name of a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string& cardsFileName);

    /*
     * Copy C'tor of Mtmchkin class.
     *
     * @param other - An existing instance of the class.
     *
     * @return
     *      A new instance of Mtmchkin (which is a copy of the given instance).
     */
    Mtmchkin(const Mtmchkin& other) = delete;

    /*
     * Assignment operator of the Mtmchkin class.
     * @param other - an existing instance of the class.
     *
     * @return
     *      A reference to an existing instance of the class (which points to the given instance other).
     */
    Mtmchkin& operator=(const Mtmchkin& other) = delete;

    /**
     * D'tor of Mtmchkin
     */
    ~Mtmchkin() = default;

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::queue<unique_ptr<Card>> m_cardsDeck;
    deque<unique_ptr<Player>> m_PlayerTurnBoard;
    deque<unique_ptr<Player>> m_winners;
    deque<unique_ptr<Player>> m_losers;
    int m_rounds;
    static const int MIN_TEAM_SIZE = 2;
    static const int MAX_TEAM_SIZE = 6;
    static const int MIN_DECK_SIZE = 5;
    static const int VALID_NUMBER_OF_PLAYER_ARGS = 2;
    static const char SPACE = ' ';
    static const char END_OF_LINE = '\0';

    void receivePlayers(int teamSize);
    static int receiveTeamSize();
    static unique_ptr<Player> buildPlayer();
    void checkPlayerStatus(unique_ptr<Player> currentPlayer);
    static vector<string> seperateStringToWords(const string& line);
};


#endif //PLAYERTRAIL_MTMCHKIN_H
