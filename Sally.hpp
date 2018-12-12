/******************************************************************************************
 ** Program name: Final Project Sally Class
 ** Author:Helen Jiang
 ** Date:3/16/18
 ** Description: Sally class include stats: HP, water, steps and backpack to store items
 ** found from Space subclasses
 ******************************************************************************************/

#ifndef SALLY_HPP
#define SALLY_HPP

#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Sally {
private:
    int HP;                                 //stores HP stat: begins with 50
    int steps;                              //stores steps: begins with 8
    int waterSteps;                         //stores waterSteps: begins with 4
    vector<string> backpack;                //stores the item
    bool hasFuel;                           //returns true if backpack has fuel

    
public:
    Sally();                                //constructor to initialize all member variables
    ~Sally(){};                             //empty destructor
    void setHP(int);                        //changes HP
    int getHP();                            //returns HP
    
    void setDehydration(int);               //changes waterSteps
    void resetHydration();                  //resets hydration
    int getDehydration();                   //returns number of steps to dehydration
    
    void setSteps(int);                     //changes steps
    int getSteps();                         //returns steps
    
    void addItem(string);                   //add item to backpack
    void useItem(int);                      //use item from backpack

    bool getFuel();                         //returns true if backpack has fuel
    
    int getBackpackSize();                  //return size of backpack vector
    void displayBackpack();                 //displays the items in backpack vector
    
    void displayAllStats();                 //display HP, steps and waterSteps
    
    bool checkItem(string);                 //check to see if backpack has certain item
    
    int findItemNumber(string);             //find the element number the item is stored at
    
};

#endif 
