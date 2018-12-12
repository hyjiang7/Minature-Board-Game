/******************************************************************************************
 ** Program name: Final Project Space header
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: abstract class, representing every tile
 ******************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include <string>
#include "Utility.hpp"
#include "Sally.hpp"
using std::string;
using std::cout;
using std::endl;
using std::cin;

class Space {
    
protected:
    Space *up;                                  //pointer to adjacent Spaces
    Space *down;
    Space *left;
    Space *right;
    string tile;                                //stores the type of tile a Spacce is: empty, Sally, Grandma
    
    
   
public:
    Space();                                    //initializes member variables to NULL or empty ""

    void setUp(Space *);                        //links the Spaces together by taking in the type of Space
    void setDown(Space *);
    void setLeft(Space *);
    void setRight(Space *);
    
    void setTile(string);                       //sets the type of Space; changes as Sally moves acrosses the board
    string getTile();                           //returns the type of space

    virtual string getSpaceType() =0;           //returns the type of space: car, tree, house, ground, grandma, start
    virtual void setSpecialItem(Sally *) =0;    //special item each Space has
    
    virtual ~Space();                           //virtual destructor
    
};


#endif
