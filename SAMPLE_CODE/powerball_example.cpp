
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main() {
int i;
srand (time(NULL));//seed the random generator 
cout <<"***** Powerball Lotto *****";
cout << "Time to pick the winning numbers!\n";
 for(i=0;i<5;i++){
	cout << (rand()%59)+1<<" ";
}
cout << "\nAnd the Powerball is... "<<endl;
cout << (rand()%35)+1 << endl;
return 0;	
}