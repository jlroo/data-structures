#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

//get data
void read(int A[], int n) {
    int i;
    for(i=0; i<n; i++)
        cin >> A[i];
}

//show data
void display(int A[], int n) {
    int i;
    for(i=0; i<n; i++)
        cout << A[i] << " ";
}

int fibo(int n) {
    if(n==0 || n==1)
        return 1;
    else
        return(fibo(n-1)+fibo(n-2));
}

int Fibonacci_Search(int *A,int n, int val) {
    int f1,f2,t,mid,j,f;
    j=1;
    while(fibo(j) <= n) {           //find fib(j) such that fib(j)>=n
        j++;
    }
    f=fibo(j);
    f1=fibo(j-2);                   //find lower Fibonacci numbers
    f2=fibo(j-3);                   // f1=fib(j-2), f2=fib(j-3)
    mid=n-f1+1;
    while(val!=A[mid]){             // if not found
        if(mid<0||val>A[mid]){
                                    //look in lower half
            if(f1 == 1)
                return -1;
            mid = mid+f2;           //decrease Fibonacci numbers
            f1 = f1-f2;
            f2 = f2-f1;
        }
        else{                       //look in upper half
            if(f2 == 0)             //if not found return -1
                return -1;
            mid = mid-f2;           //decrease fibonacci numbers
            t = f1-f2;              //this time, decrease more
            f1 = f2;                //for smaller list
            f2 = t;
        }
    }
    return mid;
}

int Binary_Search(int *A,int low,int high,int val) {
    int mid;
    if(low<=high) {
        mid=(low+high)/2;
        if(A[mid] == val) {
            //cout<<"\n\t Found";
            return mid;
        }
        else if(val<A[mid])
            return Binary_Search(A,low,mid-1, val);
        else
            return Binary_Search(A,mid+1,high, val);
    }
    return -1;
}

int Sequential_Search(int * A,int n,int val){
    int i=0;
    A[n] = val;                     // place target at end of the list
    while(val!=A[i])
    {
        i = i + 1;
    }
    if(i < n)                       //if target is found not at sentinel then return position
        return(i);
    else                            // return -1 if not found
        return(-1);
}

int main() {
  //  int i;
    int n;
    cout << "How many numbers do you have in the array? ";
    cin >> n;
    int * A = new int [n];
    read(A,n);
    int val;
    int z = sizeof(*A);
    cout << "What value do you want to search for? ";
    cin >> val;
    cout << "Fibonacci Search:\n" << val << " is at index " << Fibonacci_Search (A,n,val) <<endl;
    cout << "Binary Search:\n" << val << " is at index "    << Binary_Search (A,0,z,val) << endl;
    cout << "Sequential Search:\n" << val << " is at index "<< Sequential_Search(A,n,val) << endl;
    return 1;
}
