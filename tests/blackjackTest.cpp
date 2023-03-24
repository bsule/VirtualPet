#include "gtest/gtest.h"
#include "../header/blackjack.h"
#include "../header/card.h"
#include <iostream>

using namespace std;

TEST(BlackjackTest, CreatingCard){
    EXPECT_NO_THROW(Card *card = new Card(10));
}

TEST(BlackjackTest, ConstructorTest){
  EXPECT_NO_THROW(Blackjack *blackjack = new Blackjack());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}