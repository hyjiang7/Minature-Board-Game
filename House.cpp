/******************************************************************************************
 ** Program name: Final Project House implementation
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains bandage, magic potion
 ******************************************************************************************/

#include "House.hpp"


//returns space type: "house"
string House::getSpaceType() {
    
    return "house";
    
}

/****************************************************************
 * Items available from House class: bandage, magic potion or nothing
 * bandage: 40% chance of finding ; heals 10 HP
 * magic potion: 40% chance of finding; grants one extra step
 * nothing: 20% chance of finding nothing
 * takes in Sally pointer to update Sally's stats
 * if user finds an item; user can use item now or save it to backpack
 ****************************************************************/
void House::setSpecialItem(Sally * sPtr) {
    
   int probably = randomNum(5);
    
    if( probably == 1 || probably == 2) {
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
    else if (probably == 3 || probably == 4) {
        cout << "You found a magic potion. You are granted one extra step " << endl;
        int c;
        cout << "Enter:\n"
        << "1. Save Item to backpack.\n"
        << "2. Use Item." << endl;
        c = inputValidation(1, 2);
        if ( c == 1) {
            sPtr->addItem("magic potion");
        }
        else {
                sPtr->setSteps(1);
            
        }
        
    }
    else {
        cout << "There is nothing around..." << endl;
    }
    
}
