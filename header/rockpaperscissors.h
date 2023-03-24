#ifndef ROCKPAPERSCISSORS_HPP
#define ROCKPAPERSCISSORS_HPP
#include "../header/minigames.h"
#include <string>

using namespace std;

class RockPaperScissors : public Minigames {
 public:
    RockPaperScissors();
    const void print();
    const void printRules();  
    int startGame();
    int getPlayerChoice();
    void printScore();
    void printFinalScore();
    void clearText();
 private: 
    int return_value = 0; //for experience points...
    int playerScore;  
    int botScore;
    int playerChoice;
    int botChoice;
    int getBotChoice();
    void compareChoices();
    string getChoiceText(int choice);
    string dashes = "----------------------------";
    int maxPoints;




};



#endif