//
//  HW_6.cpp
//  C++
//
//  Created by jlroo on 10/30/14.
//  Copyright (c) 2014& Jose L Rodriguez. All rights reserved.
//

#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <cmath>

using namespace std;

class BTreeNode {
public:
    string data;
    BTreeNode * Lchild;
    BTreeNode * Rchild;
};

class BinaryTree {
    
private:
   
    BTreeNode * root;
    
    public :
    
        BinaryTree() {              //constructor
            root=NULL;
        }
    
        BTreeNode * vector_To_BST ( vector<string> data, int start, int end );
        BTreeNode * Btree_Equal   ( BTreeNode * root1 , BTreeNode * root2 );    // To compare two trees
        bool Search     ( string  data, BTreeNode * root ) ;
        void Inorder    ( BTreeNode * root );
        void Postorder  ( BTreeNode * root );
        void Preorder   ( BTreeNode * root );

};

class QTreeNode {
public:
    string data;
    QTreeNode * child1;
    QTreeNode * child2;
};

class QuaternaryTree {
    
private:
    QTreeNode * root;
    
    public :
    
    QuaternaryTree() {              //constructor
        root=NULL;
    }
    
    QTreeNode * vector_To_QST ( vector<string> data, int start,int end );
    
    QTreeNode * Btree_Equal   ( QTreeNode * root1 , QTreeNode * root2 );    // To compare two trees
    bool QSearch     ( string  data, QTreeNode * root ) ;
    void QInorder    ( QTreeNode * root );
    void QPostorder  ( QTreeNode * root );
    void QPreorder   ( QTreeNode * root );
    
};

 QTreeNode * QuaternaryTree (string vector_data){

    QTreeNode * root = new QTreeNode;
    
    root->data=vector_data;
    root->child1=NULL;
    root->child2=NULL;
    
    return root;
}

bool binary_search(const vector<string>& sorted_vec, string key) {
   
    size_t mid, left = 0 ;
    size_t right = sorted_vec.size();               // one position passed the right end
    
    while (left < right) {
        mid = left + (right - left)/2;
        if (key > sorted_vec[mid]){
            left = mid+1;
        }
        else if (key < sorted_vec[mid]){
            right = mid;
        }
        else {
            return 1;
        }
    }
    return 0;
}

QTreeNode * vector_To_QST (vector<string> vector_data, int start, int end){
    
    int mid = floorl( start + (end - start)/2 );
  
    if(start>end)
        return NULL;
  
    QTreeNode * root = QuaternaryTree(vector_data[mid]);               // TREE ROOT (MEAN)
   
        root->child1 = vector_To_QST(vector_data,start,mid-1);          // FIRST QUARTILE
        root->child2 = vector_To_QST(vector_data,mid+1,end);       // SECOND QUARTILE
  
    return root;
}

void QInorder (QTreeNode * root ) {              //Function to read the tree Inorder data structure
    if(root!=NULL) {
                                                //and print out the data in the root
        QInorder (root -> child1);
        cout << root ->data<<endl;
        QInorder (root ->child2);
    
    }
}

bool QTreeEqual( QTreeNode * root1, QTreeNode * root2) {
    
    if(root1 == root2)                              // handles the roots are equal or both NULL
        return 1;
    if(root1 == NULL || root2 == NULL)              // one of them NULL
        return 0;
    if(root1->data != root2->data)                  // data check
        return 0;
    if(!QTreeEqual(root1->child1, root2->child1))
        return 0;
    if(!QTreeEqual(root1->child2, root2->child2))
        return 0;
    
    return 1;                                       // everything has been checked, return true
    
}

bool QSearch(string data, QTreeNode * root) {                //Function to search inpur data in the tree
    
    QTreeNode * Tmp = root;                                //Points Tmp to the Root
    
    while (Tmp) {
        if ( Tmp->data== data)
            return 1;
        else
            if (Tmp->data > data)
                Tmp=Tmp->child1;
            else
                Tmp=Tmp->child2;
    }
    
    return 0;
}

int count_QNodes( QTreeNode * root ) {
    if ( root == NULL )
        return 0;                                                       // The tree is empty.  It contains no nodes.
    else {
        int count = 1;                                                  // Start by counting the root.
        count += count_QNodes(root->child1);                              // Add the number of nodes in the left subtree.
        count += count_QNodes(root->child2);                              // Add the number of nodes in the right subtree.

        return count;  // Return the total.
    }
}

BTreeNode * BinaryTree (string data){                               // create balance Binary_tree
    BTreeNode * root = new BTreeNode;
    root->data=data;
    root->Lchild=NULL;
    root->Rchild=NULL;
    return root;
}

