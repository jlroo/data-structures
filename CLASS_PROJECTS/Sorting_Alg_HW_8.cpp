#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

/*
using namespace std;

//bubble
#define max 10
 void bubblesort(int A[max], int n) {
 int i, j, temp;
     for (i = 1; i < n; i++) {                  // number of passes
        for (j = 0; j < n - i; j++) {           // j varies from 0 to n-i
            if (A[j] > A[j + 1]) {              // compare two successive numbers
                temp = A[j];
                // swap A[j] with A[j+1]
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
 }
 
//quick sort
void quickSort(int A[], int low, int high){
    int i = low, j = high, aux, int = A[(low + high) / 2]; //variables initialization
    while (i <= j) {
        while (A[i] < pivot){                              // chack with the pivot
            i++;
        }
        while (A[j] > pivot){
            j--;
        }
        if (i <= j) {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;         //tempeorarily store value
            i++;                //increase i
            j--;                //decrease j
        }
    }
    if (low < j){
        quickSort(A, low, j);   //recursive call of quicksort function
    }
    if (i < high){
        quickSort(A, i, high);
    }
}

void swap(int *x, int *y){   //swap function to use in quick sort

    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int low, int high) {     //partition fuction to implement with quick sort
    int i;
    int p;
    int first_high;
    
    p = high;
    first_high = low;
    
    for (i = low; i < high; ++i)
    {
        if (A[i] < A[p])
        {
            swap(&A[i], &A[first_high]);        //swap array valye for the hights value
            first_high++;
        }
    }
    
    swap(&A[p], &A[first_high]);
    
    return first_high;
}

//shell sort
typedef unsigned int UINT;          //define type for UINT
void shell(int A[], UINT size) {
    UINT m = 1;
    while (m <= size)
    {
        m = 3 * m + 1;
    }
    while (m > 0)
    {
        m = m / 3;
        UINT k;
        for (k = 1; k < m; k++)
        {
                                        //Insertion Sort
            UINT i;
            for (i = 1; i < size; i++)
            {
                UINT j;
                for (j = i; j > 0 && A[j-1] > A[j]; j--)
                {
                                        // Xor swap
                    A[j] ^= A[j-1];
                    A[j-1] ^= A[j];
                    A[j] ^= A[j-1];
                }
            }
        }
    }
}


//bucket sort
#define m 10                    //define size

void bucketsort (int *a, int n) {
    
    int buckets [m];            //initialize bucket
    
    for (int j=0; j &lt; m; ++j)
        
        buckets[j]=0;
    
    for (int i=0; i &lt; n; ++i)
        
        ++buckets[a[i]];          //add array[i] value to bucket
    
    for (int i=0, j=0; j &lt; m; ++j)
        
        for (int k=buckets[j]; k &gt; 0; --k)
            
            a[i++]=j;
    
}

//radix sort
void RadixSort(int A[], int n);

//merge sort
void merge(int A[], int low, int high, int mid);
void MergeSort(int A[], int low, int high);

//get data
void read(int A[], int n) {                     ///read the dat
    int i;
    for(i=0; i<n; i++)
        cin >> A[i];                            //print array values
}

//show data
void display(int A[], int n) {                  //dsiplay data
    int i;
    for(i=0; i<n; i++)
        cout << A[i] << " ";
}


void write_to_file(char * filename, char * sort_tech, int A[])      //write results to external file
{
    ofstream out;
    out.open(filename, ios::app);
    out << sort_tech << "\t";
    for(int i=0; i<1000; i++)
        out << A[i] << "\t";
    out << endl;
    out.clear();
    out.close();
}

void copy_array(int dest[],int source[], int n) {
    for(int i=0; i<n; i++) dest[i]=source[i];
}

bool read_from_file(char * filename, int A[]) {             //read from the user inputed file
    int i;
    ifstream in;
    in.open(filename);
    if(in.is_open())
    {
        for(i=0; i<1000; i++)
            in>>A[i];
        in.clear();
        in.close();
        return true;
    }
    else
    {cout << "Cannot read file.\n"; return false;}
}
int main(){
		//make a clock
		//read in all files
	    //col: 0=bubble, 1=shell, 2=quick, 3=bucket, 4=merge
	    //row 0 random, row 1 nearly sorted, row 2 reversed, row 3 few unique
	    string labels[]={"random","nearly sorted","reversed","few unique"};
       // ofstream out;
}

*/

