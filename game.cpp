#include "game.h"

const char *const Game::graphic[6]
{
    {
        "_______________     \n"
        "|             |     \n"
        "|             {}    \n"
        "|                   \n"
        "|                   \n"
        "|                   \n"
        "|                   "
    }, {
        "_______________     \n"
        "|             |     \n"
        "|            {O}    \n"
        "|                   \n"
        "|                   \n"
        "|                   \n"
        "|                   "
    }, {
        "_______________     \n"
        "|             |     \n"
        "|            {O}    \n"
        "|             |     \n"
        "|                   \n"
        "|                   \n"
        "|                   "
    }, {
        "_______________     \n"
        "|             |     \n"
        "|            {O}    \n"
        "|            /|\\    \n"
        "|                   \n"
        "|                   \n"
        "|                   "
    }, {
        "_______________     \n"
        "|             |     \n"
        "|            {O}    \n"
        "|            /|\\    \n"
        "|            / \\    \n"
        "|                   \n"
        "|                   "
    }, {
        "_______________     \n"
        "|             |     \n"
        "|            {O}    \n"
        "|            /|\\    \n"
        "|            / \\    \n"
        "|           -----   \n"
        "|             |     "
    }
};

Game::Game( int size )
    :gameOver( false ), tries( 0 ), length( size ), wordList( nullptr )
{
    wordList = new string[length];

    std::ifstream randomWord;
    randomWord.open("Words.txt");

    for(int i = 0; i < length; i++)
        randomWord >> wordList[i];
}

Game::~Game( )
{
    delete[] wordList;
}

void Game::play( )
{
    string misteryWord{ wordList[ 1 + std::rand( ) + length ] };

    while(0 < tries--)
    {
        cout << "\033[2J"<<graphic[tries];

        cout << 
            "\nYou're guessing the word: " << misteryWord << 
            "\nThat words has: " << length << 
            " characters\nYou have: +" << tries << " tries\n"<< 
        endl;

        cin >> userInput;

        if(misteryWord == userInput)
        {
            gameOver = true;
            break;
        }
    }
}

bool Game::close( )
{
    cout << "Do you want to play again? [y/n]\n" << endl;

    while(true)
    {
        cin >> userInput;
        cout << endl;

        for(int i = 0, size = userInput.length( ); i < size; i++)
            userInput[i] = tolower(userInput[i]);

        if(userInput == "y" || userInput == "yes")
            break;
        else if(userInput == "n" || userInput == "no")
        {
            tries = 5;
            gameOver = false;
        }
    }
    return gameOver;
}
    