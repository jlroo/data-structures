/*
 * Stacks.cpp
 *
 *  Created on: Feb 8, 2014
 *      Author: mdcsaenz
 */

#include<iostream>
#include<string>
#include<stack>
#include<string>

using namespace std;

void
example_one();
void
example_two();
void
example_three();

int
main()
{
  example_one();
  cout << "Example Two Below:"<< "\n"<<endl;
  example_two();
  cout << "Example Three Below:\n"<<endl;
  example_three();
  return 0;
}

void example_one() {
  stack<int> mystack;
  mystack.push(10);
  mystack.push(20);
  cout << "mystack.pop() is " << mystack.top() << endl;
  mystack.top() -= 5;
  cout << "mystack.pop() is " << mystack.top() << endl;
}

void example_two() {
  stack<int> myints;
  cout << "0. size: " << (int) myints.size() << endl;
  for (int i = 0; i < 5; i++)
    myints.push(i);
  cout << "1. size: " << (int) myints.size() << endl;
  myints.pop();
  cout << "2. size: " << (int) myints.size() << endl;
}

void example_three() {
  stack<int> mystack;
  int sum = 0;
  for (int i = 1; i <= 10; i++)
    {
      mystack.push(i);
      //cout<<i<<"\n"<<endl;
    }
  while (!mystack.empty())
    {
      sum += mystack.top();
      cout<<"What is my top? "<<mystack.top()<<endl;
      mystack.pop();
    }
  cout << "total: " << sum << endl;
  cout <<"Is empty? "<< mystack.empty() << endl;

}