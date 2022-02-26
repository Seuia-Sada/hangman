#include <iostream>
#include <string>
#include<boost/algorithm/string.hpp>
#include "game.h"
 



int main()
{

    srand(time(0));




    Game game;



   while(game.gameOver == false){
       game.gameStart(game.randomWord());
       if(game.yesOrno("Do you want to play again?")){
           game.gameOver = false;
       }
       else{
           game.gameOver = true;
       }
   }
    
   
   
    return 0;
   

}
