#include "../header/card.h"
#include "../header/blackjack.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include<ctime>

using namespace std;

Card::Card(int playerTotal){
    srand(time(0));
    int suitInt = rand() % 4;
    switch (suitInt){
        case 0:
            suit = "Clubs";
            break;
        case 1:
            suit = "Diamonds";
            break;
        case 2:
            suit = "Hearts";
            break;
        case 3:
            suit = "Spades";
            break;
    }
    valueInt = rand() % 13 + 1;
    switch (valueInt){
        case 1:
            valueString = "Ace";
            if (playerTotal + 11 >= 21){
                valueInt = 1;
            }
            else{
                valueInt = 11;
            }
            break;
        case 11:
            valueString = "Jack";
            valueInt = 10;
            break;
        case 12:
            valueString = "Queen";
            valueInt = 10;
            break;
        case 13:
            valueString = "King";
            valueInt = 10;
            break;
        default:
            valueString = to_string(valueInt);
            break;
    }
}

const string Card::getSuit(){
    return suit;
}

const string Card::getValueString(){
    return valueString;
}

const int Card::getValueInt(){
    return valueInt;
}