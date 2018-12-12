/******************************************************************************************
 ** Program name: Final Project Game implementation
 ** Author:Helen Jiang
 ** Date: 3/16/18
 ** Description: Save Sally's Grandma: game flow
 ******************************************************************************************/

#include "Game.hpp"

/****************************************************************
 * constructor makes a new board and initializes member variables
 * to their appropriate values
 ****************************************************************/
Game::Game(){
    
    grandmaTile = "G ";
    sallyTile = "S ";
    emptyTile = "  ";
    sallyX = -1;
    sallyY = -1;
    moved = false;
    SallyPtr = NULL;
    win = false;
    board.makeBoard();
}

/****************************************************************
 * destructor to set pointers to NULL
 ****************************************************************/
Game::~Game(){

    SallyPtr = NULL;
    map =  NULL;
}
/****************************************************************
 * function allocates memory to make a new Sally object
 ****************************************************************/
void Game::makeSallyObject(){
    
    SallyPtr = new Sally;
    
}
/****************************************************************
 * initial setup of the game
 * sets all board tiles to their appropiate tiles
 * set win and moved to false for each game loop
 ****************************************************************/
void Game::setUpGame(){
    
    board.setEmptyTiles();
    map = board.getBoard();
    setSallyLocation(0, 0);
    setGrandmaLocation(4, 4);
    makeSallyObject();
    win = false;
    moved = false;
    
}

/****************************************************************
 * function takes in x and y coords to set Sally's location
 ****************************************************************/
void Game::setSallyLocation(int x, int y){
    sallyX = x;
    sallyY = y;
    map[sallyX][sallyY]->setTile(sallyTile);
}

/****************************************************************
 * function takes in x and y coords to set Grandma's location
 ****************************************************************/
void Game::setGrandmaLocation(int x, int y) {
    
    map[x][y]->setTile(grandmaTile);
    
}

/****************************************************************
 * function takes in x and y coords to set empty location
 ****************************************************************/
void Game::setEmptyTile(int x, int y){
    
    map[x][y]->setTile(emptyTile);
    
}

/****************************************************************
 * function takes in a direction user wants to move
 * checks to see if direction is movable
 * if so, return true, set new location to sally, and old location to empty tile
 * let uer know what kind of tile they arrived at,
 * takes away a step and dehydration
 * prints board of newly taken step
 * calls interspace function
 ****************************************************************/
bool Game::moveSally(int dir) {
    
    //move up
    if(dir == 1) {

        if( sallyX - 1 >= 0){
            sallyX = sallyX - 1;
            setEmptyTile(sallyX + 1, sallyY);
            setSallyLocation(sallyX, sallyY);
             cout << endl << endl << endl << endl;
            cout << "You arrived at a ..." << map[sallyX][sallyY]->getSpaceType() << endl;
            SallyPtr->setSteps(-1);
            SallyPtr->setDehydration(-1);
            board.printBoard();
            interactSpace();
            moved = true;
        }
        else {
            cout << "You cannot move that way. Please choose a different direction. " << endl;
            moved = false;
        }
    }
    //move down
    else if(dir == 2) {
        
        if(sallyX + 1 < 5){
            sallyX = sallyX + 1;
            setEmptyTile(sallyX - 1, sallyY);
            setSallyLocation(sallyX, sallyY);
             cout << endl << endl << endl << endl;
            cout << "You arrived at a ..." << map[sallyX][sallyY]->getSpaceType() << endl;
            SallyPtr->setSteps(-1);
            SallyPtr->setDehydration(-1);
            board.printBoard();
            interactSpace();
            moved = true;
        }
        else {
            cout << "You cannot move that way. Please choose a different direction. " << endl;
            moved = false;
        }
    }
    //move left
    else if(dir == 3) {
        
        if(sallyY - 1 >= 0){
            sallyY = sallyY - 1;
            setEmptyTile(sallyX, sallyY + 1);
            setSallyLocation(sallyX, sallyY);
             cout << endl << endl << endl << endl;
            cout << "You arrived at a ..." << map[sallyX][sallyY]->getSpaceType() << endl;
            SallyPtr->setSteps(-1);
            board.printBoard();
            SallyPtr->setDehydration(-1);
            interactSpace();
            moved = true;
        }
        else {
            cout << "You cannot move that way. Please choose a different direction. " << endl;
            moved = false;
        }
    }
    //move right
    else if(dir == 4){
        
        if(sallyY + 1 < 5){
            sallyY = sallyY + 1;
            setEmptyTile(sallyX, sallyY - 1);
            setSallyLocation(sallyX, sallyY);
             cout << endl << endl << endl << endl;
            cout << "You arrived at a ..." << map[sallyX][sallyY]->getSpaceType() << endl;
            SallyPtr->setSteps(-1);
            SallyPtr->setDehydration(-1);
            board.printBoard();
            interactSpace();
            moved = true;
        }
        else {
            cout << "You cannot move that way. Please choose a different direction. " << endl;
            moved = false;
        }
    }
    else {
        //if user wants to view backpack or use items; call useItems function
        useItems();
    }
    
    return moved;
}

