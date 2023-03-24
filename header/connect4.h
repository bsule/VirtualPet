#ifndef CONNECT4_HPP
#define CONNECT4_HPP

#include "../header/minigames.h"
#include <string>

using namespace std;

class Connect4 : public Minigames{
    public:
        enum DiscOption {EMPTY, WHITE, BLACK};
        enum Turn {USER, BOT};
    private:
        string White = "\u25CF"; // ●
        string Black = "\u25CB"; // ○
        string Empty = " ";
        int userInput = -1;
        int botInput; // random input column
        Turn currentTurn = Turn::USER;
        DiscOption grid[6][7];
        bool isValidColumn(int); // check if specified column has space.
        bool isEmpty(int,int); // check if specified location is empty.
        const void print();  // print grid
        const void printRules(); // print rules
        void clearText(); // clears the terminal
        void promptUser(); // prompt user for column input and check for input validity
        bool checkWin(); // check for win by either player
        void placeInColumn(); // place disc in specified user input - 1 column.
        bool playerWon;
    public:
        Connect4(); // constructor
        bool startGame(); // start game loop until winner or draw
};

#endif