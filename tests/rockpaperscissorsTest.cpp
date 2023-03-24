#include "gtest/gtest.h"
#include "../header/rockpaperscissors.h"
#include <iostream>

using namespace std;

TEST(RPSTests, testStartGame)
{
    RockPaperScissors game;
    EXPECT_NO_THROW(game.startGame());
}

TEST(RPSTests, testConstructor)
{
    EXPECT_NO_THROW(RockPaperScissors *game = new RockPaperScissors());
}

TEST(RPSTests, testNoThrow)
{
    RockPaperScissors *game = new RockPaperScissors();
    EXPECT_NO_THROW(game->clearText());
}

TEST(RPSTests, testNoThrow2)
{
    RockPaperScissors *game = new RockPaperScissors();
    EXPECT_NO_THROW(game->printRules());
}

TEST(RPSTests, testNoThrow3)
{
    RockPaperScissors *game = new RockPaperScissors();
    EXPECT_NO_THROW(game->getPlayerChoice());
}

TEST(RPSTests, testNoThrow4)
{
    RockPaperScissors *game = new RockPaperScissors();
    EXPECT_NO_THROW(game->printFinalScore());
}

TEST(RPSTests, testNoThrow5)
{
    RockPaperScissors *game = new RockPaperScissors();
    EXPECT_NO_THROW(game->printScore());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}