/****************************************************************
 * function let users to view their backpack and use item
 * allows user to use as many items as they can
 * until user wants to quit
 ****************************************************************/
void Game::useItems (){
    int choice = 0;                                         //stores if they want to use items or exit
    int backpackSize = SallyPtr->getBackpackSize();         //size of backpack vector
    int use = 0;                                            //stores the item num they want to use
    
    SallyPtr->displayBackpack();
    
    //after each use of item; displays the stats and
    //remaining contents in the backpack
    if(backpackSize != 0){
        cout << "\n\nEnter:\n1. Use items" << endl
        << "2. Exit" << endl;
        choice = inputValidation(1, 2);
        while(choice == 1) {
            cout << "Enter the item number you will like to use: ";
            use = inputValidation(1, backpackSize);
            SallyPtr->useItem(use);
            SallyPtr->displayAllStats();
            
            SallyPtr->displayBackpack();
            backpackSize = SallyPtr->getBackpackSize();
            
            if(backpackSize != 0) {
                cout << "\n\nEnter:\n1. Use items" << endl
                << "2. Exit" << endl;
                choice = inputValidation(1, 2);
            }
            else {
                choice = 2;
            }
            
        }
    }
    //prints board to allow user to see where they want to take the next step
    cout << endl << endl << endl << endl;
    board.printBoard();
    
}
/****************************************************************
 * function is the same as moveSally; but function is only used when
 * user is driving car;
 * doesn't allow user to interact with the space type
 * doesn't take away a step or dehydration
 * returns true if Sally drove to a valid space
 ****************************************************************/
