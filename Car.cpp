/******************************************************************************************
 ** Program name: Final Project Car implementation
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains 2 steps
 ******************************************************************************************/

#include "Car.hpp"

//returns Space type: "car"
string Car::getSpaceType() {
    
    return "car";
    
}

/****************************************************************
 * Cars allow users to take 2 steps for the "price" of 1
 * doesn't allow for interacting with Spaces inside a car
 * must have fuel in backpack in order to use car
 ****************************************************************/
void Car::setSpecialItem(Sally * sPtr) {
    
    bool hasFuel;                   //stores true if backpack has fuel
    int itemNum;                    //stores the element number the fuel is stored in 
    
    //check to see if Sally has fuel; if so, use item from backpack
    hasFuel = sPtr->checkItem("fuel");
    
    if(hasFuel){
        
        cout << "Congrats you have fuel in your backpack.\n"
        << "The fuel is just enough to go two steps." << endl;
        itemNum = sPtr->findItemNumber("fuel");
        sPtr->useItem(itemNum+1);
        
    }
    else {
        cout << "uhoh, you don't have any fuel for the car." << endl;
    }
    
    
}
