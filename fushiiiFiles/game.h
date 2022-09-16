#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

#ifndef GAMER_H
#define GAMER_H

class Game{
    public:
    bool right;
    bool gameOver = false;
    int rightAnswer = 0;
    int wrongAnswer = 0;
    int tries = 5;
    char userInput;
    int count;
    void gameStart(std::string);
    std::string randomWord();
    int yesOrno(std::string question);
    void setup();

};

#endif // USER_H
