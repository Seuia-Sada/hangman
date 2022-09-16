#include "game.h"

int main(void)
{
    std::srand( std::time( NULL ) );
    Game game;

    do {
        game.play( );
    } while(game.close( ));

    return EXIT_SUCCESS;
}
    