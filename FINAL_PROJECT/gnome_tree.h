//
//  gnome_tree.h
//  C++
//
//  Created by jlroo on 12/4/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#ifndef __C____gnome_tree__
#define __C____gnome_tree__

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

class genome_node {
public:
    string data;
    genome_node * Lower_sequence;
    genome_node * Upper_sequence;
};

class genome_tree {
    
private:
    
    genome_node * root;
    
    public :
    
    genome_tree() {
        root=NULL;
    }
    
    genome_node * vector_To_GST ( vector<string> data, int start, int end );//CREATE TREE
    genome_node * genome_tree_Equal   ( genome_node * root1 , genome_node * root2,vector<string> g_count,vector<double> v_count) ;//COMPARE TREE
    bool Search     ( string  data, genome_node * root ) ;//SEARCH TREE WORD
    void Inorder    ( genome_node * root );
    
};

genome_node * genome_tree (string data){        // NODE TREE FUNCTION
    
    genome_node * root = new genome_node;
    
    root->data=data;
    root-> Lower_sequence=NULL;
    root-> Upper_sequence=NULL;
    return root;
}

genome_node * vector_To_GST (vector<string> data, int start, int end){      //CREATE THE TREE
    
    int mid = floorl( start + ((end-start)/2));
    
    if(start>end)
        return NULL;
    
    genome_node * root = genome_tree(data[mid]);
    root->Lower_sequence = vector_To_GST(data,start, mid-1);
    root->Upper_sequence = vector_To_GST(data,mid+1, end);
    
    return root;
}

void Inorder (genome_node * root ) {
    if(root!=NULL) {
        Inorder (root -> Lower_sequence);
        cout << root ->data<<endl;
        Inorder (root -> Upper_sequence);
        cout << root ->data<<endl;

    }
}
    //PRINT TO SCREEN THE RESULTS
bool genome_tree_Equal ( genome_node * root1, genome_node * root2,vector<string> g_count,vector<double> v_count) {
    
    int count_size = floorl(g_count.size());

    if(root1 == root2){         // IF THE TREES ARE EQUAL
        cout<<" "<<endl;
        cout <<" __________________________________ "<<endl;
        cout <<"|                                  |"<<endl;
        cout <<"|     The two Genome Sequences     |"<<endl;
        cout <<"|          are EQUIVALENT          |"<<endl;
        cout <<"|__________________________________|"<<endl;
        cout <<""<<endl;
        cout <<" __________________________________  "<<endl;
        cout <<"|                                  | "<<endl;                //This function write to the console and creates a nice format
        cout <<"|     GENOME ANALYSIS RESULTS      | "<<endl;                //to display the statistics
        cout <<"|__________________________________| "<<endl;
        cout <<"|_____SEQUENCE_____|_____COUNT_____| "<<endl;
        cout <<"|                  |               | "<<endl;
        
        for (int i=0; i<count_size; i++) {
            cout <<"|    "<<setw(14)<<left<< g_count[i] <<"|       "<<setw(8)<<left<< v_count[i] <<"|"<<endl;
        }
        
        cout <<"|__________________|_______________| "<<endl;
        cout <<""<<endl;
        
        g_count.clear();
        v_count.clear();
        return 0;
    }
    
    if(root1 == NULL || root2 == NULL){
        cout<<"NO trees or files were created the ROOTS are empty! Try again with the rigth files!"<<endl;
        return 0;
    }
    if(root1->data != root2->data){     // IF THE TREES ARE NOT EQUAL

        cout<<endl;
        cout<<" ___________________________________ "<<endl;
        cout<<"|                                   |"<<endl;
        cout<<"|    GENOME SEQUENCE DONT MATCH     |"<<endl;
        cout<<"|___________________________________|"<<endl;
        cout<<"|                                   |"<<endl;
        cout<<"|      SAMPLE GENOME SEQUENCE       |"<<endl;
        cout<<"|                                   |"<<endl;
        cout<<"|   TEST Gtree Node: "<<root2->data <<"     |"<<endl;
        cout<<"|                                   |"<<endl;
        cout<<"|___________________________________| "<<endl;
        cout<<"|                                   |"<<endl;
        cout<<"|        ORIGIN GENOME SEQUENCE     |"<<endl;
        cout<<"|                                   |"<<endl;
        cout<<"|   ORIGIN GTree Node: "<<root1->data <<"   |"<<endl;
        cout<<"|                                   |"<<endl;
        cout<<"|___________________________________| "<<endl;
        cout<<""<<endl;
        cout<<" __________________________________  "<<endl;
        cout<<"|                                  | "<<endl;                //This function write to the console and creates a nice format
        cout<<"|     GENOME ANALYSIS RESULTS      | "<<endl;                //to display the statistics
        cout<<"|__________________________________| "<<endl;
        cout<<"|_____SEQUENCE_____|_____COUNT_____| "<<endl;
        cout<<"|                  |               | "<<endl;
        for (int i=0; i<count_size; i++) {
            cout <<"|    "<<setw(14)<<left<< g_count[i] <<"|       "<<setw(8)<<left<< v_count[i] <<"|"<<endl;
        }
        cout <<"|__________________|_______________| "<<endl;
        cout <<""<<endl;
        g_count.clear();
        v_count.clear();

        return 1;
    }
   
    if(!genome_tree_Equal(root1->Lower_sequence, root2->Lower_sequence,g_count,v_count)){
        return 0;
    }
    
    if(!genome_tree_Equal(root1->Upper_sequence, root2->Upper_sequence,g_count,v_count)){
        return 0;
    }
    return 0;
}

