#include <iostream>
#include <cmath>
#include <time.h>

#include "../header/tictactoe.h"

/* 
    When startGame() is called, printRules() will be called automatically and the game will begin.
    Either the computer or the user will start and it will be chosen at random. The user will always
    be 'X'. the board will be shown and the locations will be marked with a number and they input
    that number if they would like to go that location. If that location is taken or not valid, 
    the user will be prompted to input another location. Once they input a valid location, the 
    computer will choose a spot to input the 'o'. If the computer can win the game, it will place
    it so where the computer wins. If it cannot win, it will see if the user has a chance at winning
    and it will block it. If not, then it will choose a spot at random to place the 'o'. The game
    will end in a tie, the computer winning, or the user winning.
*/

TicTacToe::TicTacToe(){
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
}

const void TicTacToe::printRules(){
    cout << "██████  ██    ██ ██      ███████ ███████ " << endl;
    cout << "██   ██ ██    ██ ██      ██      ██      " << endl;
    cout << "██████  ██    ██ ██      █████   ███████ " << endl;
    cout << "██   ██ ██    ██ ██      ██           ██ " << endl;
    cout << "██   ██  ██████  ███████ ███████ ███████ " << endl;
    
    cout << endl << "In the TicTacToe gamemode, you will play against the computer to gain experience points." << endl;
    cout << "Either you or the computer will start and it will be chosen at random. When it is your turn," << endl;
    cout << "the board will be shown and you will be prompted to input a number on the board for the location" << endl;
    cout << "that you would like to select. If that spot is invalid, you will be asked to input another spot" << endl;
    cout << "When the game is complete, it will tell you who won (or if it was a draw) and you will see the" << endl;
    cout << "total amount of experience points you earned." << endl << endl;
}

const void TicTacToe::print(){ // print xp
    
}

void TicTacToe::clearText(){
    system("clear");
}

bool TicTacToe::startGame(){
    printRules();
    int move=0;
    whoStarts();
    if(whoStart==false){
        board[1][1]= tComputer;
    }
    while(complete==false){
        userMove();
        cin >> move;
        if(cin.fail()){
            move=0;
            cin.clear();
            cin.ignore(256,'\n');
        }
        while(move<1 || move>9){
            cout << endl << "You did not choose a valid location." << endl;
            userMove();
            cin >> move;
            if(cin.fail()){
                move=0;
                cin.clear();
                cin.ignore(256,'\n');
            }
        }
        while(legalMove(move)==false){
            cout << endl << "You did not choose a valid location." << endl;
            userMove();
            cin >> move;
            if(cin.fail()){
                move=0;
                cin.clear();
                cin.ignore(256,'\n');
            }
        }
        checkWinner();
        computerMove();
        checkWinner();
    }
    bool bool_win = false;
    if(winner=="User"){
        cout << "Congratulations, you won!" << endl;
        bool_win = true;
    }
    else if(winner=="Computer"){
        cout << "The computer won" << endl;
    }
    else{
        cout << "It was a tie" << endl;
    }

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
    return bool_win;
}

void TicTacToe::userMove(){
    cout << "Where would you like to move? (You are X)" << endl;
    boardForUserMove();
}

void TicTacToe::boardForUserMove(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=' '){
                inputBoard[i][j]=board[i][j];
            }
        }
    }
    cout << " " << inputBoard[0][0] << " | " << inputBoard[0][1] << " | " << inputBoard[0][2]<< " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << inputBoard[1][0] << " | " << inputBoard[1][1] << " | " << inputBoard[1][2]<< " "<< endl;
    cout << "---|---|---" << endl;
    cout << " " << inputBoard[2][0] << " | " << inputBoard[2][1] << " | " << inputBoard[2][2]<< " " << endl;
    cout << endl;
}


void TicTacToe::showBoard(){
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2]<< " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2]<< " "<< endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2]<< " " << endl;
    cout << endl;
}

