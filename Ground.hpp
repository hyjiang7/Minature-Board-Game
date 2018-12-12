/******************************************************************************************
 ** Program name: Final Project Ground header
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains booby traps, grenades
 ******************************************************************************************/

#ifndef Ground_hpp
#define Ground_hpp
#include "Space.hpp"

class Ground: public Space {

public:
    Ground(){};                                         //empty constructor
    virtual ~Ground(){};                                //empty destructor

    virtual string getSpaceType() override;             //returns Space type: "ground"
    virtual void setSpecialItem(Sally *) override;      //special items with ground
};



#endif
