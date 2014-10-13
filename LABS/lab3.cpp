//
//  main.cpp
//  LabThree
//
//  Created by maria saenz on 9/9/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//

#include<fstream>
#include<iostream>
#include<string>

using namespace std;


/**
 * ifstream-open the file for input
 * ofstream-open the file for output
 * fstream-open the file for input/output/both
 */

/**
 * Usages for reading a File:
 file>>char *;       //ie an array
 file>>char;         //single char
 file.get(char);     //single char
 file.get(char *,int);   //read a string
 file.getline(char *,int sz);
 file.getline(char *,int sz,char eol);
 */

bool test_output(string filename, string sentence){
    ofstream file;
    file.open(filename);
    file << sentence << endl;
    return 1;
}

bool test_input_simple(string file_open){
    
    ifstream open_file;
    char * main_text;
    open_file.open(file_open);
    while (open_file.peek()!=EOF) {
        
        open_file.getline(main_text,'\t');
        cout<<main_text<<endl;
        
    }
    
    return 1;

}

bool test_input_whole();
bool test_input_insertObj();






int main(){
    
   /* //Output test
     string filename;
     string sentence;
     cout << "Enter a filename: ";
     getline(cin, filename);
     cout << "Enter a sentence to put into the file: ";
     getline(cin, sentence);
     bool output_finished = test_output(filename, sentence);
     cout << "Outcome of Output test: " << output_finished << endl;
    //Simple Input test*/
    
    string file_open;
    cout << "Enter a filename: ";
    getline(cin, file_open);
    test_input_simple(file_open);

    
    //Input whole file test
    //test_input_whole();
    
    //test_input_insertObj();
    return 0;
}