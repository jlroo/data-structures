//
//  HW_5.cpp
//  C++
//
//  Created by jlroo on 10/14/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//
#include "HW_5.h"

int main(){
    char key;
    vector<string> word_count;
    vector<double> w_count;
    vector<string> words;
    vector<string> single_word;
    string filename;                                                            //User filename
    string filename_out;                                                        //file to store statistics
    string open_file;
    char * file_name;
    char * file_out;
    
    do {
                                                                                //welcome message and menu options
        cout << "* * * * * WELCOME TO FILE STATS * * * * * *"<<endl;
        cout << "*       Lets analyze a text file          *"<<endl;
        cout << "* To analyze a file           [press] (1) *"<<endl;
        cout << "* To open stats file          [press] (2) *"<<endl;
        cout << "* To search for a word        [press] (3) *"<<endl;
        cout << "* To Exit                     [press] (4) *"<<endl;
        cout << "*        [Choose one option]              *"<<endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * *"<<endl;
        cin >> key;                                                             //get option for the swicth
        
        switch (key) {
                
            case 49:{
                cout <<""<<endl;
                cout << "* * * * * * * * * FILE IN * * * * * * * * *"<<endl;
                cout << "*    To start analyzing a file please     *"<<endl;
                cout << "*      enter the name and location        *"<<endl;
                cout << "*              of your file               *"<<endl;
                cout << "*      [/user/location/FILE_IN.txt]       *"<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * *"<<endl;
                cout << "Text file to analize:";
                cin.ignore();cin.sync();
                
                getline(cin,filename);                                         //  Get file name from user
                file_name = new char[filename.length() + 1];
                strcpy(file_name, filename.c_str());
                
                read_file(file_name, words);                                   //function to read the file and put it in a vector
                get_num_occ(words,single_word,word_count,w_count);             //function to get individula words and their count
                
                filename_out= filename.insert(filename.length()-4, "_Stats");  //File with statistics will be save with the same name of the input file plus
                file_out= new char[filename_out.length()+1];                   //_Stat.txt root
                strcpy(file_out, filename_out.c_str());
                
                print_stats(word_count,w_count);                               //Print statistics in a nice format
                
                write_file(file_out,word_count,w_count);                       //function that writes to the output to an outside file
                
                cout <<""<<endl;
                cout << "* * * * * * * * * FILE  OUT * * * * * * * *"<<endl;
                cout << "*      You can find the file with the     *"<<endl;
                cout << "*            statistics here:             *"<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * *"<<endl;
                cout << ""<<endl;
                cout << "   "<<left<< filename_out<<right<<setw(5)<<endl;       //gives the location of the file containing the statistics
                cout << ""<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * *"<<endl;
                cout << ""<<endl;
                
            }
                
                break;
                
            case 50:{
                cin.ignore();
                cout << "* * * * * * * * STATS ARCHIVE * * * * * * *"<<endl;
                cout << "*    To open a file with statistics       *"<<endl;
                cout << "*        about a text file enter          *"<<endl;
                cout << "*       the filename and location         *"<<endl;
                cout << "*    [/user/location/file_STATS.txt]:     *"<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * *"<<endl;
                cout <<""<<endl;
                cin.sync();
                getline(cin,open_file);                                         //  Get file name from user
                file_name = new char[open_file.length() + 1];
                strcpy(file_name, open_file.c_str());
                open_stat_file(file_name);                                      // function to read a file and write the content to console
            }
                break;
                
            case 51:{
                
                cin.ignore();cin.sync();
                cout << "* * * * * * * * SEARCH WORD * * * * * * * *"<<endl;
                cout << "*                                         *"<<endl;
                cout << "*       Search for a word in the file     *"<<endl;
                cout << "*        and look for its statistics     *"<<endl;
                cout << "*                                         *"<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * *"<<endl;

                search_word(word_count,w_count);                                //function to search word in the file
                cout << ""<<endl;
            }
                break;
                
            case 52:{
                cout << "!BYE!"<<endl;
            }
                break;
                
            default:{
                cout << "Not an option, try again or exit (4)"<<endl<<endl;
            }
        }
        
    }
    while (key!=52);
}