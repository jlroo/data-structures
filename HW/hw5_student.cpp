//
//  main.cpp
//  Homework_5
//
//  Created by maria saenz on 10/8/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct word_freq{
    string word;
    int num_times_occ;
};

//this function reads the file and puts it in the vector
bool read_file(char * file_name,vector<string> & w);

//this function finds if the word is already in the array and returns the index
int is_in(string w, vector<word_freq> & wf);

//this function finds how many times a word occurs
int get_num_occ(string w, vector<word_freq> & wf);

//this function will write a file called 'word_stats.txt'
//and have all the UNIQUE words and how many times they show up
bool write_file(char * file_name,vector<word_freq> & wf);

bool read_file(char * file_name,vector<string> & w)
{
    int i;
    ifstream in;
    in.open(file_name);
    if(!in.is_open()) return false;
    char * word=new char [100];
    string s_word;
    while(in.peek()!=EOF)
    {
       
    }
    in.clear();
    in.close();
    return true;
}


int is_in(string w, vector<word_freq> & wf)
{
    int i;
    for(i=0; i<wf.size(); i++)
    {
        if(w==wf[i].word){
            return i;
        }
    }
    return -1;
}


int main() {

    int i;
    int index;
    vector<string> words;
    vector<word_freq> words_occ;
    word_freq new_word;
    string filename;
    //get the filename from the user
    if(read_file(filename, words))
    {
        for(i=0; i<words.size(); i++)
        {
            index=is_in(words[i],words_occ);
            //if word is in there increment the num_times
            //else make it equal  new_word.num_time_occ=1  and new_word=word then add to vector
        }
    }

    /*Print out unique words and how many times they occur Example:
     raven Occurs: 10
     saintly Occurs: 1
     days Occurs: 1
     */
    
    //Write file out with function write_file after parse
    
    //Prompt user: "What word would you like to look up, enter 0 to quit" so they can search words
    
    return 1;
}
