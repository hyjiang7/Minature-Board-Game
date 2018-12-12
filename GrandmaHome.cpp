/******************************************************************************************
 ** Program name: Final Project Grandma implementation
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains grandma's house
 ******************************************************************************************/
#include "GrandmaHome.hpp"

//returns Space type: "grandma's house"
string GrandmaHome::getSpaceType() {
    
    return "grandma's house";
    
}

/****************************************************************
 * function lets user feed grandma the soup to save grandma
 * from dying 
 ****************************************************************/
void GrandmaHome::setSpecialItem(Sally * sPtr) {
    int feed;
    cout << "You arrived safely to grandma's house. "
    << "Enter:\n 1. To feed her the special soup. ";
    feed = inputValidation(1, 1);
    
}

