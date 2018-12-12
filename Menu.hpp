/******************************************************************************************
 ** Program name: Final Project Menu Class
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma Menu
 ******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "Utility.hpp"
#include <string>
using std::string;

class Menu {
    
private:
    int play;                                   //stores if user wants to play or quit
    int choiceOfAction;                         //stores the action user wants to perform
    
public:
    Menu();                                     //initializes member variables
    void welcomeMessage();                      //describes game story/ rules
    int programStart();                         //asks user if they want to enter a value again
    int actionChoice();                         //displays the menu user can take
    void warningMessage(string);                //displays a warning message for a certain stat
                   
    
};

#endif /* Menu_hpp */
