#include "Mtmchkin.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Exception.h"
#include "Card.h"
#include "utilities.h"

#include <queue>
#include <fstream>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <cstring>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::endl;
using std::queue;
using std::unique_ptr;
using std::vector;
using std::map;
using std::deque;
using std::stringstream;
using std::istringstream;



/**
 * A template for creating new Instance of Card depending on the card type
 * Used for "converting" a string to a class Instance
 * @tparam T class type (type of card)
 * @return a new instance of card
 */
template < typename T> Card * createInstance()
{
    return new T();
}
typedef std::map<std::string, Card* (*)()> cardMapType;


Mtmchkin::Mtmchkin(const std::string& cardsFileName) : m_rounds(0){
    ifstream cardsFile(cardsFileName);
    if (!cardsFile) {
        throw DeckFileNotFound();
    }
    string cardName;
    int errorLine = 1;
    cardMapType cardsTypesMap{ {"Card", &createInstance<Card>}, }; //TODO: ADD OPTIONS
    while (getline(cardsFile, cardName)) {
        if (cardsTypesMap.find(cardName) == cardsTypesMap.end()) {
            throw DeckFileFormatError(errorLine);
        }
        m_cardsDeck.push(unique_ptr<Card>(cardsTypesMap[cardName]()));
        errorLine++;
    }
    if(m_cardsDeck.size() < MIN_DECK_SIZE){
        throw DeckFileInvalidSize();
    }
    printStartGameMessage();
    int teamSize = receiveTeamSize();
    receivePlayers(teamSize);
}

int Mtmchkin::receiveTeamSize() {
    int teamSize;
    string input;
    while (true) {
        printEnterTeamSizeMessage();
        getline(std::cin, input);
        try{
            teamSize = stoi(input);
        }
        catch(std::invalid_argument const&){
            printInvalidInput();
            continue;
        }
        if(teamSize > MAX_TEAM_SIZE || teamSize < MIN_TEAM_SIZE){
            printInvalidTeamSize();
        }
        else{
            break;
        }
    }
    return teamSize;
}

void Mtmchkin::receivePlayers(int teamSize) {
    for (int i = 0; i < teamSize; i++) {
        unique_ptr<Player> player = buildPlayer();
        cout << *player << endl;
        m_PlayerTurnBoard.push_back(std::move(player));
    }

}

/**
 * A template for creating new Instance of Player depending on the player type- Wizard, Fighter or Rogue
 * Used for "converting" a string to a class Instance
 * @tparam T class type (type of player)
 * @param name name of the player, required for all players' types
 * @return a new instance of player
 */
template < typename T> Player * createInstance(string& name)
{
    return new T(name);
}
typedef std::map<std::string, Player* (*)(string& name)> playerMapType;

unique_ptr<Player> Mtmchkin::buildPlayer() {
    string name, classType, input;
    bool isValidArgs = false;
    playerMapType playerTypesMap{ {"Wizard", &createInstance<Wizard>}, {"Fighter", &createInstance<Fighter>},
                                  {"Rogue", &createInstance<Rogue>}, };
    while (!isValidArgs) {
        printInsertPlayerMessage();
        getline(cin, input);
        vector<string> wordsInLine = seperateStringToWords(input);
        if(wordsInLine.size() != VALID_NUMBER_OF_PLAYER_ARGS){
            printInvalidInput();
        }
        else{
            name = wordsInLine[0];
            classType = wordsInLine[1];
            if (!isValidName(name)) {
                printInvalidName();
            }
            else if (playerTypesMap.find(classType) == playerTypesMap.end()){
                printInvalidClass();
            }
            else {
                isValidArgs = true;
            }
        }
    }
    return unique_ptr<Player>(playerTypesMap[classType](name));
}

void Mtmchkin::playRound() {
    printRoundStartMessage(m_rounds+1);
    int currentPlayersNumber = m_PlayerTurnBoard.size();
    for(int i=0; i<currentPlayersNumber; i++){
        printTurnStartMessage( m_PlayerTurnBoard.front()->getName());
        unique_ptr<Card> currentCard = std::move(m_cardsDeck.front());
        m_cardsDeck.pop();
        currentCard->encounter();
        m_cardsDeck.push(std::move(currentCard));
        checkPlayerStatus(std::move(m_PlayerTurnBoard.front()));
    }
    m_rounds++;
}

void Mtmchkin::checkPlayerStatus(unique_ptr<Player> currentPlayer)
{
    if(currentPlayer->isKnockedOut()){
        m_losers.push_back(std::move(currentPlayer));
    }
    else if(currentPlayer->isWon()){
        m_winners.push_back(std::move(currentPlayer));
    }
    else{
        m_PlayerTurnBoard.push_back(std::move(currentPlayer));
    }
    m_PlayerTurnBoard.pop_front();
}

void Mtmchkin::printLeaderBoard() const
{
    int ranking=1;
    printLeaderBoardStartMessage();
    for (deque<unique_ptr<Player>>::const_iterator iterator = m_winners.begin(); iterator != m_winners.end();
         ++iterator){
        printPlayerLeaderBoard(ranking, **iterator);
        ranking++;
    }

    for (deque<unique_ptr<Player>>::const_iterator iterator = m_PlayerTurnBoard.begin();
         iterator != m_PlayerTurnBoard.end();
         ++iterator){
        printPlayerLeaderBoard(ranking, **iterator);
        ranking++;
    }

    for (std::reverse_iterator<deque<unique_ptr<Player>>::const_iterator> iterator = m_losers.rbegin();
         iterator != m_losers.rend();
         ++iterator){
        printPlayerLeaderBoard(ranking, **iterator);
        ranking++;
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return m_rounds;
}

bool Mtmchkin::isGameOver() const {
    return m_PlayerTurnBoard.empty();
}

vector<string> Mtmchkin::seperateStringToWords(const string &line) {
    vector<string> words{};

    stringstream sstream(line);
    string word;
    while (std::getline(sstream, word, SPACE)){
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }
    return words;
}







