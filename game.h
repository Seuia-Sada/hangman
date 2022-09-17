#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <cctype>
#include <fstream>
#include <string>
using std::string;
#include <iostream>
using std::cin, std::cout;
using std::endl;
#include <cstdlib>
using std::srand, std::rand;

class Game
{
public:
    Game( int = 99 );
    ~Game( );
    void play( );
private:
    static const char *const graphic[6];

    bool gameOver;
    int tries;
    const int length;

    string userInput;
    string *wordList;
};

#endif
    