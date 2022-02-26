#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include "game.h"


//Read from the file to get the words

std::string Game::randomWord(){
    std::string wordList[99];
    std::ifstream randomWord;
    randomWord.open("Words.txt");
    for(int i = 0; i < 99; i++)
    {      
    randomWord >> wordList[i];
    }



    std::string word = wordList[rand() % 99];
    return word;
}
//Kind of the logic of the game
void Game::setup(){
    tries = 5;
}


void Game::gameStart(std::string word){
    setup();
    std::string misteryWord(word.length(), '*');
    while(gameOver == false)
    {  
       std::cout << "\033[2J";
       switch(tries)
        {
            case 5:
                 std::cout <<"_______________    " << std::endl;
                 std::cout <<"|             |     " << std::endl;
                 std::cout <<"|             {}    " << std::endl;
                 std::cout <<"|                   " << std::endl;
                 std::cout <<"|                   " << std::endl;
                 std::cout <<"|                   " << std::endl;
                break;
            case 4: 
                 std::cout <<"_______________    " << std::endl;
                 std::cout <<"|             |     " << std::endl;
                 std::cout <<"|            {O}    " << std::endl;
                 std::cout <<"|                   " << std::endl;
                 std::cout <<"|                   " << std::endl;
                 std::cout <<"|                   " << std::endl;
                break;
            case 3:
                 std::cout <<"_______________    " << std::endl;
                 std::cout <<"|             |     " << std::endl;
                 std::cout <<"|            {O}    " << std::endl;
                 std::cout <<"|             |     " << std::endl;
                 std::cout <<"|                   " << std::endl;
                 std::cout <<"|                   " << std::endl;
                break;
            case 2:
                 std::cout <<"_______________    " << std::endl;
                 std::cout <<"|             | " << std::endl;
                 std::cout <<"|            {O} " << std::endl;
                 std::cout <<"|            /|\\  " << std::endl;
                 std::cout <<"|               " << std::endl;
                 std::cout <<"|               " << std::endl;
                 break;
            case 1:
                 std::cout <<"_______________    " << std::endl;
                 std::cout <<"|             |     " << std::endl;
                 std::cout <<"|            {O}    " << std::endl;
                 std::cout <<"|            /|\\   " << std::endl;
                 std::cout <<"|            / \\   " << std::endl;
                 std::cout <<"|           -----    " << std::endl;
                 std::cout <<"|             |      " << std::endl;
                 break;
        
                 
        }
        
       
       std::cout << "You're guessing the word: " << misteryWord << std::endl;
       std::cout << "That words has: " << misteryWord.length() << " characters" << std::endl;
       std::cout << "You have: +" << tries << " tries" << std::endl;
       //std::cout << word << std::endl;
       
       std::cout << std::endl;
       std::cin >> userInput;
       std::cout << std::endl;

        right = false;
        
       
       for(int i = 0; misteryWord.length() > i; i++)
       {
       


        if(word[i] == userInput)
        {
            misteryWord[i] = userInput;
            right = true;


        
        }   


        }
         if(right == true)
        {
            
        }
        else
        {
            
            tries--;
        }
    if(word == misteryWord){
        std::cout << "You've won! Congrats!" << std::endl;
        gameOver = true;
    }
    if (tries == 0)
    {
                 std::cout << "\033[2J";
                 std::cout <<"_______________    " << std::endl;
                 std::cout <<"|             |     " << std::endl;
                 std::cout <<"|             |      " << std::endl;
                 std::cout <<"|            {O}    " << std::endl;
                 std::cout <<"|            /|\\   " << std::endl;
                 std::cout <<"|            / \\   " << std::endl;
                 std::cout <<"|                   " << std::endl;
        gameOver = true;
    }
    

       }


//Prompt that asks y/n
}
int Game::yesOrno(std::string question){
    
    std::cout << question << "[y/n] " << std::endl;
    
    std::string userInput;
    
    std::cout << std::endl;
    std::cin >> userInput;
    std::cout << std::endl;

    boost::to_lower(userInput);

    
    while(userInput != "y" or "yes" || "n" or "no"){
    

    if(userInput == "y"){
        return 1;
        
    } 
    else if (userInput == "n")
    {
        return 0;
        

    }
    else
    {
        return yesOrno(question);
    }
    
    }
    
    return 0;
}
