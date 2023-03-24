#ifndef VIRTUALPET_HPP
#define VIRTUALPET_HPP

#include <iostream>
#include "../header/minigames.h"
#include <string>
#include <ctime>

using namespace std;

class VirtualPet{
    public:
        enum Items {EMPTY, CAKE, TREAT};
        const string ItemsText[3] = {"", "Cake", "Treat"};
    private:
        time_t savedTime = time(NULL);
        void updateStats(int&);
        string name = "";
        int experience = 0;
        int petLevel = 0;
        enum PetType {
            DOG = 1, 
            CAT = 2
        };
        PetType petType;
        int hunger = 100;
        int thirst = 100;
        int boredom = 100;
        int messiness = 100;
        int affection = 100;
        int status = 100;
        const string catForm1 = R"(
                            _ |\ _
                            \ ` ..
                        __,.- =__Y=
                        .        )
                _    /   ,    \ /\ _
                ((____|    )_-\ \ _-`
                  `-----'`-----` `--`
        )";
        const string catForm2 = R"(
                 ,_     _ 
                | \ _,-~/
                / _  _ |    ,--.
                (  @  @ )   / ,-'
                \  _T_/-._( (
                /         `. 
                |         _  \ |
                \ \ ,  /      |
                || |-_\ __   /
                ((_/`(____,-'
        )";
        const string catForm3 = R"(
                _                          
                \`*-.                  
                )  _`-.                  
                .  : `. .              
                : _   '  \.              
                ; *` _.   `*-._        
                `-.-'          `-.    
                    ;       `       `.     
                    :.       .        \.    
                    . \  .   :   .-'   .   
                    '  `+.;  ;  '      :   
                    :  '  |    ;       ;-. 
                    ; '   : :`-:     _.`* 
                .*' /  .*' ; .*`- +'  `*' 
                `*-*   `*-*  `*-*
        )"; //put in value here later...

        const string dogForm1 = R"(
                   __ 
            (___()'`;
            /,    /`
            \ -- \. 
        )";
        const string dogForm2 = R"(
            _   _
            /(. .)\    )
              (*)____/| 
            /       |
            /   |--\ |
            (_)(_)  (_)
        )";
        const string dogForm3 = R"(
                 __
                /  \. 
                / ..|\. 
                (_\  |_)
                /  \@' 
                /     \. 
            _   /  `   | 
            \ /  \  | _\. 
            \   /_ ||  \ _ 
            \____)|_) \ _)
            )";
        string petForms[3] = {dogForm1, dogForm2, dogForm3}; //default...
        //Items Inventory[];
        int itemCount = 0; //how many items the player currently has
        Items Inventory[20] = {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,
        EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,
        EMPTY,EMPTY,EMPTY,EMPTY,EMPTY};
        

    public:
        VirtualPet(string, string); //constructor
        void addExperience(int);
        void decreaseBoredom();
        void updateSavedTime();
        const void printLevelUp();
        void updateLevel();
        int getStatus();
        int getHunger();
        int getThirst();
        int getBoredom();
        int getMessiness();
        int getAffection();
        void feed(Items);
        void foodPrompt();
        void drink();
        void rest();
        void clean();
        void petYourPet();
        int getExperience();
        int getPetLevel();
        PetType getPetType();
        string getPetTypeString();
        string getPetName();
        const void printPet();
        const void displayInventory(); //display inventory
        bool hasCakes();
        bool hasTreats();
        void settleInventory(); //make sure all empty indexes are last
        void addToInventory(Items); //add an item to pet inventory
        void addRandomItemToInventory();
        const void printPet(PetType, int);
        void save(); //create a file to save
        bool load(); //load contents from a file
};

#endif