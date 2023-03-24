#include "../header/virtualPet.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

VirtualPet::VirtualPet(string _petType, string _name){
    if (_petType == "Cat"){
        this->petType = CAT;
        if (_petType == "Cat"){
            this->petType = CAT;
            petForms[0].clear();
            petForms[1].clear();
            petForms[2].clear();
            petForms[0] = catForm1;
            petForms[1] = catForm2;
            petForms[2] = catForm3;
        }
        /*
        string _petForms[3] = {catForm1, catForm2, catForm3};
        copy(_petForms, _petForms + 3, petForms);
        */
    }
    /*
    else if (_petType == "Dog"){
        this->petType = DOG;
        string _petForms[3] = {dogForm1, dogForm2, dogForm3};
        copy(_petForms, _petForms + 3, petForms);
    }
    */
    this->name = _name;
}

const void VirtualPet::printPet(){ 
    if (petLevel < 5){
        cout << petForms[0] << endl;
    }
    else if (petLevel < 10){
        cout << petForms[1] << endl;
    }
    else{
        cout << petForms[2] << endl;
    }
}

int VirtualPet::getPetLevel(){
    return petLevel;
}

void VirtualPet::updateLevel(){
    petLevel = (experience/100) + 1;
}

int VirtualPet::getExperience(){
    return experience;
}

void VirtualPet::save(){
    ofstream os;
    os.open("SaveFile.txt");
    if(!os.is_open()){
        cout << endl << "Error opening file." << endl;
        return;
    }
    os << "DO NOT MODIFY THIS FILE\n";
    os << name << endl;
    os << experience << endl;
    os << petLevel << endl;
    os << hunger << endl;
    os << thirst << endl;
    os << boredom << endl;
    os << messiness << endl;
    os << affection << endl;
    os << status << endl;
    os << time(NULL) << endl;
    // os << petForms[0] << endl;
    // os << petForms[1] << endl;
    // os << petForms[2] << endl;
    os << itemCount << endl;

    for(int i=0;i<20;i++){
        if(Inventory[i]==Items::EMPTY){
            os << "EMPTY" << endl;
        }
        else if(Inventory[i]==Items::CAKE){
            os << "CAKE" << endl;
        }
        else{
            os << "TREAT" << endl;
        }
    }
    os << petType << endl;


    os.close();
}

bool VirtualPet::load(){
    ifstream os;
    os.open("SaveFile.txt");
    if(!os.is_open()){
        cout << endl << "Error opening file." << endl;
        return false;
    }
    string values;
    int intvalues;
    getline(os,values);
    getline(os, values);
    name=values;
    
    // int values
    getline(os,values);
    intvalues=stoi(values);
    experience = intvalues;
    getline(os, values);
    intvalues=stoi(values);
    petLevel=intvalues;
    getline(os, values);
    intvalues=stoi(values);
    hunger=intvalues;
    getline(os, values);
    intvalues=stoi(values);
    thirst=intvalues;
    getline(os, values);
    intvalues=stoi(values);   
    boredom=intvalues;
    getline(os, values);
    intvalues=stoi(values);
    messiness=intvalues;
    getline(os,values);
    intvalues=stoi(values);
    affection=intvalues;
    getline(os, values);
    intvalues=stoi(values);
    status=intvalues;
    getline(os, values);
    intvalues=stoi(values);
    savedTime=intvalues;
    getline(os, values);
    intvalues=stoi(values);
    itemCount=intvalues;

    for(int i=0;i<20;i++){
        getline(os,values);
        if(values=="EMPTY"){
            Inventory[i]=Items::EMPTY;
        }
        else if(values=="CAKE"){
            Inventory[i]=Items::CAKE;
        }
        else if(values=="TREAT"){
            Inventory[i]=Items::TREAT;
        }
    }
    getline(os, values);
    intvalues=stoi(values);
    if(intvalues==1){
        petType=DOG;
    }
    else{
        petType=CAT;
    }

    os.close();
    return true;
}

string VirtualPet::getPetTypeString(){
    if (petType == CAT){
        return "Cat";
    }
    else if (petType == DOG){
        return "Dog";
    }
    return "";
}

string VirtualPet::getPetName(){
    return name;
}

void VirtualPet::petYourPet(){
    affection += 25;
    if (affection > 100){
        cout << "affection already max" << endl;
        affection = 100;
    }
    else cout << "you pet your pet and gained 25 affection" << endl;
}

void VirtualPet::decreaseBoredom(){
    boredom += 25;
    if (boredom > 100){
        boredom = 100;
    }
}

void VirtualPet::clean(){
    cout << "you cleaned your pet" << endl;
    messiness = 100;
}


void VirtualPet::rest(){
    if(status==100){
        cout << "Your pet is already fully rested!" << endl;
        return;
    }
    status=status+10;
    if(status>100){
        status=100;
        cout << "Your pet is now fully rested!" << endl;
        return;
    }
    cout << "Your pets rest level is now " << status << "!" << endl;

}

