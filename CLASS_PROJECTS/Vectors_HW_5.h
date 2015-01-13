//
//  HW_5.h
//  C++
//
//  Created by jlroo on 10/14/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#ifndef __C___Vectors_HW_5__
#define __C___Vectors_HW_5__

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
        cout <<"The file isnt open or you enter a wrong"<<endl;
        cout <<"location to open a file make sure that"<<endl;
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
        if ((single_word[i+1]!=single_word[i])) {                 //If the second word isnt equal to the first assign to the vector
            word_count.push_back(single_word[i]);                 //then count how many times a single_word at [i] occurs in the all vector
            w_count.push_back(count(single_word.begin(), single_word.end(), single_word[i]));   //assing the count value to the vector w_count
        }
    }
    
    return 1;
}

int search_word(vector<string> & word_count, vector<double> & w_count) {
    cin.sync();
    cout<<""<<endl;
    string search;
    cout<<"Enter a word to search:";
    cin>> search;
    cout<<""<<endl;
    
    transform(search.begin(),search.end(), search.begin(), ::tolower);      //transform the user input to lower case to compare with words in the vector
    auto search_result = find(word_count.begin(),word_count.end(), search); //find the word input by the user in the vector that contains the words
    
    if (search_result != end(word_count)) {
        for (int i=0; i<word_count.size(); i++) {
            if (search==word_count[i]) {
                cout<<"You are searching for the word: "<<search<<endl;
                cout<<"This word appears: "<< w_count[i]<<" times."<<endl;
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

bool open_stat_file(string file_name){                //function that gets the filename from the user and writes its content to the console
    
    string line;
    ifstream fin;
    fin.open(file_name);
    cout<<" "<<endl;
    cout<<"             STATS FILE STARTS HERE      "<<endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * *"<<endl;
    do {
        if (fin.is_open()){
            while (!fin.eof()) {
                
                getline(fin, line);
                cout <<"       "<< line <<endl;
            }
        }
    }
    while (!fin.eof());
    fin.clear();
    fin.close();
    cout << "* * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"                 END OF THE FILE             "<<endl;
    cout<<""<<endl;
    return 1;
}



#endif /* defined(__C____HW_5__) */
