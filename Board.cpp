/******************************************************************************************
 ** Program name: Final Project Board implementaiton
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: makes the board for the game and links all Spaces together
 ******************************************************************************************/

#include "Board.hpp"
/****************************************************************
 * allocates memory for 2D array
 * each array element houses a pointer to type Space; boardMap
 * boardMap then creates a new Space object
 ****************************************************************/
Board::Board(){

    emptyTile = "  ";
    
    boardMap = new Space**[5];
    for( int i = 0; i < 5; i++){
        boardMap[i] = new Space*[5];
    }
    
}

//deallocate memory
Board::~Board(){

    //delete the Space objects
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            delete boardMap[i][j];
            boardMap[i][j] = NULL;
        }
    }
    
    //delete the board
    for(int i = 0; i < 5; i++){
        delete [] boardMap[i];
        boardMap[i] = NULL;
    }
    delete [] boardMap;
    boardMap = NULL;
}

/****************************************************************
 * boardMap allocates new memory for Space subclasses
 * the subclasses are then linked by the direction pointers
 ****************************************************************/
void Board::makeBoard(){
    boardMap[0][0] = new Start;
    boardMap[0][1] = new Ground;
    boardMap[0][2] = new Tree;
    boardMap[0][3] = new Car;
    boardMap[0][4] = new Ground;
    boardMap[1][0] = new Tree;
    boardMap[1][1] = new Tree;
    boardMap[1][2] = new House;
    boardMap[1][3] = new Tree;
    boardMap[1][4] = new Tree;
    boardMap[2][0] = new Car;
    boardMap[2][1] = new Tree;
    boardMap[2][2] = new Car;
    boardMap[2][3] = new Ground;
    boardMap[2][4] = new Tree;
    boardMap[3][0] = new Tree;
    boardMap[3][1] = new Ground;
    boardMap[3][2] = new House;
    boardMap[3][3] = new Tree;
    boardMap[3][4] = new House;
    boardMap[4][0] = new House;
    boardMap[4][1] = new Ground;
    boardMap[4][2] = new Ground;
    boardMap[4][3] = new Tree;
    boardMap[4][4] = new GrandmaHome;
    
    
    boardMap[0][1]->setDown(boardMap[1][1]);
    boardMap[0][1]->setLeft(boardMap[0][0]);
    boardMap[0][1]->setRight(boardMap[0][2]);

    boardMap[0][2]->setDown(boardMap[1][2]);
    boardMap[0][2]->setLeft(boardMap[0][1]);
    boardMap[0][2]->setRight(boardMap[0][3]);

    boardMap[0][3]->setDown(boardMap[1][3]);
    boardMap[0][3]->setLeft(boardMap[0][2]);
    boardMap[0][3]->setRight(boardMap[0][4]);

    boardMap[0][4]->setDown(boardMap[1][4]);
    boardMap[0][4]->setLeft(boardMap[0][3]);

    boardMap[1][0]->setUp(boardMap[0][0]);
    boardMap[1][0]->setDown(boardMap[2][0]);

    boardMap[1][0]->setRight(boardMap[1][1]);

    boardMap[1][1]->setUp(boardMap[0][1]);
    boardMap[1][1]->setDown(boardMap[2][1]);
    boardMap[1][1]->setLeft(boardMap[1][0]);
    boardMap[1][1]->setRight(boardMap[1][2]);
    
    boardMap[1][2]->setUp(boardMap[0][2]);
    boardMap[1][2]->setDown(boardMap[2][2]);
    boardMap[1][2]->setLeft(boardMap[1][1]);
    boardMap[1][2]->setRight(boardMap[1][3]);
    
    boardMap[1][3]->setUp(boardMap[0][3]);
    boardMap[1][3]->setDown(boardMap[2][3]);
    boardMap[1][3]->setLeft(boardMap[1][2]);
    boardMap[1][3]->setRight(boardMap[1][4]);
    
    boardMap[1][4]->setUp(boardMap[0][4]);
    boardMap[1][4]->setDown(boardMap[2][4]);
    boardMap[1][4]->setLeft(boardMap[1][3]);
    
    boardMap[2][0]->setUp(boardMap[1][0]);
    boardMap[2][0]->setDown(boardMap[3][0]);
    boardMap[2][0]->setRight(boardMap[2][1]);

    boardMap[2][1]->setUp(boardMap[1][1]);
    boardMap[2][1]->setDown(boardMap[3][1]);
    boardMap[2][1]->setLeft(boardMap[2][0]);
    boardMap[2][1]->setRight(boardMap[2][2]);

    boardMap[2][2]->setUp(boardMap[1][2]);
    boardMap[2][2]->setDown(boardMap[3][2]);
    boardMap[2][2]->setLeft(boardMap[2][1]);
    boardMap[2][2]->setRight(boardMap[2][3]);
    
    boardMap[2][3]->setUp(boardMap[1][3]);
    boardMap[2][3]->setDown(boardMap[3][3]);
    boardMap[2][3]->setLeft(boardMap[2][2]);
    boardMap[2][3]->setRight(boardMap[2][4]);

    boardMap[2][4]->setUp(boardMap[1][4]);
    boardMap[2][4]->setDown(boardMap[3][4]);
    boardMap[2][4]->setLeft(boardMap[2][3]);
    
    boardMap[3][0]->setUp(boardMap[2][0]);
    boardMap[3][0]->setDown(boardMap[4][0]);
    boardMap[3][0]->setRight(boardMap[3][1]);
    
    boardMap[3][1]->setUp(boardMap[2][1]);
    boardMap[3][1]->setDown(boardMap[4][1]);
    boardMap[3][1]->setLeft(boardMap[3][0]);
    boardMap[3][1]->setRight(boardMap[3][2]);

    boardMap[3][2]->setUp(boardMap[2][2]);
    boardMap[3][2]->setDown(boardMap[4][2]);
    boardMap[3][2]->setLeft(boardMap[3][1]);
    boardMap[3][2]->setRight(boardMap[3][3]);

    boardMap[3][3]->setUp(boardMap[2][3]);
    boardMap[3][3]->setDown(boardMap[4][3]);
    boardMap[3][3]->setLeft(boardMap[3][2]);
    boardMap[3][3]->setRight(boardMap[3][4]);

    boardMap[3][4]->setUp(boardMap[2][4]);
    boardMap[3][4]->setDown(boardMap[4][4]);            //location Grandma
    boardMap[3][4]->setLeft(boardMap[3][3]);

    boardMap[4][0]->setUp(boardMap[3][0]);
    boardMap[4][0]->setRight(boardMap[4][1]);

    boardMap[4][1]->setUp(boardMap[3][1]);
    boardMap[4][1]->setLeft(boardMap[4][0]);
    boardMap[4][1]->setRight(boardMap[4][2]);

    boardMap[4][2]->setUp(boardMap[3][2]);
    boardMap[4][2]->setLeft(boardMap[4][1]);
    boardMap[4][2]->setRight(boardMap[4][3]);
    
    boardMap[4][3]->setUp(boardMap[4][2]);
    boardMap[4][3]->setLeft(boardMap[4][2]);
    boardMap[4][3]->setRight(boardMap[4][4]);             //location Grandma
    
}

//returns boardMao
Space*** Board::getBoard(){
    
    return boardMap;
    
}

//prints board; where all of the Space subclasses are represented by emptyTile
//so user is not able to see the type of tile they land on
void Board::printBoard(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
             cout << boardMap[i][j]->getTile() << "|";
        }
        cout << endl;
    }
        cout << endl;
   
    
}

//sets all tiles to emptyTile
void Board::setEmptyTiles() {
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            boardMap[i][j]->setTile(emptyTile);
        }
       
    }
    
}

































