/******************************************************************************************
 ** Program name: Final Project Tree header
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: subclass of Space; contains bandage, water, fuel
 ******************************************************************************************/
#ifndef Tree_hpp
#define Tree_hpp

#include "Space.hpp"

class Tree: public Space {

public:
    Tree(){};                                                 //empty constructor
    virtual ~Tree(){};                                        //empty destructor
    
    virtual string getSpaceType() override;                   //returns the space type: tree
    virtual void setSpecialItem(Sally *) override;            //special item for trees
  
    
};


#endif
