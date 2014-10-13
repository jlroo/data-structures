#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int stack_array[7];
	int top=-1; //shows its empty
	int val=1;
	int stack_limit=6;
	
	while(top<7){
		stack_array[top+1]=top+1;
		top++;
	}


	/*while(top<7){
	 if((top+1)<stack_limit){
		stack_array[top+1]=top+1;
		top++;
	   }
	 else{
		break;
	  }
	}*/
	/*while(top<7){
     	while(val%2==0) val++;
		stack_array[top+1]=val;
		val++;
		top++;
	}*/
	
	for(int i=0; i<top; i++){
		cout<<stack_array[i]<<endl;
	}
	
	return 1;
}
