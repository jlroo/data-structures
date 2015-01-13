#include <iostream>
#include "jlroo_Cqueue.h"

using namespace std;

int main()
{
    //here's some code to test your solution
    Cqueue Q;
    Q.Add(1);
    Q.Add(14);
    Q.Add(17);
    Q.write_Cqueue_to_Console();
    Q.Delete();
    Q.write_Cqueue_to_Console();
    Q.Add(20);
    Q.Add(22);
    Q.Add(29);
    Q.write_Cqueue_to_Console();
    Q.Delete();
    Q.Delete();
    Q.Add(34);
    Q.Add(39);
    Q.write_Cqueue_to_Console();
    return 0;
}

