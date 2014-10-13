#include <iostream>
#include <queue>
using namespace std;



void example_one(){
  queue<int> myqueue;

  myqueue.push(12);
  myqueue.push(75);   // this is now the back

  myqueue.back() -= myqueue.front();

  cout << "myqueue.back() is now " << myqueue.back() << endl;
	
}

void example_two(){
	queue<int> myqueue;
 	int myint;
 	cout << "Please enter some integers (enter 0 to end):\n";
	cin >> myint;
 	while(myint) {cin >> myint; myqueue.push (myint);}
	cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
   	cout << " " << myqueue.front();
   	myqueue.pop();
	}
}

int main ()
{ 
	cout<<" Example ONE"<<endl;
	example_one();
	cout<<" Example TWO"<<endl;
	example_two();
  return 0;
}