bool Search(string data,genome_node * root) { // SEARCH FOR A WORD IN THE ORIGIN TREE
    genome_node * Tmp = root;
    while (Tmp) {
        if ( Tmp->data== data)
            return 1;
        else
            if (Tmp->data > data)
                Tmp=Tmp->Lower_sequence;
            else
                Tmp=Tmp->Upper_sequence;
    }
    return 0;
}

int count_BNodes( genome_node * root ) {                                //COUNT THE NODES OF THE TREE
    if ( root == NULL )
        return 0;                                                       // The tree is empty.  It contains no nodes.
    else {
        int count = 1;                                                  // Start by counting the root.
        count += count_BNodes(root->Lower_sequence);                    // Add the number of nodes in the left subtree.
        count += count_BNodes(root->Upper_sequence);                    // Add the number of nodes in the right subtree.
        return count;                                                   // Return the total.
    }
}

bool Sort_vector(vector<string> g_sequence, vector<string> & sorted_data,vector<double> & data_count){  //SORT VECTOR FUNCTION
   
    sort(g_sequence.begin(),g_sequence.end());
    int count_sequence=floorl(g_sequence.size());
    for (int i=0; i<count_sequence; i++) {
        if ((g_sequence[i+1]!=g_sequence[i])) {                      //If the word second word isnt equal to the first assign to the vector
            sorted_data.push_back(g_sequence[i]);
            data_count.push_back(count(g_sequence.begin(), g_sequence.end(), g_sequence[i]));
        }
    }
    return 1;
}

bool Sort_vector_test(vector<string> & test_sequence,vector<string> & sorted_test){ //SORT TEST VECTOR FUNCTION
    
    sort(test_sequence.begin(),test_sequence.end());
    int test_size=floorl(test_sequence.size());
    for (int i=0; i<test_size; i++) {
        if ((test_sequence[i+1]!=test_sequence[i])) {               //If the word second word isnt equal to the first assign to the vector
            sorted_test.push_back(test_sequence[i]);                //then count how many times a single_word at [i] occurs in the all vector
        }
    }
    return 1;
}

