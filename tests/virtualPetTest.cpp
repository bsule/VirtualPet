#include "gtest/gtest.h"
#include "../header/virtualPet.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

TEST(VitualPetTest, CreatingPetTest){
  EXPECT_NO_THROW(VirtualPet *virtualPet = new VirtualPet("Cat", "Po"));
}

TEST(VirtualPetTest, StatsTest){
  VirtualPet *virtualPet1 = new VirtualPet("Cat", "Po");
  EXPECT_EQ(virtualPet1->getAffection(), 100);
  EXPECT_EQ(virtualPet1->getBoredom(), 100);
  EXPECT_EQ(virtualPet1->getHunger(), 100);
  EXPECT_EQ(virtualPet1->getThirst(), 100);
  EXPECT_EQ(virtualPet1->getMessiness(), 100);
}

int main(int argc, char **argv) {
    VirtualPet virtualPet("Cat", "Po");
    virtualPet.displayInventory();
    virtualPet.addToInventory(virtualPet.CAKE);
    virtualPet.displayInventory();
    

    //Test for Updating Stats
    /*
    cout << endl << virtualPet.hunger << endl;
    std::this_thread::sleep_for(std::chrono::seconds(11));
    virtualPet.updateStats(virtualPet.hunger);
    cout << endl << virtualPet.hunger << endl;
    */    


  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}