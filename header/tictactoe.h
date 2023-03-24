#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "../header/minigames.h"

using namespace std;

class TicTacToe : public Minigames{
 private:
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
	char inputBoard[3][3] = {{'1', '2', '3'},
                        	 {'4', '5', '6'},
                        	 {'7', '8', '9'}};
    const char tUser = 'X';
    const char tComputer = 'o';
    bool whoStart = false; // if false computer starts
	string winner = "Tie"; // takes strings "User" "Tie" or "Computer"
	bool complete = false; // sees if game is completed

    void showBoard(); // shows the board
    void whoStarts(); // chooses at random who starts
	void checkWinner(); // sees if someone won
	void userMove(); // prints that its the turn of the user and uses boardforusermove
	void boardForUserMove(); // prints the input board
	bool legalMove(int move); // sees if the user can move to the location they chose
	void computerMove(); // sees if the computer can win, if not then sees if it can block the user from winning, 
                         // if not then chooses a spot at random with computerMoveHelper
    void computerMoveHelper(); // chooses a spot at random for the computer
	bool noMove(); // sees if theres no moves on the board
	
 public:
    TicTacToe();
    const void print(); // prints the xp gained
    const void printRules();
    bool startGame(); // starts and completes the game
    void clearText();
};

#endif