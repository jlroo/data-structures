//
//  Stack.h
//  LabFour
//
//  Created by maria saenz on 9/13/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//

#ifndef LabFour_Stack_h
#define LabFour_Stack_h


class Stack
{
private:
    int *p;
    int top,length;
    
public:
    Stack(int = 0);
    ~Stack();
    void push(int);
    int pop();
    void display();
    bool isEmpty();
    void copy(Stack& stack);
};


#endif
