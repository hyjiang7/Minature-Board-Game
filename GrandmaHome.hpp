/******************************************************************************************
 ** Program name: Final Project Grandma header
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains grandma's house
 ******************************************************************************************/

#ifndef GRANDMAHOME_HPP
#define GRANDMAHOME_HPP

#include "Space.hpp"

class GrandmaHome: public Space {
    
public:
    GrandmaHome(){};                                        //empty constructor
    virtual ~GrandmaHome(){};                               //empty destructor
    virtual string getSpaceType() override;                 //returns space type "grandma's house"
    virtual void setSpecialItem(Sally * sPtr) override;     //sets grandma's special item
    
};

#endif
