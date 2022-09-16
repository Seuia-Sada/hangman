#include "game.h"

int main(void)
{
    std::srand( std::time( NULL ) );
    Game game;

    do {
        game.play( );
    } while(!game.close( ) == true);

    return EXIT_SUCCESS;
}
    