BTreeNode * vector_To_BST (vector<string> data, int start, int end){
    
    if(start>end)
        return NULL;
    
    int mid = start + ((end-start)/2);
    
    BTreeNode * root = BinaryTree(data[mid]);
    
    root->Lchild = vector_To_BST(data,start, mid-1);
    root->Rchild = vector_To_BST(data,mid+1, end);
    
    return root;
}

void Inorder (BTreeNode * root ) {              //Function to read the tree Inorder data structure
    if(root!=NULL) {                                        //and print out the data in the root
        Inorder (root -> Lchild);
        cout << root ->data<<endl;
        Inorder (root ->Rchild);
    }
}

void Preorder (BTreeNode * root) {              //Function to read the tree Preorder data structure
    if(root!=NULL) {
        cout <<"\t"<< root ->data<<endl;
        Preorder (root -> Lchild);
        Preorder (root -> Rchild);
    }
}

void Postorder (BTreeNode * root) {             //Function to read the tree Postorder data structure
    if (root!=NULL) {
        Postorder (root-> Lchild);
        Postorder (root-> Rchild);
        cout <<"\t"<< root->data<<endl;
    }
}

void clear(BTreeNode * root) {
    if(root != NULL) {
        clear(root-> Lchild);
        clear(root-> Rchild);
        delete root;
    }
}

bool TreeEqual( BTreeNode * root1, BTreeNode * root2) {
    
    if(root1 == root2)                              // handles the roots are equal or both NULL
        return 1;
    if(root1 == NULL || root2 == NULL)              // one of them NULL
        return 0;
    if(root1->data != root2->data)                  // data check
        return 0;
    if(!TreeEqual(root1->Lchild, root2->Lchild))
        return 0;
    if(!TreeEqual(root1->Rchild, root2->Rchild))
        return 0;
    
    return 1;                                       // everything has been checked, return true

}

bool Search(string data,BTreeNode * root) {                //Function to search inpur data in the tree
    
    BTreeNode * Tmp = root;                                //Points Tmp to the Root
    
    while (Tmp) {
        if ( Tmp->data== data)
            return 1;
        else
            if (Tmp->data > data)
                Tmp=Tmp->Lchild;
            else
                Tmp=Tmp->Rchild;
    }
    return 0;
}

int count_BNodes( BTreeNode * root ) {
     if ( root == NULL )
        return 0;                                                       // The tree is empty.  It contains no nodes.
    else {
        int count = 1;                                                  // Start by counting the root.
        count += count_BNodes(root->Lchild);                              // Add the number of nodes in the left subtree.
        count += count_BNodes(root->Rchild);                              // Add the number of nodes in the right subtree.
        return count;  // Return the total.
    }
}

bool Sort_vector(vector<string> words, vector<string> & sorted_data,vector<double> & code_count){
    sort(words.begin(),words.end());
    for (int i=0; i<words.size(); i++) {
        if ((words[i+1]!=words[i])) {                            //If the word second word isnt equal to the first assign to the vector
            sorted_data.push_back(words[i]);
            code_count.push_back(count(words.begin(), words.end(), words[i]));
        }
    }
    return 1;
}

bool Sort_vector_test(vector<string> & test_words,vector<string> & t_sorted){
    sort(test_words.begin(),test_words.end());
    for (int i=0; i<test_words.size(); i++) {
        if ((test_words[i+1]!=test_words[i])) {               //If the word second word isnt equal to the first assign to the vector
            t_sorted.push_back(test_words[i]);                //then count how many times a single_word at [i] occurs in the all vector
        }
    }
    return 1;
}

bool get_words(char * file_name, vector<string> &w, char type) {
    int i,j;
    int len=0;
    ifstream in;
    in.open(file_name);
    if(!in.is_open()) {
        cout << "The genome file could not be opened. Check the location.\t";
        return 0;
    }
    
    char * word=new char [11];                              //this is a default, we'll be looking at words of size 10
    while(in.peek()!=EOF) {                                 //gets the length of the sequence
        in>>word[0];
        len++;
    }
    in.clear();
    in.close();                                             //have to close and reopen file to reset filestream to beginning of file
    in.open(file_name);
    
    for(i=0; i<10; i++) {
        in>> word[i];
        if(word[i]<97) word[i]+=32;                         //makes it lowercase
        if(type=='B' || type=='b'){                         //if doing BTree, translates 4 letter code into two letter code
            if(word[i]=='a' || word[i]== 'g') word[i]='r';  //purine
            else word[i]='y';                               //pyrimidine
        }
        
    }
    word[10]='\0';
    w.push_back(word);
    for(i=1; i<(len-10-1); i++) {                           //read until the end of the file
                                                            //shift
        for(j=0; j<9; j++) word[j]=word[j+1];
        in>> word[9];
        if(word[9]<97) word[9]+=32;                         //makes it lowercase
        if(type=='B' || type=='b'){
            if(word[9]=='a' || word[9]== 'g') word[9]='r';  //purine
            else word[9]='y';                               //pyrimidine
        }
        word[10]='\0';
        w.push_back(word);
    }
    in.clear();
    in.close();
    return 1;
}