bool Game::driveSally(int d){
    bool drove = false;
    //move up
    if(d == 1) {
        if( sallyX - 1 >= 0){
            sallyX = sallyX - 1;
            setEmptyTile(sallyX + 1, sallyY);
            setSallyLocation(sallyX, sallyY);
             cout << endl << endl << endl << endl;
            cout << "You arrived at a ..." << map[sallyX][sallyY]->getSpaceType() << endl;
            board.printBoard();
            drove = true;
        }
        else {
            cout << "\nYou cannot drive that way. Please choose a different direction. " << endl;
            drove = false;
            
        }
       
    }
    //move down
    else if(d == 2) {
        
        if(sallyX + 1 < 5){
            sallyX = sallyX + 1;
            setEmptyTile(sallyX - 1, sallyY);
            setSallyLocation(sallyX, sallyY);
             cout << endl << endl << endl << endl;
            cout << "You arrived at a ..." << map[sallyX][sallyY]->getSpaceType() << endl;
            board.printBoard();
            drove = true;
            
        }
        else {
            cout << "\nYou cannot move that way. Please choose a different direction. " << endl;
            drove = false;
        }
        
    }
    //move left
    else if(d == 3) {
        
        if(sallyY - 1 >= 0){
            sallyY = sallyY - 1;
            setEmptyTile(sallyX, sallyY + 1);
            setSallyLocation(sallyX, sallyY);
             cout << endl << endl << endl << endl;
            cout << "You arrived at a ..." << map[sallyX][sallyY]->getSpaceType() << endl;
            board.printBoard();
            drove = true;
            
        }
        else {
            cout << "\nYou cannot move that way. Please choose a different direction. " << endl;
            drove = false;
        }
        
    }
    //move right
    else if(d == 4) {
        
        if(sallyY + 1 < 5){
            sallyY = sallyY + 1;
            setEmptyTile(sallyX, sallyY - 1);
            setSallyLocation(sallyX, sallyY);
             cout << endl << endl << endl << endl;
            cout << "You arrived at a ..." << map[sallyX][sallyY]->getSpaceType() << endl;
            board.printBoard();
            drove = true;
            
        }
        else {
            cout << "\nYou cannot move that way. Please choose a different direction. " << endl;
            drove = false;
        }
        
    }
    else {
        useItems();
        drove = false;
    }
  
    return drove;
}
/****************************************************************
 * function lets user interact with the appropriate Space type
 * calls the setSpecialItem function
 * if tree or house; asks user if they want to enter or look around
 ****************************************************************/
void Game::interactSpace(){
    
    if(map[sallyX][sallyY]->getSpaceType() == "ground") {
     
        map[sallyX][sallyY]->setSpecialItem(SallyPtr);
    }
    else if(map[sallyX][sallyY]->getSpaceType() == "car") {
        //if user encounter a car; asks user to make a move 2x
        //keeps looping if move is invalid
        //when they get off the car; it alows user to interact with space again
        map[sallyX][sallyY]->setSpecialItem(SallyPtr);
        if(SallyPtr->getFuel()) {
            for(int i = 0; i < 2; i++){
                SallyPtr->displayAllStats();
                int d = menu.actionChoice();
                //cout << endl << endl << endl << endl;
                bool drove = false;
                drove = driveSally(d);
                while(!drove){
                    d = menu.actionChoice();
                    //cout << endl << endl << endl << endl;
                    drove = driveSally(d);
                }
            }
            interactSpace();
        }
    }
    else if(map[sallyX][sallyY]->getSpaceType() == "house") {

            int choice = 0;
            cout << "\n\nEnter:\n1. Enter Door\n"
                 << "2. keep going" << endl;
            choice = inputValidation(1, 2);
            if( choice == 1){
                map[sallyX][sallyY]->setSpecialItem(SallyPtr);
        
            }
    }
    else if(map[sallyX][sallyY]->getSpaceType() == "tree"){
        int choice = 0;
        cout << "\n\nEnter:\n1. Look around\n"
        << "2. keep going" << endl;
        choice = inputValidation(1, 2);
        if( choice == 1){
            map[sallyX][sallyY]->setSpecialItem(SallyPtr);
        }
    }
    else if(map[sallyX][sallyY]->getSpaceType() == "grandma's house") {
        //if they get to grandma's house; set win to true
        map[sallyX][sallyY]->setSpecialItem(SallyPtr);
        win = true;
    }
    else {
        map[sallyX][sallyY]->setSpecialItem(SallyPtr);
    }
    
    
}

/****************************************************************
 * function sets game loop; starts by asking if play wants to play
 * keeps looping until user quits
 ****************************************************************/
void Game::gameLoop(){
    int start = 0;
   
    menu.welcomeMessage();
    start = menu.programStart();
    cout << endl << endl;
    
    while( start == 1){
        setUpGame();
        gamePlay();

        map = NULL;
        delete SallyPtr;
        start = menu.programStart();
    }
    
}

/****************************************************************
 * function takes care of prompting user to action and
 * calls appropriate function to take care of action
 ****************************************************************/
