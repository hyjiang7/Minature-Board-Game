/******************************************************************************************
 ** Program name: Final Project House header
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains bandage, magic potion
 ******************************************************************************************/

#ifndef HOUSE_HPP
#define HOUSE_HPP
#include "Space.hpp"

class House: public Space {
    
public:
    House(){};                                              //empty constructor
    virtual ~House(){};                                     //empty destructor
    
    virtual string getSpaceType() override;                 //returns Space type: "house"
    virtual void setSpecialItem(Sally * sPtr) override;     //special item for Houses
};



#endif
