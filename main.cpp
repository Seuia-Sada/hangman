#include "game.h"

int main(void)
{
    std::srand( std::time( NULL ) );
    Game game;

    game.play( );

    return EXIT_SUCCESS;
}
    