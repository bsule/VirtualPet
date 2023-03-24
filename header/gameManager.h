#ifndef GAMEMANGER_HPP
#define GAMEMANGER_HPP

#include "virtualPet.h"
#include <iostream>

using namespace std;

class GameManager{
    public:
        GameManager(); //constructor
        ~GameManager(); //deconstructor
        void start();
        void mainMenu();
        void save(); //create a file to save
        void load(); //load contents from a file
    private:
        VirtualPet* pet;
};

#endif