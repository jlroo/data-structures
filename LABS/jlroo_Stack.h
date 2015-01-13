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