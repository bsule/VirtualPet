#include "../header/connect4.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Connect4::Connect4(){
    for (unsigned i = 0; i < 6; i++) // row loop
    {
        for (unsigned j = 0; j < 7; j++) // column loop
        {
            grid[i][j] = DiscOption::EMPTY;
        }
    }
}

bool Connect4::isValidColumn(int column){
    if (grid[0][column] == DiscOption::EMPTY) return true;
    return false;
}

bool Connect4::isEmpty(int row, int column){
    if (grid[row][column] == DiscOption::EMPTY){
        return true;
    }
    return false;
}

const void Connect4::print(){
    for (unsigned i = 0; i < 6; i++) // row loop
    {
        cout << "| ";
        for (unsigned j = 0; j < 7; j++) // column loop
        {
            if (grid[i][j] == 0){
                cout << Empty;
            }
            else if (grid[i][j] == 1){
                cout << White;
            }
            else if (grid[i][j] == 2){
                cout << Black;
            }
            cout << " ";
        }
        cout << '|' << endl;
    }
    cout << "_________________" << endl;
}

const void Connect4::printRules(){
    cout << "Connect 4 Rules:" << endl;
    cout << "Take turns against an AI placing their color disc in a column that is not full." << endl;
    cout << "A player wins by connecting 4 discs of the same color either horizontally, vertically, or diagonally." << endl;
    cout << "A draw occurs when all columns and filled and neither player connected 4 discs." << endl;
}

void Connect4::clearText(){
    system("clear");
}

void Connect4::promptUser(){
    while (userInput < 1 || !isValidColumn(userInput - 1) || userInput > 7){
        cout << "Enter a valid column to place a disc in: ";
        cin >> userInput;
        cout << endl;
        cin.clear();
        cin.ignore();
    }
}

bool Connect4::checkWin(){
    // Horizontal Check 
    for (unsigned i = 0; i < 6; i++) // row loop
    {
        for (unsigned j = 0; j < 4; j++) // column loop
        {
            if(grid[i][j] == DiscOption::WHITE && grid[i][j + 1] == DiscOption::WHITE
             && grid[i][j + 2] == DiscOption::WHITE && grid[i][j + 3] == DiscOption::WHITE){
                cout << "Player Wins!" << endl;
                playerWon = true;
                return true;
            }
            else if(grid[i][j] == DiscOption::BLACK && grid[i][j + 1] == DiscOption::BLACK
             && grid[i][j + 2] == DiscOption::BLACK && grid[i][j + 3] == DiscOption::BLACK){
                cout << "Computer Wins!" << endl;
                playerWon = false;
                return true;
            }
        }   
    }

    // Vertical Check
    for (unsigned i = 0; i < 3; i++) // row loop
    {
        for (unsigned j = 0; j < 7; j++) // column loop
        {
            if(grid[i][j] == DiscOption::WHITE && grid[i + 1][j] == DiscOption::WHITE
             && grid[i + 2][j] == DiscOption::WHITE && grid[i + 3][j] == DiscOption::WHITE){
                cout << "Player Wins!" << endl;
                playerWon = true;
                return true;
            }
            else if(grid[i][j] == DiscOption::BLACK && grid[i + 1][j] == DiscOption::BLACK
             && grid[i + 2][j] == DiscOption::BLACK && grid[i + 3][j] == DiscOption::BLACK){
                cout << "Computer Wins!" << endl;
                playerWon = false;
                return true;
            }
        }
    }

    // Diagonal Down and Right Check
    for (unsigned i = 0; i < 3; i++)
    {
        for (unsigned j = 0; j < 7; j++)
        {
            if(grid[i][j] == DiscOption::WHITE && grid[i + 1][j + 1] == DiscOption::WHITE
             && grid[i + 2][j + 2] == DiscOption::WHITE && grid[i + 3][j + 3] == DiscOption::WHITE){
                cout << "Player Wins!" << endl;
                playerWon = true;
                return true;
            }
            else if(grid[i][j] == DiscOption::BLACK && grid[i + 1][j + 1] == DiscOption::BLACK
             && grid[i + 2][j + 2] == DiscOption::BLACK && grid[i + 3][j + 3] == DiscOption::BLACK){
                cout << "Computer Wins!" << endl;
                playerWon = false;
                return true;
            }
        }
        
    }
    
    // Diagonal Up and Right Check
    for (unsigned i = 5; i > 2; i--)
    {
        for (unsigned j = 0; j < 7; j++)
        {
            if(grid[i][j] == DiscOption::WHITE && grid[i - 1][j + 1] == DiscOption::WHITE
             && grid[i - 2][j + 2] == DiscOption::WHITE && grid[i - 3][j + 3] == DiscOption::WHITE){
                cout << "Player Wins!" << endl;
                playerWon = true;
                return true;
            }
            else if(grid[i][j] == DiscOption::BLACK && grid[i - 1][j + 1] == DiscOption::BLACK
             && grid[i - 2][j + 2] == DiscOption::BLACK && grid[i - 3][j + 3] == DiscOption::BLACK){
                cout << "Computer Wins!" << endl;
                playerWon = false;
                return true;
            }
        }
        
    }
    bool isDraw = true;
    for (unsigned i = 0; i < 7; i++)
    {
        if (isValidColumn(i)){
            isDraw = false;
            break;
        }
    }
    if (isDraw){
        cout << "Draw!" << endl;
        playerWon = false;
    }
    return isDraw;
}

void Connect4::placeInColumn(){
    if(currentTurn == Turn::USER){
        for (unsigned i = 5; i >= 0; i--){
            if (isEmpty(i, userInput - 1)){
                grid[i][userInput - 1] = DiscOption::WHITE;
                userInput = -1;
                currentTurn = Turn::BOT;
                break;
            }
        }
    }
    else{
        botInput = rand() % 7;
        while (!isValidColumn(botInput)) botInput = rand() % 7;
        for (unsigned i = 5; i >= 0; i--){
            if (isEmpty(i, botInput)){
                grid[i][botInput] = DiscOption::BLACK;
                botInput = rand() % 7;
                currentTurn = Turn::USER;
                break;
            }
        }
    }
}

bool Connect4::startGame(){
    clearText();
    while (!checkWin()){
        printRules();
        print();
        promptUser();
        placeInColumn();
        print();
        placeInColumn();
        clearText();
    }
    cout << endl;
    print();
    int userInput;
    bool exit = false;
    cout << "Press 0 to return to the main menu" << endl;
    while(!exit){
        cin >> userInput;
        if (userInput == 0){
            exit = true;
        }
    }
    return playerWon;
}