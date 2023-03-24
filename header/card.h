#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

using namespace std;

class Card{
    private:
        string suit;
        string valueString;
        int valueInt;
    public:
        Card(int); //Constructor (generate random card)
        const string getSuit();
        const int getValueInt();
        const string getValueString();
};

#endif