#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "../header/minigames.h"
#include "../header/card.h"

using namespace std;

class Blackjack : public Minigames{
    public:
        Blackjack(); //constructor
        ~Blackjack(); //deconstructor
        bool startGame(); //start game
        int getPlayerTotal();
        void hit();
        void stand();
    private:
        const void print(); //print hands
        const void printRules(); //printrules
        int playerTotal = 0;
        int enemyTotal = 0;
        Card *playerHand[25];
        int numCards = 0; //num of cards
        bool uniqueCard(Card*);
};

#endif