int VirtualPet::getStatus(){
    updateStats(status);
    return status;
}

int VirtualPet::getHunger(){
    updateStats(hunger);
    return hunger;
}

int VirtualPet::getThirst(){
    updateStats(thirst);
    return thirst;
}


int VirtualPet::getBoredom(){
    updateStats(boredom);
    return boredom;
}

int VirtualPet::getMessiness(){
    updateStats(messiness);
    return messiness;
}

int VirtualPet::getAffection(){
    updateStats(affection);
    return affection;
}

void VirtualPet::foodPrompt() {
    cout << "What do you want to feed your pet?" << endl;
    cout << "1. Cake" << endl;
    cout << "Or" << endl;
    cout << "2. Treat" << endl;
    displayInventory();
}
bool VirtualPet::hasCakes() {
    for (int i = 0; i < itemCount; ++i) {
        if (Inventory[i] == CAKE) {
            return true;
        }
    }
    return false;
}

bool VirtualPet::hasTreats() {
    for (int i = 0; i < itemCount; ++i) {
        if (Inventory[i] == TREAT) {
            return true;
        }
    }
    return false;
}

void VirtualPet::feed(Items item){
    if (hunger == 100) {
        cout << "Your pet's hunger is already max!" << endl << endl;
        return;
    }

// Looks for index of first specified food item it finds. For example, if they specified "CAKE" then this will find the first cake in the inventory and get the index.
    int itemIndex;
    for (int i = 0; i < itemCount; ++i) { 
        if (Inventory[i] == item) {
            itemIndex = i;
            i = 21;
        }
        // else if (i == itemCount) {
        //     if (item == CAKE) {
        //         cout << "You have no cakes!" << endl;
        //     }
        //     else if (item == TREAT) {
        //         cout << "You have no treats!" << endl;
        //     }
        //     return;
        // }
    }
//This loop down here uses the itemIndex we got and moves the food item to the end of the inventory array, then we --itemCount to signify that a food item was consumed. 
    // for (int i = itemIndex; i < itemCount - 1; ++i) {
    //     Items temp = Inventory[i];
    //     Inventory[i] = Inventory[i+1];
    //     Inventory[i+1] = temp;
    // }
    // --itemCount;

    Inventory[itemIndex] = EMPTY;
    hunger += 10;
    --itemCount;
    settleInventory();
    if (hunger > 100){
        hunger = 100;
        cout << "Your pets hunger is now max!" << endl;
        return;
    }
    cout << "Your pets hunger level is now " << hunger << "!" << endl;

}

void VirtualPet::drink(){
    if(thirst==100){
        cout << "Your pets thirst is already max!" << endl;
        return;
    }
    thirst=thirst+10;
    if(thirst>100){
        thirst=100;
        cout << "Your pets thirst is now max!" << endl;
        return;
    }
    cout << "Your pets thirst level is now " << thirst << "!" << endl;
}

const void VirtualPet::displayInventory(){
    cout << "Pet Inventory:" << endl;
    cout << "You have " << itemCount << " out of 20 items" << endl;
    settleInventory();
    for (unsigned i = 0; i < 20; i++){
        if (Inventory[i] == EMPTY){

        }
        else if (Inventory[i] == CAKE){
            cout << i + 1 << ". " << ItemsText[CAKE] << endl;
        }
        else if (Inventory[i] == TREAT){
            cout << i + 1 << ". " << ItemsText[TREAT] << endl;
        }
    }
}

void VirtualPet::settleInventory(){
    for (unsigned i = 0; i < 20; i++)
    {
        for (unsigned j = 0; j < 20; j++)
        {
            if (Inventory[j] == EMPTY){
                Items temp = Inventory[j];
                Inventory[j] = Inventory[j + 1];
                Inventory[j + 1] = temp;
            }
        }           
    }
}

void VirtualPet::addToInventory(Items item){
    if(itemCount == 20){
        cout << "Inventory is full" << endl;
    }
    Inventory[itemCount] = item;
    itemCount++;
    cout << ItemsText[item] << " was added to inventory" << endl;
}

void VirtualPet::addRandomItemToInventory(){
    int randomNumber = rand() % 2 + 1;
    if (randomNumber == 1){
        addToInventory(Items::CAKE);
    }
    else{
        addToInventory(Items::TREAT);
    }
}

void VirtualPet::updateStats(int& stat){
    int statDropPerHour = 10;
    int pointsToLose;

    time_t currentTime = time(NULL);
    time_t timeDifference = currentTime - savedTime; //difference in seconds
    timeDifference /= 3600; //difference in hours
    pointsToLose = timeDifference * statDropPerHour; //How many points should be lost after given hour

    if (stat - pointsToLose <= 0) stat = 0;
    else stat -= pointsToLose;
}

void VirtualPet::updateSavedTime(){
    savedTime = time(NULL);
}

void VirtualPet::addExperience(int experienceAdd){
    experience += experienceAdd;
    updateLevel();
}