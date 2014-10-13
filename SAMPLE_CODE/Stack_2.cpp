//
//  Stack.cpp
//  LabFour
//
//  Created by maria saenz on 9/13/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//


#include <iostream>
#include "Stack.h"


using namespace std;



Stack::Stack(int size)
{
    top=-1;
    length=size;
    if(size == 0)
        p = 0;
    else
        p=new int[length];
}

Stack::~Stack()
{
    if(p!=0)
        delete [] p;
}

void Stack::push(int elem)
{
    if(p == 0)                //If the stack size is zero, allow user to mention it at runtime
    {
        cout<<"Stack of zero size"<<endl;
        cout<<"Enter a size for stack : ";
        cin >> length;
        p=new int[length];
    }
    if(top==(length-1))     //If the top reaches to the maximum stack size
    {
        cout<<"\nCannot push "<<elem<<", Stack full"<<endl;
        return;
    }
    else
    {
        top++;
        p[top]=elem;
    }
}
int Stack::pop()
{
    if(p==0 || top==-1)
    {
        cout<<"Stack empty!";
        return -1;
    }
    int ret=p[top];
    top--;
    length--;
    
    return ret;
}

void Stack::display()
{
  //1. Create a display function
}

bool Stack::isEmpty(){
    if (top==-1){
        return true;
    }
    return false;
}

void Stack::copy(Stack& dest){
    //2. Create a copy function
}

int main(){
    Stack B; //We are creating a stack of size 'zero'
    Stack A;
    B.push(1);
    B.push(2);
    B.push(3);
    B.push(4);
    B.push(5);
    cout << "Copy B into A and Display\n"<<endl;
    B.copy(A);
    //3.Write Display A and Display B
    return 1;
}