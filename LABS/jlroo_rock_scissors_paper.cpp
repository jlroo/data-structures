//
//  lab_1.cpp
//  COMP_271_PROJECT
//
//  Created by jlroo on 9/3/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

// 
//  main.cpp
//  COMP_271_LABS
//
//  Created by jlroo on 9/2/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

char get_comp_val(){
    srand(time(0));
    char letters[] = "rsp";
    char i = letters[rand() % 3];
    return i;
}

int main(){
    char comp_val;
    char user_val=NULL;
    cout << "We are going to play a game! Paper Scissors Rock!" << endl;
    cout << "On the count of three, you'll choose." << endl;
    cout << "For Rock, type an r. For Scissors, s. For Paper, p. or to quit, q";
    cout << "\n" << "1.. 2.. 3.." << endl;
    cin >> user_val;
    
    if (user_val!='q') {
        comp_val=get_comp_val();
        
        if(comp_val==user_val) {
            cout << "TIE!" << endl;
            return main();
        }
        else {
            if(comp_val=='r'){
                if(user_val=='s') {
                    cout << "Rock beats Scissor. You lose.\n";
                    return main();
                }
                else if (user_val=='p'){
                    cout << "Paper beats Rock. You win!\n";
                    return main();
                }
                
            }
            if(comp_val=='s'){
                if(user_val=='r'){
                    cout << "Rock beats Scissor. You win!\n";
                    return main();
                }
                else if (user_val=='p'){
                    cout << "Scissor beats Paper. You lose.\n";
                    return main();
                }
            }
            if(comp_val=='p'){
                
                if(user_val=='s'){
                    cout << "Scissor beats Paper. You win!\n";
                    return main();
                }
                else if(user_val=='r') {
                    cout << "Paper beats rock You lose.\n";
                    return main();
                }
            }
        }
    }
    else if (user_val=='q')
        cout << "Quitting thanks for playing" << endl;
    return 0;
}
