#include "game.h"

int main( )
{
    std::srand( std::time(NULL) );
    hangman game("Words.txt");

    while(!game.close( ))
        game.play( );

    return 0;
}
    