void TicTacToe::checkWinner(){
    // horizontal
    if(board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X'){
        winner="User";
        complete=true;
    }
    else if(board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X'){
        winner="User";
        complete=true;
    }
    else if(board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X'){
        winner="User";
        complete=true;
    }
    // vertical
    else if(board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X'){
        winner="User";
        complete=true;
    }
    else if(board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X'){
        winner="User";
        complete=true;
    }
    else if(board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X'){
        winner="User";
        complete=true;
    }
    // diagnal
    else if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X'){
        winner="User";
        complete=true;
    }
    else if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X'){
        winner="User";
        complete=true;
    }

    // computer win
    if(board[0][0]==tComputer && board[0][1]==tComputer && board[0][2]==tComputer){
        winner="Computer";
        complete=true;
    }
    else if(board[1][0]==tComputer && board[1][1]==tComputer && board[1][2]==tComputer){
        winner="Computer";
        complete=true;
    }
    else if(board[2][0]==tComputer && board[2][1]==tComputer && board[2][2]==tComputer){
        winner="Computer";
        complete=true;
    }
    // vertical
    else if(board[0][0]==tComputer && board[1][0]==tComputer && board[2][0]==tComputer){
        winner="Computer";
        complete=true;
    }
    else if(board[0][1]==tComputer && board[1][1]==tComputer && board[2][1]==tComputer){
        winner="Computer";
        complete=true;
    }
    else if(board[0][2]==tComputer && board[1][2]==tComputer && board[2][2]==tComputer){
        winner="Computer";
        complete=true;
    }
    // diagnal
    else if(board[0][0]==tComputer && board[1][1]==tComputer && board[2][2]==tComputer){
        winner="Computer";
        complete=true;
    }
    else if(board[0][2]==tComputer && board[1][1]==tComputer && board[2][0]==tComputer){
        winner="Computer";
        complete=true;
    }
    

    // check if theres a move available
    if(noMove()==true){
        complete=true;
    }
    if(complete==true){
        showBoard();
    }
}

bool TicTacToe::noMove(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                return false;
            }
        }
    }
    return true;
}

void TicTacToe::whoStarts(){
    srand(time(0));
    int userORcomp = rand()%2+1; // one or two
    if(userORcomp==2){
        whoStart=true;
        cout << "You start!" << endl;
    }
    else{
        cout << "Computer starts." << endl;
    }
}

bool TicTacToe::legalMove(int move){
    if(move==1){
        if(board[0][0]!=' '){
            return false;
        }
        else{
            board[0][0]=tUser;
            return true;
        }
    }
    else if(move==2){
        if(board[0][1]!=' '){
            return false;
        }
        else{
            board[0][1]=tUser;
            return true;
        }
    }
    else if(move==3){
        if(board[0][2]!=' '){
            return false;
        }
        else{
            board[0][2]=tUser;
            return true;
        }
    }
    else if(move==4){
        if(board[1][0]!=' '){
            return false;
        }
        else{
            board[1][0]=tUser;
            return true;
        }
    }
    else if(move==5){
        if(board[1][1]!=' '){
            return false;
        }
        else{
            board[1][1]=tUser;
            return true;
        }
    }
    else if(move==6){
        if(board[1][2]!=' '){
            return false;
        }
        else{
            board[1][2]=tUser;
            return true;
        }
    }
    else if(move==7){
        if(board[2][0]!=' '){
            return false;
        }
        else{
            board[2][0]=tUser;
            return true;
        }
    }
    else if(move==8){
        if(board[2][1]!=' '){
            return false;
        }
        else{
            board[2][1]=tUser;
            return true;
        }
    }
    else if(move==9){
        if(board[2][2]!=' '){
            return false;
        }
        else{
            board[2][2]=tUser;
            return true;
        }
    }
    return false;
}

