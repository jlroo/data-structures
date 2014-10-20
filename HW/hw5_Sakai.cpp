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
#include <sstream>
#include <iomanip>

using namespace std;

bool read_file(char * file_name,vector<string> & w) {
    
    ifstream in;
    in.open(file_name);

    if(!in.is_open()){
        cout <<"The file isnt open or you enter a wring"<<endl;
        cout <<"location to opem a file make sure that"<<endl;
        cout <<"you enter the rigth name and location"<<endl;
        return 0;
    }
    
    else {
        char * word=new char [100];                             //creates a char array pointing to an address
        string s_word;
        while(in.peek()!=EOF) {                                 //Returns the next character in the input sequence, without extracting it.
                                                                //The character is left as thenext character to be extracted from the stream.
            in.get(*word);                                      // Extracts characters from the stream
            if (isalpha(*word) || isspace(*word)) {             //If wherever is store at the address od word is an aplhabetic char or spance
                s_word=tolower(*word);                          //change all the alphabetic characters to lower case and assign it to a string
                w.push_back(s_word);                            //push the string of word to the vector w
            }
        }
    }
    in.clear();
    in.close();
    return 1;
}

void print_stats(vector<string> & word_count, vector<double> & w_count) {
    cout <<" _________________________  "<<endl;
    cout <<"|                         | "<<endl;                //This function write to the console and creates a nice format
    cout <<"|     FILE STATISTICS     | "<<endl;                //to display the statistics
    cout <<"|_________________________| "<<endl;
    cout <<"|_____WORD_____|__COUNT___| "<<endl;
    cout <<"|              |          | "<<endl;
    for (int i=0; i<word_count.size(); i++) {
        cout <<"|  "<<setw(12)<<left<< word_count[i] <<"|    "<<setw(5)<<left<< w_count[i] <<" |"<<endl;
    }
    cout <<"|______________|__________| "<<endl;
    
}

int get_num_occ(vector<string> & w, vector<string> & single_word,vector<string> & word_count, vector<double> & w_count) {
    
    ostringstream clean_txt;                                      //Use a string buffer that contains a sequence of characters.
                                                                  //This sequence of characters can be accessed directly as a string object, using member str.
    copy(w.begin(), w.end(),ostream_iterator<string>(clean_txt)); //Copies the elements in the range [first,last) into the range beginning at result and
    string string_buffer;                                         //writes sequentially to an output stream.
    stringstream TextStream(clean_txt.str());                     //Inserts the string into a stream

    while (TextStream >> string_buffer) {                         //While assings words from the string to the string buffer
        single_word.push_back(string_buffer);                     //push the individual words assigned to the string buffer to the new vector.
    }
    
    sort(single_word.begin(),single_word.end());                  //Sorts the elements in the range [first,last) into ascending order.
    vector<string>::iterator it;                                  //Random-access iterators to access elements at an arbitrary offset position relative
                                                                  //to the element pointed.
    
    for (int i=0; i<single_word.size(); i++) {
        if ((single_word[i+1]!=single_word[i])) {                 //If the word second word isnt equal to the first assign to the vector
            word_count.push_back(single_word[i]);                 //then count how many times a single_word at [i] occurs in the all vector
            w_count.push_back(count(single_word.begin(), single_word.end(), single_word[i]));   //assing the count value to the vector w_count
        }
    }
    
    return 1;
}

int search_word(vector<string> & word_count, vector<double> & w_count) {
    
    cout<<""<<endl;
    vector<string>::iterator it;
    string search;
    cout<<"Enter a word to search:"<<endl;
    cin>> search;
    cout<<""<<endl;
    transform(search.begin(),search.end(), search.begin(), ::tolower);
    
    auto search_result = find(word_count.begin(),word_count.end(), search);

    if (search_result != end(word_count)) {
        for (int i=0; i<word_count.size(); i++) {
            if (search==word_count[i]) {
                cout<<"You are searching for the word: "<<search<<endl;
                cout<<"This word Appears: "<< w_count[i]<<" times."<<endl;
                cout<<"In the text file."<<endl;
                return 1;
            }
        }
    } else {
        cout<<"The word: "<<search<<endl;
        cout<<"Does not appear in the text file."<<endl;
    }

    return 1;
}

bool write_file(char * file_out,vector<string> & word_count, vector<double> & w_count){
    ofstream file_stats;
    file_stats.open(file_out);                                    //Write to the new file Stat.txt the statistics from the input file
    file_stats <<" _________________________  "<<"\n";            //in a nice format
    file_stats <<"|                         | "<<endl;
    file_stats <<"|     FILE STATISTICS     | "<<endl;
    file_stats <<"|_________________________| "<<endl;
    file_stats <<"|_____WORD_____|__COUNT___| "<<endl;
    file_stats <<"|              |          | "<<endl;
    for (int i=0; i<word_count.size(); i++) {
        file_stats <<"|  "<<setw(12)<<left<< word_count[i] <<"|    "<<setw(5)<<left<< w_count[i] <<" |"<<endl;
    }
    file_stats <<"|______________|__________| "<<endl;
    file_stats.clear();
    file_stats.close();
    return 1;
}

int main() {
    
    vector<string> word_count;
    vector<double> w_count;                                       //The vectors word_count and w_count store words and its occurance
    vector<string> words;
    vector<string> single_word;
    string filename;                                                //User filename
    string filename_out;                                            //file to store statistics
    char * file_name;
    char * file_out;
    
    filename="/Users/jlroo/Desktop/poe_2.txt";
    file_name = new char[filename.length() + 1];
    strcpy(file_name, filename.c_str());

    filename_out= filename.insert(filename.length()-4, "_Stats");  //File with statistics will be save with the same name of the input file plus
    file_out= new char[filename_out.length()+1];                   //_Stat.txt root
    strcpy(file_out, filename_out.c_str());
    
    read_file(file_name, words);
    get_num_occ(words,single_word,word_count,w_count);
    print_stats(word_count,w_count);                              //Print statistics in a nice format
    write_file(file_out,word_count,w_count);
    search_word(word_count,w_count);
    
    return 1;
}
