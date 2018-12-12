/******************************************************************************************
 ** Program name: Final Project Ground implementation
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains booby traps, grenades
 ******************************************************************************************/
#include "Ground.hpp"

//returns Space type: "ground"
string Ground::getSpaceType() {
    
    return "ground";
    
}

/****************************************************************
 * Items available from Ground class: bobby traps, grenades
 * bobby traps: 67% chance of finding; minus 15 HP
 * grenades: 33% chance of finding: minus 25 HP
 * takes in Sally pointer to update Sally's stats
 * if user finds an item; user can use item now or save it to backpack
 ****************************************************************/
void Ground::setSpecialItem(Sally * sPtr) {
    int probably = randomNum(3);
    
    if(probably == 1 || probably == 3){
        //small bomb
        cout << "Oh no, you stepped on a bobby trap. Minus 15 health points. " << endl;
        sPtr->setHP(-15);
    }
    else {
        //big bomb
        cout << "Oh no, you activated a grenade. Minus 25 health points. " << endl;
        sPtr->setHP(-25);
    }
    
}
