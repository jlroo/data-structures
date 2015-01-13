

#include <iostream>
#include "jlroo_Stack.h"
using namespace std;

class stack_class {

private:
    char * stack_name;
    int stack_size;
public:
    stack_class(char stact_name, int stack_size);
    //getters
    double get_length();
    char * get_rect_name();
    
    //setters
    bool set_length(double l);
    bool set_rect_name(char * n);
};

 Stack::Stack(int size) {
    
    top=-1;
    length=size;
    if(size == 0)
        p = 0;
    else
        p=new int[length];
}

Stack::~Stack() {
    
    if(p!=0)
        delete [] p;
}

void Stack::push(int elem) {
   
    if(top==(length-1))     //If the top reaches to the maximum stack size
    {
        cout<<"\nCannot push "<<elem<<", Stack full"<<endl;
        return;
    }
    else {
        top++;
        p[top]=elem;
    }
}

int Stack::pop() {
    
    if(p==0 || top==-1) {
        
        cout<<"Stack empty!";
        return -1;
    }
    
    int ret=p[top];
    top--;
    length--;
    
    return ret;
}

void Stack::display() {
    int i;
    {
        if (top == -1)
        {
            cout<<("Stack is empty\n");
            return;
        }
        else
        {
            cout<< ("\nStack status is:\n");
            for (i = top; i >= 0; i--)
            {
                cout<< (p[i]);
            }
           
        }
        cout<<("\n");
    }
    
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
    //initialize user input variables
    char key;
    int user_lenght;
    string user_name;
    
    do {
        
        //welcome message and menu options
        cout << "Welcome to PUSH, POP and DISPLAY"<<endl<<endl;
        cout << "Lets start"<< endl;
        cout << "To PUSH    press (1)"<<endl;
        cout << "To POP     press (2)"<<endl;
        cout << "To DISPLAY press (3)"<<endl;
        cout << "To EXIT    press (4)"<<endl<<endl;
        cout << "Choose one:"<<endl;
        
        cin >> key; //get option for the swicth
        
        switch (key) {
                
            case 49:{
                cout<<"Stack of zero size"<<endl;
                cout<<"Enter a size for stack : ";
                cin >> user_lenght;
                cout<<"Enter a name for the stack: ";
                cin >> user_name;
                Stack::Stack(user_lenght);

                
            }
                break;
                
            case 51:{
                //pop
                
            }
                break;
            
            case 52:{
                //display
                
            }
                break;

            case 53:{
                cout << "Thank you!"<<endl<<endl;
            }
                break;
            default:{
                cout << "Not an option, try again or exit (2)"<<endl<<endl;
            }
                
        }
    }
    while (key!=53);
}