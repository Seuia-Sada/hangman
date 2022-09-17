#include <cctype>
#include <fstream>
#include <iostream>
using std::cin, std::cout;
using std::endl;

const char *const Game::graphic[6]
{
    "_______________     \n"
    "|             |     \n"
    "|             {}    \n"
    "|                   \n"
    "|                   \n"
    "|                   \n"
    "|                   ",

    "_______________     \n"
    "|             |     \n"
    "|            {O}    \n"
    "|                   \n"
    "|                   \n"
    "|                   \n"
    "|                   ", 

    "_______________     \n"
    "|             |     \n"
    "|            {O}    \n"
    "|             |     \n"
    "|                   \n"
    "|                   \n"
    "|                   ", 

    "_______________     \n"
    "|             |     \n"
    "|            {O}    \n"
    "|            /|\\    \n"
    "|                   \n"
    "|                   \n"
    "|                   ", 

    "_______________     \n"
    "|             |     \n"
    "|            {O}    \n"
    "|            /|\\    \n"
    "|            / \\    \n"
    "|                   \n"
    "|                   ", 

    "_______________     \n"
    "|             |     \n"
    "|            {O}    \n"
    "|            /|\\    \n"
    "|            / \\    \n"
    "|           -----   \n"
    "|             |     "
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

void Game::play( )
{
    string misteryWord{ wordList[ 1 + std::rand( ) % length ] };
    char* guessWord{ new char[ wordList.length( ) + 1 ] };

    guessWord[wordList.length( )] = '\0';

    while(gameOver == false && 0 < tries)
    {
        cout << "\033[2J" << graphic[tries];

        cout << 
            "\nYou're guessing the word: " << misteryWord << 
            "\nThat words has: " << misteryWord.length( ) << 
            " characters\nYou have: +" << tries << " tries\n"<< misteryWord << 
        endl;
        cin >> userInput;
    }
}

bool Game::close( )
{
    while(gameOver == true)
    {
        cout << "Do you want to play again? [y/n]\n" << endl;
        cin >> userInput;
        cout << endl;

        userInput[i] = tolower(userInput[i]);

        if(userInput == 'y')
        {
            tries = 5;
            gameOver = false;
            break;
        } 
        else if(userInput == 'n')
            break;
    }
    return !gameOver;
}

Game::~Game( )
{
    delete[] wordList;
}
    