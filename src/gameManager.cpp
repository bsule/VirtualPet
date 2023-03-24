#include "../header/gameManager.h"
#include "../header/virtualPet.h"
#include "../header/blackjack.h"
#include "../header/connect4.h"
#include "../header/tictactoe.h"
#include "../header/rockpaperscissors.h"
#include <iostream>
#include <limits>

using namespace std;

GameManager::GameManager(){
    start();
}

GameManager::~GameManager(){
    delete pet;
}

void GameManager::start(){

    system("clear"); //make sure everything is cleared
    int userInput;
    bool cont = true; //just to loop through if we get an invalid input

    while(cont){

        cout << "Welcome! Are you loading a save or starting a new one? (1 for load, 2 for new)\n";
        cin >> userInput;

        if (cin.fail()){
            cout << "Invalid input" << endl;
            userInput = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (userInput == 1){ //load
            pet = new VirtualPet("", "");
            pet->load();
            mainMenu();

            cont = false;
        }
        else if (userInput == 2){ //new
            string petType, name;
            cont = true;
            // choose type of pet
            while (cont){
                cout << "Would you like a cat or a dog? (1 for cat, 2 for dog): ";
                cin >> userInput;
                if (cin.fail()){
                    cout << "\nInvalid input" << endl;
                    userInput = -1;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if (userInput == 1){
                    petType = "Cat";
                    cont = false;
                }
                else if (userInput == 2){
                    petType = "Dog";
                    cont = false;
                }
                else{
                    cout << "\nInvalid input" << endl;
                    userInput = -1;
                }
                cout << endl;
            }

            cont = true;
            string userInput2 = "";

            //choose name of pet
            while (cont){
                cout << "What is the name of your " << petType << "?: ";
                cin >> name;
                if (cin.fail()){
                    cout << "\nInvalid input" << endl;
                    userInput = -1;
                    cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if (name == ""){
                    cout << "\nPlease enter a name" << endl;
                }
                else{
                    cont = false;
                }
                cout << endl;
            }

            //Now make the pet...
            pet = new VirtualPet(petType, name);
            pet->save();
            mainMenu();

            cont = false;
        }
        else{
            cout << "Invalid input" << endl;
            userInput = -1;
        }
    }

}

void GameManager::mainMenu(){
    system("clear"); //make sure everything is cleared
    pet->printPet();
    cout << "\nLEVEL " << pet->getPetLevel() << " ";
    if (pet->getPetTypeString() == "Cat"){
        cout << "CAT: ";
    }
    else{
        cout << "DOG: ";
    }
    cout << pet->getPetName() << endl << endl;

    int i;
    cout << "HUNGER    | ";
    for (i = 0; i < pet->getHunger()/10; i++){
        cout << "■";
    }
    for (i = 0; i < (10 - (pet->getHunger()/10)); i++){
        cout << "□";
    }

    cout << endl << "THIRST    | ";
    for (i = 0; i < pet->getThirst()/10; i++){
        cout << "■";
    }
    for (i = 0; i < (10 - (pet->getThirst()/10)); i++){
        cout << "□";
    }

    cout << endl << "BOREDOM   | ";
    for (i = 0; i < pet->getBoredom()/10; i++){
        cout << "■";
    }
    for (i = 0; i < (10 - (pet->getBoredom()/10)); i++){
        cout << "□";
    }

    cout << endl << "MESSINESS | ";
    for (i = 0; i < pet->getMessiness()/10; i++){
        cout << "■";
    }
    for (i = 0; i < (10 - (pet->getMessiness()/10)); i++){
        cout << "□";
    }

    cout << endl << "AFFECTION | ";
    for (i = 0; i < pet->getAffection()/10; i++){
        cout << "■";
    }
    for (i = 0; i < (10 - (pet->getAffection()/10)); i++){
        cout << "□";
    }

    cout << endl << "EXP : " << pet->getExperience() << " / 100" << endl;

    pet->updateSavedTime();

    cout << endl << endl << "-----------------------------------" << endl;
    cout << "What do you want to do with your pet?" << endl;
    cout << "1. Play Games" << endl;
    cout << "2. Pet" << endl;
    cout << "3. Feed" << endl;
    cout << "4. Drink" << endl;
    cout << "5. Clean" << endl;
    cout << "6. Check Inventory" << endl;
    cout << "7. Save" << endl;
    cout << "8. Quit" << endl;
    bool cont = true;

    while (cont){
        int userInput;
        cin >> userInput;
        cout << endl;
    
        switch (userInput){
            
            case 1: //play games
                cont = true;
                while (cont){
                    cout << "Which minigame would you like to play?" << endl;
                    cout << "1. Blackjack" << endl;
                    cout << "2. Connect 4" << endl;
                    cout << "3. Tic Tac Toe" << endl;
                    cout << "4. Rock Paper Scissors" << endl;
                    
                    cin >> userInput;
                    switch (userInput){
                        case 1:
                            {//Blackjack();
                                Blackjack blackjack;
                                pet->decreaseBoredom();
                                if (blackjack.startGame()){
                                    pet->addExperience(10);
                                    pet->addRandomItemToInventory();
                                }
                                cont = false;
                                mainMenu();
                                break;
                            }
                        case 2:
                            {
                                //Connect4();
                                Connect4 connect4;
                                pet->decreaseBoredom();
                                if (connect4.startGame()){
                                    pet->addExperience(10);
                                    pet->addRandomItemToInventory();
                                }
                                cont = false;
                                mainMenu();
                                break;
                            }
                        case 3:
                            {
                                //TicTacToe();
                                TicTacToe tictactoe;
                                pet->decreaseBoredom();
                                if (tictactoe.startGame()){
                                    pet->addExperience(10);
                                    pet->addRandomItemToInventory();
                                }
                                cont = false;
                                mainMenu();
                                break;
                            }
                            
                        case 4:
                            {
                                //RockPaperScissors();
                                RockPaperScissors rockpaperscissors;
                                pet->decreaseBoredom();
                                int XP = rockpaperscissors.startGame();//30,50,100 points
                                pet->addExperience(XP);
                                if (XP != 0){
                                    pet->addRandomItemToInventory();
                                }
                                cont = false;
                                mainMenu();
                                break;
                            }
                        default:
                            cout << "Invalid Input" << endl;
                            userInput = -1;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                    }
                    
                }
                cont = false;
                break;
            case 2: //Pet
                pet->petYourPet();
                cont = false;
                break;
            case 3: //Feed
                if (pet->hasTreats() || pet->hasCakes()) {
                    pet->foodPrompt();
                    int playerFoodChoice;
                    cin >> playerFoodChoice;

                    
                    while ((cin.fail() || playerFoodChoice > 2 || playerFoodChoice < 1)
                           || (playerFoodChoice == 1 && !pet->hasCakes())
                           || (playerFoodChoice == 2 && !pet->hasTreats())) {

                        system("clear");
                        if (cin.fail()){
                            playerFoodChoice = -1;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else if (playerFoodChoice == 1) {
                            cout << "You have no cakes! Enter a different option!" << endl << endl;
                        }
                        else if (playerFoodChoice == 2) {
                            cout << "You have no treats! Enter a different option!" << endl << endl;
                        }
                        else {
                            cout << "That's not a food choice!" << endl << endl;
                        }
                        cin.clear();
                        cin.ignore();
                        pet->foodPrompt();
                        cin >> playerFoodChoice;
                    }
                    
                    if (playerFoodChoice == 1) {
                        pet->feed(VirtualPet::CAKE);
                    }
                    else if (playerFoodChoice == 2) {
                        pet->feed(VirtualPet::TREAT);
                    }      
                }         
                else {
                    cout << "You have no food!" << endl << endl;
                }
                cont = false;
                break;
            case 4: //Drink
                pet->drink();
                cont = false;
                break;
            case 5: //Clean
                pet->clean();
                cont = false;
                break;
            case 6:
                //call check inventory thing
                pet->displayInventory();
                cont = false;
                break;
            case 7: //save
                //insert save function here
                pet->save();
                
                cont = false;
                break;
            case 8: //quit
                cout << "game exited" << endl;
                return;
            default:
                cout << "Invalid Input" << endl;
                userInput = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }

    cont = true;
    cout << "Enter 0 to go back to refresh the main menu: ";
    while (cont){
        int userInput;
        cin >> userInput;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            userInput = -1;
        }
        if (userInput == 0){
            cont = false;
            system("Clear");
        }
    }
    mainMenu();
}