bool get_test_file(char * file_name, vector<string> & r) {
    int i;
    ifstream in;
    in.open(file_name);
    if(!in.is_open()) {
        cout << "The read file could not be opened. Check the location.\t";
        return 0;
    }
    char * word=new char [11];                              //this is a default, we'll be looking at words of size 10
    while(in.peek()!=EOF) {
        in.getline(word,11,'\n');
        for(i=0; i<10; i++) {
            if(word[i]<97) word[i]+=32;                     //makes it lowercase
        }
        r.push_back(word);
    }
    in.clear();
    in.close();
    delete word;
    return 1;
}

bool write_vector_to_screen(vector<string> g_count,vector<double> v_count, int Tree_comparison){
    
    if (Tree_comparison==1) {
        cout <<" __________________________________ "<<endl;
        cout <<"|                                  |"<<endl;
        cout <<"|     The two Genome Sequences     |"<<endl;
        cout <<"|          are EQUIVALENT          |"<<endl;
        cout <<"|__________________________________|"<<endl;

    }else {
        
        cout <<" __________________________________ "<<endl;
        cout <<"|                                  | "<<endl;
        cout <<"|     The two Genome Sequences     |"<<endl;
        cout <<"|        are NOT EQUIVALENT        |"<<endl;
        cout <<"|__________________________________|"<<endl;
    
    }
    
        cout<<""<<endl;
        cout <<" __________________________________  "<<endl;
        cout <<"|                                  | "<<endl;                //This function write to the console and creates a nice format
        cout <<"|     GENOME ANALYSIS RESULTS      | "<<endl;                //to display the statistics
        cout <<"|__________________________________| "<<endl;
        cout <<"|_____SEQUENCE_____|_____COUNT_____| "<<endl;
        cout <<"|                  |               | "<<endl;
    for (int i=0; i<g_count.size(); i++) {
        cout <<"|    "<<setw(14)<<left<< g_count[i] <<"|       "<<setw(8)<<left<< v_count[i] <<"|"<<endl;
    }
        cout <<"|__________________|_______________| "<<endl;
        cout <<""<<endl;
    
    g_count.clear();
    v_count.clear();
    return 1;
}

bool write_vector_to_file(vector<string> g_count,vector<double> v_count, char * file_name, int Tree_comparison) {

    ofstream out;
    out.open(file_name);
    
    if (Tree_comparison==1) {
       
        out <<" "<<endl;
        out <<" __________________________________ "<<endl;
        out <<"|                                  | "<<endl;
        out <<"|     The two Genome Sequences     |"<<endl;
        out <<"|          are EQUIVALENT          |"<<endl;
        out <<"|__________________________________|"<<endl;
        
    }else {
        out <<" "<<endl;
        out <<" __________________________________ "<<endl;
        out <<"|                                  | "<<endl;
        out <<"|     The two Genome Sequences     |"<<endl;
        out <<"|        are NOT EQUIVALENT        |"<<endl;
        out <<"|__________________________________|"<<endl;
        
    }
        out <<" "<<endl;
        out <<" __________________________________  "<<endl;
        out <<"|                                  | "<<endl;                //This function write to the console and creates a nice format
        out <<"|     GENOME ANALYSIS RESULTS      | "<<endl;                //to display the statistics
        out <<"|__________________________________| "<<endl;
        out <<"|_____SEQUENCE_____|_____COUNT_____| "<<endl;
        out <<"|                  |               | "<<endl;
    for (int i=0; i<g_count.size(); i++) {
        out <<"|    "<<setw(14)<<left<< g_count[i] <<"|       "<<setw(8)<<left<< v_count[i] <<"|"<<endl;
    }
        out <<"|__________________|_______________| "<<endl;
        out <<""<<endl;
        out.clear();
        out.close();
    
        g_count.clear();
        v_count.clear();
    return 1;
}

bool display_results() {
    
    string filename;
    string line;
    ifstream fin;
    cout << "Enter filename with results:";
    filename="/Users/jlroo/Desktop/Results_Btree.txt";
    cout<<" "<<endl;
  //  getline(cin, filename);
    fin.open(filename.c_str());
    do
    {
        
        if (fin.is_open())
        {
            getline(fin, line, '\n');
            cout << line << endl;
        }
        else{
            cout<<"File not found!"<<endl;
            return 0;
        }
        
    }
    while (!fin.eof());   //checks the connection
    fin.clear();
    fin.close();
    
    return 1;
}
