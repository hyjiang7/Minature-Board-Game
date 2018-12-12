/******************************************************************************************
 ** Program name: Final Project Start implementation
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains starting tile
 ******************************************************************************************/

#include "Start.hpp"
//returns "Start"
string Start::getSpaceType() {
    
    return "start";
    
}


/****************************************************************
 * function does not hav any times because the tile is the starting
 * position for Sally
 ****************************************************************/
void Start::setSpecialItem(Sally * sPtr) {
    
    cout << "You arrived back at the starting location..." << endl;
    
}
