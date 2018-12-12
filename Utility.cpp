/******************************************************************************************
 ** Program name: Final Project Utility Functions
 ** Author:Helen Jiang
 ** Date:3/16/18
 ** Description: Utility Functions include random number generator and input validation
 ******************************************************************************************/

#include "Utility.hpp"

/****************************************************************
 * function returns a random number between 1 and n
 ****************************************************************/
int randomNum(int n ){
    
    return rand() % n + 1;
    
}

/****************************************************************
 * function validates an input between lower and upper bound
 ****************************************************************/
int inputValidation(int min, int max){
    
    int vInt;
    cin >> vInt;
    
    while ( cin.fail() || vInt < min || vInt > max ){
        if (cin.fail()){                                        //if vInt is not of integer type
            
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a valid number between " << min << " and " << max << " ." << endl;
            cin >> vInt;
            
        }
        else if ( vInt < min || vInt > max){              //if vInt is not within bound
            
            cout << "Please enter a valid number between " << min << " and " << max << " ." << endl;
            cin >> vInt;
            
        }
    }
    
    return vInt;
    
}

/****************************************************************
 * function validates an input of integer type
 ****************************************************************/
int intValidation(){
    
    int v;
    
    cin >> v;
    
    while(cin.fail()){                                  //if v is not of integer type
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a valid input. " << endl;
        cin >> v;
    }
    
    return v;
    
}


