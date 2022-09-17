#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <string>
using std::string;
#include <cstdlib>

class Game
{
public:
    Game( int = 99 );
    void play( );
    bool close( );
    ~Game( );
private:
    static const char *const graphic[6];
    char userInput;

    bool gameOver;

    int tries;
    const int length;

    string *wordList;
};

#endif
    