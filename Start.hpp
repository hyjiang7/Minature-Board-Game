/******************************************************************************************
 ** Program name: Final Project Start header
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains starting tile
 ******************************************************************************************/

#ifndef START_HPP
#define START_HPP
#include "Space.hpp"

class Start: public Space {

public:
    Start(){};                                              //empty constructor
    virtual ~Start(){};                                     //empty destructor
    virtual string getSpaceType() override;                 //returns "start"
    virtual void setSpecialItem(Sally * sPtr) override;     //special item for Start class
    
};

#endif /* Start_hpp */
