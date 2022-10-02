#include "game.h"

#include <iostream>
using std::cin, std::cout, std::endl;

#include <fstream>
#include <iomanip>

hangman::hangman(const string diretory)
    : GameOver(false), NWord(diretory.length( ))
{
    if(NWord == 0) abort( );

    std::fstream file;
    file.open(diretory);

    WordList = new string[NWord];

    for(int i = 0; i < NWord; i++)
        file >>WordList[i];
}

hangman::~hangman( )
{
    delete[] WordList;
}

bool hangman::close(void)
{
    if(GameOver)
    {
        cout
            << std::setw(5)<< "\nYou "<< ( GameOver == true && tries < 6 ? "Win" : "Lost" )
            << "!\nWhat to play again?\n[y/n]"<< 
        endl;

        while(Input != 'y' && Input != 'n')
        {
            cin >>Input;
            tolower(Input);
            cout<< '\b';
        }

        if(Input == 'y') GameOver = false;
    }

    return GameOver;
}

// Gera saida
void hangman::screen(const string &word) const
{
    cout
        << "Search: "<< std::left<< std::setw( word.length( ) + 3 )<< word
        << "Tries: "<< tries<< '\n'<< graphic[tries]<< '\n'<< 
    endl;
}

void hangman::play(void)
{
    // pega uma palavra aleatória carregada no ponteiro WordList
    const string guessWord( WordList[ 1 + std::rand( ) % NWord ] );
    string search( guessWord ); // copia a string

    const size_t length{ guessWord.length( ) };
    tries = 0;

    // seta todos os caracteres menos o de terminação nulo como espaço
    for(int i = 0; i < length; i++)
        search[i] = '_';

    while(GameOver != true)
    {
        system("cls"); // limpa a tela em systemas opearcionais Windows
        screen(search);

        cin >>Input;
        tolower(Input);

        for(int changes = 0, i = 0; i < length + 1; i++)
        {
            /* */if(Input == guessWord[i]) 
            {
                search[i] = Input;
                ++changes;
            }
            else if(changes == 0 && guessWord[i] == '\0')
                ++tries;
        }

        if(search == guessWord || tries == 6 )
        {
            screen(guessWord);
            GameOver = true;
        }
    }
}

const string hangman::graphic[7]
{
    "_________  \n"
    "|      I   \n"
    "|          \n"
    "|          \n"
    "|          \n"
    "|    ----- \n"
    "|     | |  ", 

    "_________  \n"
    "|      I   \n"
    "|      O   \n"
    "|          \n"
    "|          \n"
    "|    ----- \n"
    "|     | |  ", 

    "_________  \n"
    "|      I   \n"
    "|      O   \n"
    "|      |   \n"
    "|          \n"
    "|    ----- \n"
    "|     | |  ", 

    "_________  \n"
    "|      I   \n"
    "|      O   \n"
    "|     /|   \n"
    "|          \n"
    "|    ----- \n"
    "|     | |  ", 

    "_________  \n"
    "|      I   \n"
    "|      O   \n"
    "|     /|\\  \n"
    "|          \n"
    "|    ----- \n"
    "|     | |  ", 

    "_________  \n"
    "|      I   \n"
    "|      O   \n"
    "|     /|\\  \n"
    "|     /    \n"
    "|    ----- \n"
    "|     | |  " , 

    "_________  \n"
    "|      I   \n"
    "|      O   \n"
    "|     /|\\  \n"
    "|     / \\  \n"
    "|    ----- \n"
    "|     | |  "
};
    