//
//  HW_4.cpp
//  C++
//  FALL2014
//  Created by jlroo on 9/25/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//
#include "HW_4.h"

int main()  {
    char key;
    char infix[20];
    char postfix[20];
    char prefix[20];
    
    do {
        //WELCOME MESSAGE AND MENU OPTIONS
        cout << " * * * * * * * * * * * * * * * * * * *"<<endl;
        cout << " * Special Data Structures - Stacks  *"<<endl;
        cout << " * * * Convertion of Expressions * * *"  <<endl;
        cout << " *  Infix ---> Prefix [Press] (1)    *"  <<endl;
        cout << " *  Infix ---> Posfix [Press] (2)    *"  <<endl;
        cout << " *  To Exit            [Press](3)    *"  <<endl;
        cout << " * * * * Choose one option * * * * * *"<<endl;
        
        cin >> key;     //GET OPTION FOR THE SWICTH
        cin.ignore();
        
            switch (key) {
                
                case 49:{   //INFIX TO PREFIX CONVERTION
                    cout << "* * * *  CONVERTION   * * * *"  <<endl;
                    cout << "*     Infix->TO->Prefix     *"  <<endl;
                    cout << "* * * * * * * * * * * * * * *"  <<endl;
                    cout << ""<<endl;
                    cout << "Enter the Infix Expression:  "  <<endl;
                    cin >> infix;         // USER INPUT
                    cout << ""<<endl;
                    cout << "* * * * * * * * * * * * * * *"  <<endl;
                    cout << "The Prefix Expression is :"     <<endl;
                    intopre(infix,prefix);//CALL THE FUNCTION TO INTOPRE
                                          //TO CONVERT FROM INFIX TO PREFIX

                }
                    break;
            
                case 50:{   //INFIX TO POSTFIX CONVERTION
                    cout << "* * * *   CONVERTION  * * * *"  <<endl;
                    cout << "*     Infix->TO->Postfix    *"  <<endl;
                    cout << "* * * * * * * * * * * * * * *"  <<endl;
                    cout << ""<<endl;
                    cout << "Enter the Infix Expression:  "  <<endl;
                    cin >> infix;
                    cout << ""<<endl;
                    cout << "* * * * * * * * * * * * * * *"  <<endl;
                    cout << "The Posfix Expression is :"     <<endl;
                    intopost(infix,postfix);//CALL THE FUNCTION INTOPOST
                                            //TO CONVERT FROM INFIX TO POSTFIX
                }
                    break;
            
                case 51:{
                    cout << "!BYE!"<<endl;
                }
                    break;
            
                default:{
                    cout << "Not an option, try again or exit (3)"<<endl<<endl;
                }
            }
    
        }
    while (key!=51);
}