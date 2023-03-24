#ifndef MINIGAMES_HPP
#define MINIGAMES_HPP

class Minigames{
    private:
        int experienceAwarded;
        //enum itemRewarded;
    public:
        const virtual void print() = 0;
        const virtual void printRules() = 0;
        void startGame();
        void clearText();
};

#endif