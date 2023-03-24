#include "gtest/gtest.h"
#include "../header/tictactoe.h"
#include <iostream>

using namespace std;


TEST(tCleartext, testNoThrow3){
	TicTacToe *nothrow1 = new TicTacToe();
	EXPECT_NO_THROW(nothrow1->clearText());
}

TEST(tConstructor,testNoThrowConstruc){
	EXPECT_NO_THROW(TicTacToe *nothrow = new TicTacToe());
}

TEST(tStartGame, testNoThrow){
	TicTacToe *nothrow1 = new TicTacToe();
	EXPECT_NO_THROW(nothrow1->startGame());
}

TEST(tPrint, testNoThrow2){
	TicTacToe *nothrow1 = new TicTacToe();
	EXPECT_NO_THROW(nothrow1->printRules());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}