bool get_words(char * file_name, vector<string> &w) {       //GET WORDS FROM THE ORIGIN FILES
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
        
    }
    word[10]='\0';
    w.push_back(word);
    for(i=1; i<(len-10-1); i++) {                           //read until the end of the file
        for(j=0; j<9; j++) word[j]=word[j+1];
        in>> word[9];
        if(word[9]<97) word[9]+=32;                         //makes it lowercase
        word[10]='\0';
        w.push_back(word);
    }
    in.clear();
    in.close();
    return 1;
}

bool get_test_file(char * file_name, vector<string> & read_test) {  //GET WORD FROM THE TEST FILE
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
        read_test.push_back(word);
    }
    in.clear();
    in.close();
    delete word;
    return 1;
}

//WRITES ANALYSIS RESULTS TO FILE
bool write_vector_to_file(vector<string> g_count,vector<double> v_count, char * file_name, genome_node * root1,genome_node * root2,int Tree_comparison) {
    
    ofstream out;
    out.open(file_name);
    int count_size = floorl(g_count.size());
    
    if(Tree_comparison==0){ // IF THE TREES ARE EQUVALENT
        
        out<<" "<<endl;
        out <<" __________________________________ "<<endl;
        out <<"|                                  |"<<endl;
        out <<"|     The two Genome Sequences     |"<<endl;
        out <<"|          are EQUIVALENT          |"<<endl;
        out <<"|__________________________________|"<<endl;
        
        out<<" "<<endl;
        out <<" __________________________________  "<<endl;
        out <<"|                                  | "<<endl;                //This function write to the console and creates a nice format
        out <<"|     GENOME ANALYSIS RESULTS      | "<<endl;                //to display the statistics
        out <<"|__________________________________| "<<endl;
        out <<"|_____SEQUENCE_____|_____COUNT_____| "<<endl;
        out <<"|                  |               | "<<endl;
        for (int i=0; i<count_size; i++) {
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
    
    if(Tree_comparison==1){     //IF THE TREES ARE NOT EQUIVALENT PRINT THE DIFFERENT IN THEIR ROOTS

        out<<" ___________________________________ "<<endl;
        out<<"|                                   |"<<endl;
        out<<"|    GENOME SEQUENCE DONT MATCH     |"<<endl;
        out<<"|___________________________________|"<<endl;
        out<<"|                                   |"<<endl;
        out<<"|      SAMPLE GENOME SEQUENCE       |"<<endl;
        out<<"|                                   |"<<endl;
        out<<"|   TEST Gtree Node: "<<root2->data <<"     |"<<endl;
        out<<"|                                   |"<<endl;
        out<<"|___________________________________| "<<endl;
        out<<"|                                   |"<<endl;
        out<<"|        ORIGIN GENOME SEQUENCE     |"<<endl;
        out<<"|                                   |"<<endl;
        out<<"|   ORIGIN GTree Node: "<<root1->data <<"   |"<<endl;
        out<<"|                                   |"<<endl;
        out<<"|___________________________________| "<<endl;
        out<<""<<endl;
        out<<" __________________________________  "<<endl;
        out<<"|                                  | "<<endl;                //This function write to the console and creates a nice format
        out<<"|     GENOME ANALYSIS RESULTS      | "<<endl;                //to display the statistics
        out<<"|__________________________________| "<<endl;
        out<<"|_____SEQUENCE_____|_____COUNT_____| "<<endl;
        out<<"|                  |               | "<<endl;
        for (int i=0; i<count_size; i++) {
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
    
    return 1;
}

bool display_results() {        // DISPLAY RESULTS IN THE SCREEN
    
    string filename;
    string line;
    ifstream fin;
    cout << "Enter filename with results:";
    filename="/Users/jlroo/Desktop/Results_Gtree.txt"; // FILE TO SAVE RESULTS  NEED TO CHANGE THIS FILE TO YOUR OWN PATH
    //  getline(cin, filename);
    cout<<" "<<endl;

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

#endif /* defined(__C____gnome_tree__) */
