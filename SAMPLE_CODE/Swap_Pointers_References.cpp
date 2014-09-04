//
//  main.cpp
//  Pointers
//
//  Created by maria saenz on 8/20/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//

#include <iostream>
using namespace std;
//first swap
/*void swap(int x, int y)
{
    int t=x;
    x=y;
    y=t;
}*/

//second swap
/*void swap(int *x, int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}*/

//third swap

void swap (int &x, int &y){
    int t=x;
    x=y;
    y=t;
}

void assign_reference(){
    
    int  intOne;
    
    int &rSomeRef = intOne;
    
    
    
    intOne = 5;
    
    cout << "intOne:\t" << intOne << endl;
    
    cout << "rSomeRef:\t" << rSomeRef << endl;
    
    cout << "&intOne:\t"  << &intOne << endl;
    
    cout << "&rSomeRef:\t" << &rSomeRef << endl;
    
    
    
    int intTwo = 8;
    
    rSomeRef = intTwo;  // not what you think!
    
    cout << "\nintOne:\t" << intOne << endl;
    
    cout << "intTwo:\t" << intTwo << endl;
    
    cout << "rSomeRef:\t" << rSomeRef << endl;
    
    cout << "&intOne:\t"  << &intOne << endl;
    
    cout << "&intTwo:\t"  << &intTwo << endl;
    
    cout << "&rSomeRef:\t" << &rSomeRef << endl;
}

int main()
{
    int a=5; // example of memory location: 1eff
    int b=7; // example of memory location: 1edc
    
    //first swap and third swap
    swap(a,b);
    
    //second swap
    //swap(&a,&b);
    
    //This is the output
    cout<<"A is: "<<a<<" and B is : "<<b<<endl;
    
    //assign_reference();

    return 0;
}