void Game:: gamePlay() {
    int direction;
    bool moved;
    cout << endl << endl << endl << endl;
    board.printBoard();
    do{
        
        direction = menu.actionChoice();
        moved = moveSally(direction);
        SallyPtr->displayAllStats();
        
        while(!moved){
            direction = menu.actionChoice();
            moved = moveSally(direction);
        }
        
        //gets the stats from Sally
        SallyHP = SallyPtr->getHP();
        SallyWaterSteps = SallyPtr->getDehydration();
        SallySteps = SallyPtr->getSteps();
        
        if (win == true) {
            cout << "Grandma: Wow, thanks Sally, I feel much better. You are the best." << endl;
        }
        else {
            //prints warning messages if certain stats are low
            if(SallyWaterSteps == 1){
                menu.warningMessage("HYDRATION");
            }
            if(SallyHP < 11){
                menu.warningMessage("HP");
            }
            if(SallySteps == 1){
                menu.warningMessage("STEPS");
            }
        }
        
    } while (SallyHP > 0 && SallySteps > 0 && SallyWaterSteps > 0 && !win);

    lastSave();

}


/****************************************************************
 * function gives user one last chance to same themselves
 * if they have items in their backpack
 ****************************************************************/
void Game::lastSave() {
    cout << "\n\n";
    if(win){
        cout << "******************************\n";
        cout << "* Congrats, you win the game *\n";
        cout << "*****************************" << endl << endl;
    }//end if
    else {
        bool saved = false;
        //checks to see if backpack has water and asks user if
        //they want to use it, take item from backpack
        //and set saved to true
        if(SallyWaterSteps <= 0 ){
            bool hasWater = false;
            int choice = 0;
            int itemNum = -1;
            
            hasWater = SallyPtr->checkItem("water");
            
            if(hasWater) {
                
                cout << "It seems like you have water in your backpack: "
                << "Enter 1 to use or 2 to quit: ";
                choice = inputValidation(1, 2);
                
                if ( choice == 1) {
                    itemNum = SallyPtr->findItemNumber("water");
                    SallyPtr->useItem(itemNum+1);
                    saved = true;
                }
                else{
                    cout << "Game over! You died of dehydration." << endl;
                }
            }
            else{
                cout << "Game over! You died of dehydration." << endl;
            }
            
        }//end of if
        
        //checks to see if backpack has magic potion
        if(SallySteps <= 0) {

            bool hasSteps = false;
            int choice = 0;
             int itemNum = -1;
            
            hasSteps = SallyPtr->checkItem("magic potion");
            
            if(hasSteps) {
                cout << "It seems like you magic potion in your backpack. "
                << "Enter 1 to use or 2 to quit: ";
                choice = inputValidation(1, 2);
                
                if ( choice == 1) {
                    itemNum = SallyPtr->findItemNumber("magic potion");
                    SallyPtr->useItem(itemNum+1);
                    saved = true;
                }
                else{
                    cout << "Game over! You ran out of steps." << endl;
                }
            }
            else{
                cout << "Game over! You ran out of steps." << endl;
            }
        }//end else if
        
        //checks to see if backpack has bandage
        if (SallyHP <= 0) {

            bool hasHP = false;
            int choice = 0;
             int itemNum = -1;
            
            hasHP = SallyPtr->checkItem("bandage");
            
            if(hasHP) {
                SallyPtr->displayBackpack();
                cout << "It seems like you have bandage in your backpack. "
                << "Enter 1 to use or 2 to quit: ";
                choice = inputValidation(1, 2);
                
                if ( choice == 1) {
                    itemNum = SallyPtr->findItemNumber("bandage");
                    SallyPtr->useItem(itemNum+1);
                    saved = true;
                }
                else{
                    cout << "Game over! You died from lack of HP" << endl;
                }
            }
            else{
                cout << "Game over! Youd died form lack of HP" << endl;
            }
            
        }//end else
        
        //if Sally was saved, called gamePlay(); to continue playing
        if(saved){
            gamePlay();
        }
    }
    
    
    
}

