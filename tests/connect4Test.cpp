#include "gtest/gtest.h"
#include "../header/connect4.h"
#include <iostream>

using namespace std;

TEST(Constructor, ConstructorNoThrow){
  EXPECT_NO_THROW(Connect4 *c4 = new Connect4());
}

/*
TEST(ValidityCheck, isValidColumn1){
  Connect4 *c4 = new Connect4();
  EXPECT_TRUE(c4->isValidColumn(1));
}

TEST(ValidityCheck, isValidColumn2){
  Connect4 *c4 = new Connect4();
  EXPECT_TRUE(c4->isValidColumn(5));
}

TEST(ValidityCheck, isEmpty1){
  Connect4 *c4 = new Connect4();
  EXPECT_TRUE(c4->isEmpty(0,0));
}

TEST(ValidityCheck, isEmpty2){
  Connect4 *c4 = new Connect4();
  EXPECT_EQ(c4->isEmpty(2,3),true);
}
*/

TEST(StartGame, StartGame ){
  Connect4 *c4 = new Connect4();
  EXPECT_NO_THROW(c4->startGame());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