#include<stdio.h>
#include<stdlib.h>
struct TNode{
    int data;
    struct TNode *left;
    struct TNode *right;
};

struct TNode * newNode(int data){
    struct TNode* node=(struct TNode *) malloc(sizeof(struct TNode));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct TNode * sortedArrayToBST(int array [], int start, int end){
    if(start>end)
        return NULL;
    int mid=(start+end)/2;
    struct TNode * root=newNode(array[mid]);
    root->left=sortedArrayToBST(array,start, mid-1);
    root->right=sortedArrayToBST(array,mid+1, end);
    return root;
}

void preOrder(struct TNode *root ){
    if(root==NULL)
        return ;
    // preOrder(root->left);
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void Inorder( struct TNode * root ){           //Function to read the tree Inorder data structure
    if(root!=NULL) {                                        //and print out the data in the root
        Inorder (root -> left);
        cout << root ->data <<endl;
        Inorder (root ->right);
    }
}

void Postorder ( struct TNode * root ) {             //Function to read the tree Postorder data structure
    if (root!=NULL) {
        Postorder (root-> left);
        Postorder (root-> right);
        cout << root->data<<endl;
    }
}

bool Search( TNode * root,int val) {                //Function to search inpur data in the tree
    struct TNode * Tmp= root;                       //Points Tmp to the Root
    while (Tmp) {
        if ( Tmp->data== val)
            return 1;
        else
            if (Tmp->data > val)
                Tmp=Tmp->left;
            else
                Tmp=Tmp->right;
    }
    return 0;
}

int main(){
    int n,i;
    cout<<"Enter the size of array\n"<<endl;
    cin>>n;
    int arr[20];

    for(i=0;i<n;i++){
        arr[i]=i;
    }
    
    struct TNode *root = sortedArrayToBST(arr,0,n-1);
    
    cout<<"PreOrder of Tree is \n"<<endl;
    preOrder(root);
    cout<<"-------"<<endl;
    Inorder(root);
    cout<<"-------"<<endl;
    Postorder(root);
    cout<<"-------"<<endl;
    int s_val =  Search(root,15);
    if (s_val==1) {
        cout<<"found"<<endl;
    }else
        cout<<"Not found"<<endl;
    cout<<"-------"<<endl;
    
    return 0;
}


/*
 
 struct TNode{
 long data;
 struct TNode *left;
 struct TNode *right;
 };
 
 struct TNode * newNode(long data){
 struct TNode* node=(struct TNode *) malloc(sizeof(struct TNode));
 node->data=data;
 node->left=NULL;
 node->right=NULL;
 return node;
 }
 
 struct TNode * sortedArrayToBST( vector<long> l_gnome, long start, long end){
 if(start>end)
 return NULL;
 long mid=(start+end)/2;
 struct TNode * root=newNode(l_gnome[mid]);
 root->left=sortedArrayToBST(l_gnome,start, mid-1);
 root->right=sortedArrayToBST(l_gnome,mid+1, end);
 return root;
 }
 
 void preOrder(struct TNode *root ){
 if(root==NULL)
 return ;
 // preOrder(root->left);
 cout<<root->data<<endl;
 preOrder(root->left);
 preOrder(root->right);
 }
 
 void Inorder( struct TNode * root ){           //Function to read the tree Inorder data structure
 if(root!=NULL) {                                        //and print out the data in the root
 Inorder (root -> left);
 cout << root ->data <<endl;
 Inorder (root ->right);
 }
 }
 
 void Postorder ( struct TNode * root ) {             //Function to read the tree Postorder data structure
 if (root!=NULL) {
 Postorder (root-> left);
 Postorder (root-> right);
 cout << root->data<<endl;
 }
 }
 
 bool Search( TNode * root,int val) {                //Function to search inpur data in the tree
 struct TNode * Tmp= root;                       //Points Tmp to the Root
 while (Tmp) {
 if ( Tmp->data== val)
 return 1;
 else
 if (Tmp->data > val)
 Tmp=Tmp->left;
 else
 Tmp=Tmp->right;
 }
 cout<<"Not found"<<endl;
 return 0;
 }
 
 
 */