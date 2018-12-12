/******************************************************************************************
 ** Program name: Final Project Board header
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: makes the board for the game and links all Spaces together
 ******************************************************************************************/


#ifndef BOARD_HPP
#define BOARD_HPP
#include "Ground.hpp"
#include "House.hpp"
#include "Car.hpp"
#include "Tree.hpp"
#include "GrandmaHome.hpp"
#include "Start.hpp"

class Board {
    
private:
    Space ***boardMap;                              //a pointer to 2D array
    string emptyTile;                               //stores "  " to signify empty tile

    
public:
    Board();                                        //allocate memory for 2D array 
    ~Board();                                       //deallocates memory
    void printBoard();                              //prints the board with Sally and Grandma
    void makeBoard();                               //allocates memory to make the 2D array
    Space*** getBoard();                            //returns the Board 
    void setEmptyTiles();
    
};


#endif
