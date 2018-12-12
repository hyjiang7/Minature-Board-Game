/******************************************************************************************
 ** Program name: Final Project main
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: main
 ******************************************************************************************/

#include "Game.hpp"
#include <ctime>
#include "Sally.hpp"

int main() {
    unsigned seed;
    seed = time(0);
    srand(seed);
    
    //runs the game
    Game game;
    game.gameLoop();
    
    return 0;
}
