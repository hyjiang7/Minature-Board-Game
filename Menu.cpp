/******************************************************************************************
 ** Program name: Final Project Menu Class
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma Menu implementation
 ******************************************************************************************/

#include "Menu.hpp"

Menu::Menu(){

    play = 0;
    choiceOfAction = -5;
}

//asks user if they want to play again
int Menu::programStart(){
    
    cout << "Would you like to play? Please enter 1 for yes and 2 for no. " << endl;
    play = inputValidation(1, 2);
    
    return play;
}

/****************************************************************
 * function describes game story and game rules
 ****************************************************************/
void Menu::welcomeMessage(){
    
    cout << "Oh no, Sally's grandma is really sick. Sally needs to bring Grandma\n"
    << "some special soup to save her from dying.\n"
    << "Unfortunately, there's a forest separating Sally and Grandma, and it is not a\n"
    << "typical forest. The forest is filled with booby traps, and bombs. It is your\n"
    << "job to get Sally safely through the forest to Grandma's house.\n"
    << endl << endl;
    
    cout << "Rules of the game:\n"
    << "Sally begins with 50 health points. Sally must avoid the booby traps and bombs.\n"
    << "However, if she encounters one or two traps, she is not to worry. She can find\n"
    << "houses, or trees that may have bandages to heal the damage. In addition, Sally\n"
    << "must navigate through the forest in 8 steps. There are magic potions that can\n"
    << "give extra step(s) and a car that will take you 2 steps, for a count of 1 step.\n"
    << "Lastly, Sally must drink water at least every 3 steps, or she will die of\n"
    << "dehydration. Help Sally survive by taking the first step.\n"
    << endl << endl;
}

/****************************************************************
 * function returns a the choice of action user wants to take
 * for every step
 ****************************************************************/
int Menu::actionChoice(){
    
    cout << "Please pick from one to the following options: " << endl
    << "1. Move up\n"
    << "2. Move down\n"
    << "3. Move left\n"
    << "4. Move right\n"
    << "5. View backpack or use items\n"
    << endl;
    
    choiceOfAction = inputValidation(1, 5);
    
    return choiceOfAction;
    
}

/****************************************************************
 * function gives a warning message specific to the stat
 ****************************************************************/
void Menu::warningMessage(string stat) {
    
    cout << "YOUR " << stat << " IS LOW. FIND/USE ITEM WITHIN THE NEXT STEP " << endl;
    
    
}