void TicTacToe::computerMove(){
    if(complete==true){
        return;
    }
    // check if the computer can win
    
    if(board[0][0]==tComputer && board[0][1]==tComputer && board[0][2]==' '&& board[0][2]!=tUser){
        board[0][2]=tComputer;
        return;
    }
    else if(board[0][0]==tComputer && board[0][2]==tComputer && board[0][1]==' '&& board[0][1]!=tUser){
        board[0][1]=tComputer;
        return;
    }
    else if(board[0][1]==tComputer && board[0][2]==tComputer && board[0][0]==' '&& board[0][0]!=tUser){
        board[0][0]=tComputer;
        return;
    }
    else if(board[1][0]==tComputer && board[1][1]==tComputer && board[1][2]==' '&& board[1][2]!=tUser){
        board[1][2]=tComputer;
        return;
    }
    else if(board[1][0]==tComputer && board[1][2]==tComputer && board[1][1]==' '&& board[1][1]!=tUser){
        board[1][1]=tComputer;
        return;
    }
    else if(board[1][1]==tComputer && board[1][2]==tComputer && board[1][0]==' '&& board[1][0]!=tUser){
        board[1][0]=tComputer;
        return;
    }
    else if(board[2][0]==tComputer && board[2][1]==tComputer && board[2][2]==' '&& board[2][2]!=tUser){
        board[2][2]=tComputer;
        return;
    }
    else if(board[2][0]==tComputer && board[2][2]==tComputer && board[2][1]==' '&& board[2][1]!=tUser){
        board[2][1]=tComputer;
        return;
    }
    else if(board[2][1]==tComputer && board[2][2]==tComputer && board[2][0]==' '&& board[2][0]!=tUser){
        board[2][0]=tComputer;
        return;
    }
    // vertical block
    else if(board[0][0]==tComputer && board[1][0]==tComputer && board[2][0]==' '&& board[2][0]!=tUser){
        board[2][0]=tComputer;
        return;
    }
    else if(board[0][0]==tComputer && board[2][0]==tComputer && board[1][0]==' '&& board[1][0]!=tUser){
        board[1][0]=tComputer;
        return;
    }
    else if(board[2][0]==tComputer && board[1][0]==tComputer && board[0][0]==' '&& board[0][0]!=tUser){
        board[0][0]=tComputer;
        return;
    }
    else if(board[0][1]==tComputer && board[1][1]==tComputer && board[2][1]==' '&& board[2][1]!=tUser){
        board[2][1]=tComputer;
        return;
    }
    else if(board[0][1]==tComputer && board[2][1]==tComputer && board[1][1]==' '&& board[1][1]!=tUser){
        board[1][1]=tComputer;
        return;
    }
    else if(board[2][1]==tComputer && board[1][1]==tComputer && board[0][1]==' '&& board[0][1]!=tUser){
        board[0][1]=tComputer;
        return;
    }
    else if(board[0][2]==tComputer && board[1][2]==tComputer && board[2][2]==' '&& board[2][2]!=tUser){
        board[2][2]=tComputer;
        return;
    }
    else if(board[0][2]==tComputer && board[2][2]==tComputer && board[1][2]==' '&& board[1][2]!=tUser){
        board[1][2]=tComputer;
        return;
    }
    else if(board[2][2]==tComputer && board[1][2]==tComputer && board[0][2]==' '&& board[0][2]!=tUser){
        board[0][2]=tComputer;
        return;
    }
    // diagnal block
    else if(board[0][0]==tComputer && board[1][1]==tComputer && board[2][2]==' '&& board[2][2]!=tUser){
        board[2][2]=tComputer;
        return;
    }
    else if(board[0][0]==tComputer && board[2][2]==tComputer && board[1][1]==' '&& board[1][1]!=tUser){
        board[1][1]=tComputer;
        return;
    }
    else if(board[2][2]==tComputer && board[1][1]==tComputer && board[0][0]==' '&& board[0][0]!=tUser){
        board[0][0]=tComputer;
        return;
    }
    else if(board[0][2]==tComputer && board[1][1]==tUser && board[2][0]!=' '&& board[2][0]!=tUser){
        board[2][0]=tComputer;
        return;
    }
    else if(board[0][2]==tComputer && board[2][0]==tComputer && board[1][1]!=' '&& board[1][1]!=tUser){
        board[1][1]=tComputer;
        return;
    }
    else if(board[2][0]==tComputer && board[1][1]==tComputer && board[0][2]!=' ' && board[0][2]!=tUser){
        board[0][2]=tComputer;
        return;
    }
    
    // if it cant win, try to block
    
    if(board[0][0]==tUser && board[0][1]==tUser && board[0][2]!=tComputer){
        board[0][2]=tComputer;
        return;
    }
    else if(board[0][0]==tUser && board[0][2]==tUser && board[0][1]!=tComputer){
        board[0][1]=tComputer;
        return;
    }
    else if(board[0][1]==tUser && board[0][2]==tUser && board[0][0]!=tComputer){
        board[0][0]=tComputer;
        return;
    }
    else if(board[1][0]==tUser && board[1][1]==tUser && board[1][2]!=tComputer){
        board[1][2]=tComputer;
        return;
    }
    else if(board[1][0]==tUser && board[1][2]==tUser && board[1][1]!=tComputer){
        board[1][1]=tComputer;
        return;
    }
    else if(board[1][1]==tUser && board[1][2]==tUser && board[1][0]!=tComputer){
        board[1][0]=tComputer;
        return;
    }
    else if(board[2][0]==tUser && board[2][1]==tUser && board[2][2]!=tComputer){
        board[2][2]=tComputer;
        return;
    }
    else if(board[2][0]==tUser && board[2][2]==tUser && board[2][1]!=tComputer){
        board[2][1]=tComputer;
        return;
    }
    else if(board[2][1]==tUser && board[2][2]==tUser && board[2][0]!=tComputer){
        board[2][0]=tComputer;
        return;
    }
    // vertical block
    else if(board[0][0]==tUser && board[1][0]==tUser && board[2][0]!=tComputer){
        board[2][0]=tComputer;
        return;
    }
    else if(board[0][0]==tUser && board[2][0]==tUser && board[1][0]!=tComputer){
        board[1][0]=tComputer;
        return;
    }
    else if(board[2][0]==tUser && board[1][0]==tUser && board[0][0]!=tComputer){
        board[0][0]=tComputer;
        return;
    }
    else if(board[0][1]==tUser && board[1][1]==tUser && board[2][1]!=tComputer){
        board[2][1]=tComputer;
        return;
    }
    else if(board[0][1]==tUser && board[2][1]==tUser && board[1][1]!=tComputer){
        board[1][1]=tComputer;
        return;
    }
    else if(board[2][1]==tUser && board[1][1]==tUser && board[0][1]!=tComputer){
        board[0][1]=tComputer;
        return;
    }
    else if(board[0][2]==tUser && board[1][2]==tUser && board[2][2]!=tComputer){
        board[2][2]=tComputer;
        return;
    }
    else if(board[0][2]==tUser && board[2][2]==tUser && board[1][2]!=tComputer){
        board[1][2]=tComputer;
        return;
    }
    else if(board[2][2]==tUser && board[1][2]==tUser && board[0][2]!=tComputer){
        board[0][2]=tComputer;
        return;
    }
    // diagnal block
    else if(board[0][0]==tUser && board[1][1]==tUser && board[2][2]!=tComputer){
        board[2][2]=tComputer;
        return;
    }
    else if(board[0][0]==tUser && board[2][2]==tUser && board[1][1]!=tComputer){
        board[1][1]=tComputer;
        return;
    }
    else if(board[2][2]==tUser && board[1][1]==tUser && board[0][0]!=tComputer){
        board[0][0]=tComputer;
        return;
    }
    else if(board[0][2]==tUser && board[1][1]==tUser && board[2][0]!=tComputer){
        board[2][0]=tComputer;
        return;
    }
    else if(board[0][2]==tUser && board[2][0]==tUser && board[1][1]!=tComputer){
        board[1][1]=tComputer;
        return;
    }
    else if(board[2][0]==tUser && board[1][1]==tUser && board[0][2]!=tComputer){
        board[0][2]=tComputer;
        return;
    }
    
    // if computer cant win or block, get a random location to place 'O'
    computerMoveHelper();
    
}

