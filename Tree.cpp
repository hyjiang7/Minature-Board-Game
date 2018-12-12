/******************************************************************************************
 ** Program name: Final Project Tree implementation
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains bandage, water, fuel
 ******************************************************************************************/

#include "Tree.hpp"
//returns "tree" for Space type
string Tree::getSpaceType() {
    
    return "tree";
    
}

/****************************************************************
 * Items available from Tree class: bandage, water, fuel or nothing
 * bandage: 12.5% chance of finding ; heals 10 HP
 * water: 50% chance of finding; keeps hydrated for 3 steps
 * fuel: 25% chance of finding; allows user to drive car
 * nothing: 12.5% chance of finding nothing
 * takes in Sally pointer to update Sally's stats
 * if user finds an item; user can use item now or save it to backpack
 ****************************************************************/
void Tree::setSpecialItem(Sally * sPtr) {
    
 int probably = randomNum(8);
    
    if( probably == 1) {
        cout << "You found a bandage! It will heal you by 10 points. " << endl;
        int c;
        cout << "Enter:\n"
        << "1. Save Item to backpack.\n"
        << "2. Use Item." << endl;
        c = inputValidation(1, 2);
        if ( c == 1) {
            sPtr->addItem("bandage");
        }
        else {
            sPtr->setHP(10);
        }
    }
    else if (probably == 3 || probably == 5 || probably == 6 || probably == 4) {
        cout << "You found a small bottled water. Keeps you hydrated for 3 steps. " << endl;
        int c;
        cout << "Enter:\n"
        << "1. Save Item to backpack.\n"
        << "2. Use Item." << endl;
        c = inputValidation(1, 2);
        if ( c == 1) {
            sPtr->addItem("water");
        }
        else {
            sPtr->resetHydration();
        }

    }
    else if (probably == 7 || probably == 2) {
         cout << "You found a small tank of fuel. It is now saved to your backpack. " << endl;
        sPtr->addItem("fuel");
    }
    else {
        cout << "There is nothing around..." << endl;
    }

}


