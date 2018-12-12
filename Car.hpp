/******************************************************************************************
 ** Program name: Final Project Car header
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains 2 steps
 ******************************************************************************************/
#include "Space.hpp"

#ifndef CAR_HPP
#define CARP_HPP

class Car: public Space {

public:
    Car(){};                                                    //empty constructor
    virtual ~Car(){};                                           //empty destructor
    
    virtual string getSpaceType() override;                     //returns Space type: "car"
    virtual void setSpecialItem(Sally * sPtr) override;         //special item for cars
};


#endif