void TicTacToe::computerMoveHelper(){
    bool availableMove=false;
    int random=0;
    while(availableMove==false){
        random =rand()%9+1;
        if(random==1){
            if(board[0][0]==' '){
                board[0][0]=tComputer;
                availableMove=true;
            }
        }
        else if(random==2){
            if(board[0][1]==' '){ 
                board[0][1]=tComputer;
                availableMove=true;
            }
        }
        else if(random==3){
            if(board[0][2]==' '){
                board[0][2]=tComputer;
                availableMove=true;
            }
        }
        else if(random==4){
            if(board[1][0]==' '){
                board[1][0]=tComputer;
                availableMove=true;
            }
        }
        else if(random==5){
            if(board[1][1]==' '){
                board[1][1] = tComputer;
                availableMove=true;
            }
        }
        else if(random==6){
            if(board[1][2]==' '){
                board[1][2]=tComputer;
                availableMove=true;
            }
        }
        else if(random==7){
            if(board[2][0]==' '){
                board[2][0]=tComputer;
                availableMove=true;
            }
        }
        else if(random==8){
            if(board[2][1]==' '){
                board[2][1]=tComputer;
                availableMove=true;
            }
        }
        else if(random==9){
            if(board[2][2]==' '){
                board[2][2]=tComputer;
                availableMove=true;
            }
        }
    }
}