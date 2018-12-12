/******************************************************************************************
 ** Program name: Final Project Sally Class
 ** Author:Helen Jiang
 ** Date:3/16/18
 ** Description: Sally class include stats: HP, water, steps and backpack to store items
 ** found from Space subclasses
 ******************************************************************************************/

#include "Sally.hpp"

//constructor initializes member variables 
Sally::Sally() {
    HP = 50;
    steps = 8;
    waterSteps = 4;
    hasFuel = false;

}

//sets HP by taking in int; but max HP is still 50
void Sally::setHP(int hp) {
    
    if (HP + hp >= 50){
        HP = 50;
        cout << "you are healed to the max HP..." << endl;
    }
    else {
        HP = HP + hp;
    }
    
}

//returns HP
int Sally::getHP() {
    
    return HP;
    
}

//returns true if backpack has fuel
bool Sally::getFuel() {
    
    return hasFuel;
}

//sets wateps; mainly for decrementing for each step taken
void Sally::setDehydration(int d) {
    
    waterSteps = waterSteps + d;
    
}

//resets hydration after drinking water
void Sally::resetHydration() {
    
    waterSteps = 4;
    
}

//returns waterSteps
int Sally::getDehydration() {
    
    return waterSteps;
}

//sets the steps; decrements/increments by 1
void Sally::setSteps(int s) {
    
    steps = steps + s;
    
}

//return stpes
int Sally::getSteps() {
    
    return steps;
}

//adds an item to the backpack
void Sally::addItem(string item) {
    
    backpack.push_back(item);
    displayBackpack();
    cout << endl;
    
}

//uses one item and applies that item's use to Sally's Stats
void Sally::useItem(int itemNum) {
    itemNum = itemNum - 1;
    
    if(backpack.at(itemNum) == "water") {
        resetHydration();
    }
    else if (backpack.at(itemNum) == "magic potion") {
        setSteps(1);
    }
    else if(backpack.at(itemNum) == "bandage") {
        setHP(10);
    }
    else if(backpack.at(itemNum) == "fuel") {
        hasFuel = true;
    }
    
    //erase that item from backpack
    backpack.erase(backpack.begin()+itemNum);
    
    displayBackpack();
    cout << endl;
    
}

//returns backpack vector size
int Sally::getBackpackSize() {
        
    return backpack.size();
    
}

//displays the contents of the backpack if not empty
void Sally::displayBackpack() {
    cout << "Here are the contents of your backpack:\n";
    if( backpack.size() == 0){
        cout << "There are no items..." << endl;
    }
    for(int i = 0; i < backpack.size(); i++){
        cout << i + 1 << ". " << backpack[i] << endl;
    }
  
}

//display all stats of Sally
void Sally::displayAllStats() {
    
    cout << "******************************\n";
    cout << "HP points: " << HP << endl
         << "Steps: " << steps << endl
         << "Steps till dehydration: " << waterSteps << endl;
    cout << "******************************\n";
    
}

//check backpack to see if it has certain item, itemName
//returns true if it has item
bool Sally::checkItem(string itemName) {
    bool hasItem = false;
    
    for(int i = 0; i < backpack.size(); i++){
        if(backpack[i] == itemName){
            hasItem = true;
        }
    }
    
    return hasItem;
}

//returns the item number the item in the backpack
int Sally::findItemNumber(string itemName) {
    //set to -1 for easy debugging
    int itemNum = -1;
    
    for(int i = 0; i < backpack.size(); i++){
        if( backpack[i] == itemName) {
            itemNum = i;
        }
    }
    
    return itemNum;
}
