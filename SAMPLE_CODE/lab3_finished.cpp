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


//Create a file and adds a sentence from the user
/*
bool test_output()
{
    string filename;
    string sentence;
    cout << "Enter a filename: ";
    getline(cin, filename);
    cout << "Enter a sentence to put into the file: ";
    getline(cin, sentence);
    
    ofstream file;
    
    file.open(filename.c_str()); //open takes in const char * change string to char *
    file << sentence << "\n";
    
    file.clear();
    file.close();
    
    return true;
}*/

//This function reads in a file albums.txt and parses each piece of data and puts it in a variable
bool test_input_simple()
{
    char input[300];
    string filename;
    string artist;
    string album;
    string label;
    int no_of_tracks;
    int year;
    string genre;
    double runtime;
    ifstream fin;
    cout << "Enter a filename: ";
    getline(cin, filename);
    fin.open(filename.c_str());
    cout<<""<<endl;
    
    do
    {
        if (fin.is_open())
        {
            while (!fin.eof()) {
                
                getline(fin, artist, '\t');
                getline(fin, album, '\t');
                
                fin >> year;
                fin.getline(input, 300, '\t');

                getline(fin, label, '\t');
                
                fin >> no_of_tracks;
                fin.getline(input, 300, '\t');
                
                fin >> runtime;
                fin.getline(input, 300, '\t');
                
                getline(fin, genre, '\r');
                fin.getline(input, 300, '\n');
                
                cout << artist<<endl;
                cout << album <<endl;
                cout << year <<endl;
                cout << label <<endl;
                cout << no_of_tracks<<endl;
                cout<< runtime <<endl;
                cout<< genre<<endl;
                cout<<""<<endl;
            }
        }
        else{
            cout<<"Could not open file in question, does it exist?"<<endl;
            return false;
        }
    }
    while (!fin.eof()); //checks the connection
    fin.close();
    return true;
}

//This function shows how to open a file and grab data line by line with the new line as a delimeter
/*bool test_input_whole() {
    
     string filename;
     string line;
     ifstream fin;
     
     cout << "Enter a filename: ";
     getline(cin, filename);
     fin.open(filename.c_str());
     do {
     
     if (fin.is_open()) {
         getline(fin, line, '\n');
         cout << line << endl;
     }
     
     else{
         cout<<"File not there"<<endl;
         return false;
     }
     
     }
        while (!fin.eof()); //checks the connection
        fin.clear();
        fin.close();
    

    This example is from the slides
     ifstream in;
     string filename;
     char text[100];
     cout << "Enter a filename: ";
     getline(cin, filename);
     in.open(filename);
     while(in.peek()!=EOF)
     {
     in.getline(text,100,'\n');
     cout<<text<<endl;
     }
     in.clear();
     in.close();
    return true;
} */

int main(){
    
    //Output test, write to a file
    //test_output();
    
    //Input file and test to write out per line
    //test_input_whole();
    
    //Input file and parse per parameter and add to a variable, print out
    // /Users/jlroo/Desktop/movies_o.txt /Users/jlroo/Desktop/albums.txt
    test_input_simple();
    
    return 0;
}

