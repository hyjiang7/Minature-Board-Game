/******************************************************************************************
 ** Program name: Final Project Space implementation
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: abstract class, representing every tile
 ******************************************************************************************/
#include "Space.hpp"

//initializes member variables to NULL or empty ""
Space::Space() {
    up = NULL;
    down = NULL;
    right = NULL;
    left = NULL;
    tile = " ";
  
}
//destructor to set all pointers to NULL
Space::~Space(){
    up = NULL;
    down = NULL;
    right = NULL;
    left = NULL;
}

//links the Spaces together by taking in the type of Space
void Space::setUp(Space *u) {
    up = u;
    
}
void Space::setDown(Space *d) {
    
    down = d;
}
void Space::setLeft(Space *l) {
    
    left = l;
}
void Space::setRight(Space *r) {
    right = r;
    
}

string Space::getTile() {
    
    return tile;
    
}

//sets the tile type by taking in string t
void Space::setTile(string t){
    tile = t;
    
}



