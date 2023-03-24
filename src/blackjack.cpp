#include "../header/blackjack.h"
#include "../header/card.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

Blackjack::Blackjack(){
    printRules();
}

Blackjack::~Blackjack(){
    for (int i = 0; i < 25; i++){
        delete playerHand[i];
    }
}

bool Blackjack::startGame(){
    char userInput;
    bool turnOver = false;
    while (!turnOver){
        cout << "Hit or stand? (h or s): ";
        cin >> userInput;
        if (userInput == 'h' || userInput == 'H'){ //hit
            hit();
            cout << "You pulled: " << playerHand[numCards-1]->getValueString() << " of " << playerHand[numCards-1]->getSuit() << endl;
            cout << "Total: " << playerTotal << endl;
            if (playerTotal > 21){
                cout << "BUST! YOU LOSE!" << endl;
                turnOver = true;
                int tempUserInput;
                bool exit = false;
                cout << "Press 0 to return main menu" << endl;
                while (!exit){
                    cin >> tempUserInput;
                    if (tempUserInput == 0){
                        exit = true;
                    }
                }
                return false;
            }
        }
        else if (userInput == 's' || userInput == 'S'){ //stand
            bool won = false;
            stand();
            turnOver = true;
            cout << "Enemy's Total: " << enemyTotal << endl;
            if (enemyTotal >= 21){
                cout << "Enemy busted! You win!" << endl;
            }
            else if (enemyTotal > playerTotal){
                cout << "Enemy won!" << endl;
            }
            else if (enemyTotal < playerTotal){
                cout << "You won!" << endl;
                won = true;
            }
            else{
                cout << "Draw!" << endl;
            }
            int tempUserInput;
            bool exit = false;
            cout << "Press 0 to return main menu" << endl;
            while (!exit){
                cin >> tempUserInput;
                if (tempUserInput == 0){
                    exit = true;
                }
            }
            return won;
        }
        else if (userInput == 'q' || userInput == 'Q'){ //just for dev purposes
            turnOver = true;
            return false;
        }
        else{
            cout << "Invalid input" << endl;
        }
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return false;
}

const void Blackjack::printRules(){
    //print out RULES in ASCII
    cout << "██████  ██    ██ ██      ███████ ███████ " << endl;
    cout << "██   ██ ██    ██ ██      ██      ██      " << endl;
    cout << "██████  ██    ██ ██      █████   ███████ " << endl;
    cout << "██   ██ ██    ██ ██      ██           ██ " << endl;
    cout << "██   ██  ██████  ███████ ███████ ███████ " << endl;

    cout << endl << "In this version of blackjack, the player can either hit or stand." << endl;
    cout << "Hit: Take another card." << endl;
    cout << "Stand: Take no more cards." << endl;
    cout << "The goal? Try to get the highest total value of cards," << endl;
    cout << "but if you hit a total of 21 or more, you \"burst\"," << endl;
    cout << "and you lose the match." << endl;
    cout << "An ace counts as 11, unless it will cause a burst, in which case it will count as 1." << endl;
    cout << "And face cards will count as 10." << endl << endl;
}

const void Blackjack::print(){
    //turns out we didn't need this...
}

void Blackjack::hit(){
    Card *newCard = new Card(playerTotal);
    while (uniqueCard(newCard)){
        delete newCard;
        newCard = new Card(playerTotal);
    }
    playerHand[numCards] = newCard;
    playerTotal += newCard->getValueInt(); //do not check if we bust yet
    numCards++;
}

void Blackjack::stand(){ //forced to stand if you bust
    //here we calculate the enemy's hand...
    Card *newCard = new Card(playerTotal);
    while (enemyTotal <= 15){
        while (uniqueCard(newCard)){
            delete newCard;
            newCard = new Card(playerTotal);
        }
        enemyTotal += newCard->getValueInt();
    }
}

bool Blackjack::uniqueCard(Card* newCard){
    bool match = false;
    for (int i = 0; i < numCards; i++){
        if ((newCard->getSuit() == playerHand[i]->getSuit()) && 
        (newCard->getValueString() == playerHand[i]->getValueString())){
            match = true;
        }
    }
    return match;
}

int Blackjack::getPlayerTotal(){
    return playerTotal;
}