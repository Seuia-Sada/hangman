#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <string>
using std::string;

struct hangman 
{
public:
    // construtor padrão que recebe uma string informando o nome do arquivo / diretório
    hangman( const string diretory = "" );
   ~hangman( );

    bool close( void );
    void play  ( void );
private:
    void screen( const string& ) const;

    bool GameOver;
    char Input;

    const int NWord;
    int tries;

    // string que será carregada com palavras
    string *WordList;
    const static string graphic[7];
};

#endif
    