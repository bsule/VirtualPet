#include <iostream>
#include <ctime>
#include <string>
#include "../header/rockpaperscissors.h"

using namespace std;


RockPaperScissors::RockPaperScissors() {
    playerScore = 0;
    botScore = 0;
    playerChoice = 0;
    botChoice = 0;
    
}

const void RockPaperScissors::print() {

}

const void RockPaperScissors::printRules() {
    cout << "Welcome to Rock Paper Scissors!" << endl;
    cout << "In this game of luck you will be choosing between Rock, Paper, and Scissors." << endl;
    cout << "You will be competing against a bot who will also choose an option between these three." << endl;
    cout << "When both of you have chosen, yours and the bot's choices will be revealed at the same time to see who wins the point" << endl;
    cout << "The rules are simple:" << endl;
    cout << dashes << endl;
    cout << "Rock beats Scissors" << endl;
    cout << "Scissors beats Paper" << endl;
    cout << "Paper beats Rock" << endl;
    cout << dashes << endl;
    cout << "However, two identical options will result in a tie!" << endl;
    cout << "For example, Rock can't beat Rock, Paper can't beat Paper, and Scissors can't beat Scissors!" << endl;
    cout << "The first to get to the max amount of points wins!" << endl << endl;
}


int RockPaperScissors::getPlayerChoice() {
    int choice;
    cout << "Enter your choice: 1(Rock), 2(Paper), or 3(Scissors)" << endl;
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 3)
    {
        clearText();
        cout << "Wrong input! Choices are 1, 2, or 3!" << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
    }
    return choice;


}

void RockPaperScissors::printScore() {
    cout << "Score is " << playerScore << "-" << botScore << endl;
    if (playerScore > botScore)
    {
        cout << "You are winning!" << endl;
    }
    else if (playerScore < botScore)
    {
        cout << "You are losing!" << endl;
    }
    else if (playerScore + botScore > 0)
    {
        cout << "Tie!" << endl;
    }
}

int RockPaperScissors::getBotChoice() {
    srand(time(0));
    int choice = (rand() % 3) + 1;
    return choice;
}

string RockPaperScissors::getChoiceText(int choice) {
    string choiceText;
    if (choice == 1)
    {
        choiceText = "Rock";
    }
    else if (choice == 2)
    {
        choiceText = "Paper";
    }
    else 
    {
        choiceText = "Scissors";
    }
    return choiceText;
}

void RockPaperScissors::compareChoices() {
    clearText();
    string player = getChoiceText(playerChoice);
    string bot = getChoiceText(botChoice);

    cout << "You chose: \"" << player << "\"" << endl;
    cout << "Your opponent chose: \"" << bot << "\"" << endl;
    

    if (playerChoice == botChoice)
    {
        cout << "It's a tie!" << endl;
    }
    else if (playerChoice == 1 && botChoice == 2 ||
             playerChoice == 2 && botChoice == 3 ||
             playerChoice == 3 && botChoice == 1)
    {
        cout << "You lose!" << endl;
        ++botScore;
    }
    else if (playerChoice == 2 && botChoice == 1 ||
             playerChoice == 3 && botChoice == 2 ||
             playerChoice == 1 && botChoice == 3)
    {
        cout << "You win!" << endl;
        ++playerScore;
    }


}
void RockPaperScissors::printFinalScore() {
    cout << "The final score is " << playerScore << "-" << botScore << endl;
    if (playerScore > botScore)
    {
        cout << "You won!" << endl;
        return_value = 10;
    }
    else if (playerScore < botScore)
    {
        cout << "You lost!" << endl;
    }
}
int RockPaperScissors::startGame() {
    printRules();
    cout << "How many points would you like to play up to?" << endl;
    cout << "Options are 3, 5, or 10 rounds." << endl;
    cin >> maxPoints;
    while (cin.fail() || maxPoints != 3 && maxPoints != 5 && maxPoints != 10)
    {
        clearText();
        cout << "Please enter a valid amount of points." << endl;
        cout << "Options are 3, 5, or 10 rounds." << endl;
        cin.clear();
        cin.ignore();
        cin >> maxPoints;
    }
    while (playerScore != maxPoints && botScore != maxPoints) {
        printScore();
        playerChoice = getPlayerChoice();
        botChoice = getBotChoice();
        compareChoices();

    }
    printFinalScore();
    
    int userInput;
    bool exit = false;
    cout << "Press 0 to return to the main menu" << endl;
    cin.ignore(1);
    while(!exit){
        cin >> userInput;
        if (userInput == 0){
            exit = true;
        }
    }
    return_value *= maxPoints;
    return return_value;
}

void RockPaperScissors::clearText() {
    system("clear");
}