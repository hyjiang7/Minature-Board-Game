/******************************************************************************************
 ** Program name: Final Project Game implementation
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: game flow
 ******************************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Board.hpp"
#include "Menu.hpp"


class Game {
private:
    Board board;                                //board object to make the board
    Menu menu;                                  //menu object to use menu functions
    Space*** map;                               //stores the board
    string sallyTile;                           //stores "S "
    string grandmaTile;                         //stores "G "
    string emptyTile;                           //stores "  "
    int sallyX;                                 //stores X coord of Sally
    int sallyY;                                 //stores y coord of Sally
    bool moved;                                 //true if Sally moved a step
    bool win;                                   //true if Sally reaches Grandma
    
    Sally *SallyPtr;                            //pointer to new Sally object
    int SallyHP;                                //stores Sally HP stat
    int SallySteps;                             //stores Sally Steps stat
    int SallyWaterSteps;                        //stores Sally Water Steps
    
public:
    Game();
    ~Game();
    void makeSallyObject();
    void setUpGame();
    bool moveSally(int);
    
    bool driveSally(int);
    void useItems();
    void setEmptyTile(int, int);
    void setSallyLocation(int, int);
    void setGrandmaLocation(int, int);
    void interactSpace();
    void gameLoop();
    void gamePlay();
    void lastSave();
    
};


#endif /* Game_hpp */
