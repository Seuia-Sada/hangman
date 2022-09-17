#include "game.h"

int main(void)
{
    std::srand( std::time( NULL ) );
    Game game;

    while(game.close( ))
        game.play( );

    return EXIT_SUCCESS;
}
    