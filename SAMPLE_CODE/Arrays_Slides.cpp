//
//  main.cpp
//  Arrays
//
//  Created by maria saenz on 8/21/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//

#include <iostream>

using namespace std;


void int_array_ex(){
    int arrayA[3];
    arrayA[0]=4;
    arrayA[1]=3;
    arrayA[2]=-1;
    cout<<arrayA[0]*arrayA[2]<<endl;
}

void char_array_ex(){
    char arrayB[7];
    arrayB[0]='L';
    arrayB[1]='o';
    arrayB[2]='y';
    arrayB[3]='o';
    arrayB[4]='l';
    arrayB[5]='a';
    cout<<arrayB<<endl;
}

void array_multiple_two(){
	cout<<"-----------------"<<endl;
    int arrayI[10];	//create array of ints
    int i=0;
    
    //put data in it
    for(i=0; i<10; i++)
    {
        arrayI[i]=i*2;
    }
	//print me!
    for(i=0; i<10; i++)
    {
        cout << arrayI[i] << endl;
    }
}

void sum_multiple_two(){
	cout<<"-----------------"<<endl;
    int arrayI[10];	//create array of ints
    int i=0;
	int sum=0;
	
    //put data in it
    for(i=0; i<10; i++)
    {
        arrayI[i]=i*2;
    }
    
    for(i=0; i<10; i++)
    {
        arrayI[i]=i*2;
        sum+=arrayI[i];
    }
    
    cout << sum << endl;
}

void array_two_d(){
	
	int arrayJ[2][3];
    arrayJ[0][0]=4;
    arrayJ[0][1]=3;
    arrayJ[0][2]=-1;
    arrayJ[1][0]=9;
    arrayJ[1][1]=-2;
    arrayJ[1][2]=0;
	cout<<"I am in row 1 column 2 "<<arrayJ[1][2]<<endl;
}

void dynamic_one_d(){
	int * array_pointer;
    array_pointer=new int[3]; //put some memory on heap of size 3
    array_pointer[0]=4;
    array_pointer[1]=3;
    array_pointer[2]=-1;
    cout<<"dynamic_one_d function "<<array_pointer[0]*array_pointer[2]<<endl;
    delete [] array_pointer; //with every new have to have a delete
}

void dynamic_two_d(){
	int ** array_twod; //point to two areas of memory
    array_twod=new int*[2]; //rows set only
    array_twod[0]=new int[3]; //3 columns for row 0
    array_twod[1]=new int[3];// 3 columns for row 1
    
    delete [] array_twod[0]; //get rid of row 0 and the columns in them
    delete [] array_twod[1]; //get rid of row 1  and the columns in them
    delete []  array_twod; //get rid of array pointer itself
    
}

void dynamic_two_d_forloop(){
    int ** array_twodd;
    array_twodd=new int * [2]; //rows set
    for (int i=0; i<2; i++){  //so for every row create a column of size 3
        array_twodd[i]=new int[3];
    }
    for (int i=0; i<2; i++){  //so for every row create a column of size 3
        cout<<"Memory for index (i): "<<i<<" The memory address: "<<&array_twodd[i]<<endl;
        for (int j=0; j<3; j++){
         cout<<"Memory for index (j): "<<j<<" The memory address: "<<&array_twodd[i][j]<<endl;
        }
        cout<<endl;
    }
    
    /***
     Do whatever you want with your 2D array when done, you must do below
     ***/
    
    for (int j=0; j<2; j++){
        delete [] array_twodd[j]; //delete every column instantiated
    }
    delete [] array_twodd; //get rid of the rest of the array
}

void dynamic_three_d_forloop(){
	int num_rows=3;
	int num_cols=3;
	int depth=6;
	int *** arrayI;
	
	arrayI=new int ** [num_rows];
    
	for(int i=0; i<num_rows; i++)
	{
		arrayI[i]=new int * [num_cols];
		for(int j=0; j<num_cols; j++)
		{
			arrayI[i][j]=new int [depth];
		}
	}
	
	for(int i=0; i<num_rows; i++)
	{
		for(int j=0; j<num_cols; j++)
		{
			delete [] arrayI[i][j];
		}
		delete [] arrayI[i];
	}
	delete [] arrayI;
}
int main()
{
	int_array_ex();
	cout<<"-----------------"<<endl;
	char_array_ex();
   	cout<<"-----------------"<<endl;
    char thestring[]={'L', 'o', 'y', 'o', 'l', 'a', '\0'};
	for (int p=0; p<sizeof(thestring); p++){
		cout<<" STRINGER:" <<thestring[p]<<endl;
	}
    cout<<thestring<<endl;
	cout<<thestring[2]<<thestring[2+1]<<endl;
    cout<<"-----------------"<<endl;
    array_multiple_two();
    cout<<"-----------------"<<endl;
    sum_multiple_two();
    cout<<"-----------------"<<endl;
	array_two_d();
    cout<<"-----------------"<<endl;
    //The HARDER STUFF
	dynamic_one_d();
    cout<<"-----------------"<<endl;
	dynamic_two_d();
	cout<<"-----------------"<<endl;
	dynamic_two_d_forloop();
	cout<<"-----------------"<<endl;
	dynamic_three_d_forloop();
	cout<<"-----------------"<<endl;
    return 0;
}