//
//  HW_4.h
//  C++
//  FALL2014
//  Created by jlroo on 9/25/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#ifndef __C____HW_4__
#define __C____HW_4__
#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;

//GET IN STACK PRIORITY

int isp(char ch){

    switch (ch) {
        case '+':           //IF THE OPERATION ARE '+' OR '-' RETURN 1
        case '-':return 1;  //
        case '*':           //IF THE OPERATION ARE '*' OR '/' RETURN 2
        case '/':return 2;  //
        case '^':return 3;  //IF THE OPERATION IS '^' RETURN 3
        case '(':return 0;  //IF THE OPERATION IS '(' RETURN 0
        case '#':return -2; //IF THE OPERATION IS '#' RETURN -2 THE END OF THE STACK (POP ALL)
    }
    return 1;
}

//TO GET IN STACK PRIORITY

int icp(char ch){
    
    switch (ch) {
        case '+':           //IF THE OPERATION ARE '+' OR '-' RETURN 1
        case '-':return 1;  //
        case '*':           //IF THE OPERATION ARE '*' OR '/' RETURN 2
        case '/':return 2;  //
        case '^':return 3;  //IF THE OPERATION IS '^' RETURN 3
        case '(':return 4;  //IF THE OPERATION IS '(' RETURN 4
    }
    return 1;
}

void intopost (char infix[20], char postfix[20]) { //GET USER INPUT
    //INITIALIZE VARIABLES
    int i=0;
    char ch;
    char x;
    stack <char> s;
    s.push('#');
    
    while (infix[i]!='\0') { //TAKE THE CHARCTERS UNTIL THE END OF THE INPUTED EXPRESSION
        
        ch=infix[i];
        i++;
        
        if(ch>='a'&&ch<='z') { //THIS IS THE OPERAND
                cout<<ch;
        }

        else {  //HERE STARTS THE OPERATOR
     
            if(ch=='(') {
                
                while ((s.top()='(')) { //SCAN THE TOP OF THE STACK
                    x = s.top();        //ASSIGN IT TO X
                    cout<<x;            //PRINT OUT X
                }
                x = s.top();
            }
            
        else {
            
            while (isp(s.top())>=icp(ch)) { //CHECK THE STACK WITH OPERATION PRIORITY
                x = s.top();                //ASSIGN THE TOP TO X
                cout<<x;                    //PRINT OUT X
            }
            s.push(ch);                     //PUSH THE OPERATOR
        }
       }
    }
    while (!s.empty()) {                    //SCAN IF THE STACK IS EMPTY
        x = s.top();                          //ASSIGN THE TOP TO X
        if (x!='#') {                       //SCAN THAT X IS NOT EQUAL TO '#' (POP ALL) THE END OF THE STACK
            cout<<x;
        }
        
    }
}

void intopre(char infix[20], char prefix[20]) { //GET USER INPUT
    
    //INITIALIZE VARIABLES
    int i=0;
    int j=0;
    char ch;
    char x;
    stack <char> s;
    s.push('#');
    i = strlen(infix)-1;
    
    while (i!=-1) {
        
        ch = infix[i];
        i--;
        if (ch=='(') { // CHARCK THE OPERATOR STARTS HERE
            while (s.top()!=')') {
                x = s.top();         //POP THE STACK AND ASSING IT TO X
                prefix[j]=x;      //ASSIGN TO X RO PREFIX AT LOCATION [J]
                j++;
            }
            x = s.top();             //WHEN IS DONE POP THE STACK
    }
        else {
        
            while(isp(s.top())>icp(ch)){    //CHECK THE STACK WITH OPERATION PRIORITY
                x = s.top();                  //POP THE STACK ASSIGN IT TO X
                prefix[j]=x;                //ASSIGN X TO THE PREFIXA  AT LOCATION [J]
                j++;
            }
            s.push(ch);
        }
        while (!s.empty()) {         //CHECK IF IS DONE IS NOT CONTINUE
            x = s.top();               //POP THE STACK AND ASSING IT TO X
            if (x!='#') {           //SCAN THAT X IS NOT EQUAL TO '#' (POP ALL) THE END OF THE STACK
                prefix[j]=x;        //ASSIGN VALUES OF X TO PREFIX AT LOCATION [J]
                j++;
            }
        prefix[j]='\0';
        strlen(prefix);

        }
    }
}
#endif /* defiisEmpty____HW_4__) */