//
//  HW_3.cpp
//  C++
//  FALL 2014
//  Created by jlroo on 9/25/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#include "HW_3.h"
#include<fstream>
#include <iostream>

int main(){
    
    char key;
    char * file_name= nullptr;
    string filename;
    string file;
    int num_movies;  //initialize user input variables
    
    do {
        //welcome message and menu options
        cout << "Welcome to your Movie archive"<<endl;
        cout << "Lets start adding movies to your archive"<< endl;
        cout << "To Add movies    press  (1)"<<endl;
        cout << "To Open archive  press  (2)"<<endl;
        cout << "To Find oldest   press  (3)"<<endl;
        cout << "To Exit          press  (4)"<<endl;
        cout << "Choose one option:"<<endl;
        
        cin >> key; //get option for the swicth
        
        switch (key) {
                
            case 49:{
                
                cin.ignore();
                cout << "Enter a filename (/user/location/file.txt): ";
                getline(cin,filename);                                  //  Get file name from user
                cout <<""<<endl;                                        //  /Users/jlroo/Desktop/movies.txt
                
                cout <<"How many movies are you archiving today?" <<endl;
                cin >> num_movies;
                
                write_file(filename,num_movies);                        // function to add movie to the file

            }

                break;
                
            case 50:{
                
                    cin.ignore();
                    cout << "To open a file enter the filename (/user/location/FILE_NAME.txt): ";
                    getline(cin,file);                                  //  Get file name from user
                    cout <<""<<endl;

                    file_name = new char[file.length() + 1];
                    strcpy(file_name, file.c_str());
                    write_console(file_name);                           // funtion to read a file and write to console

            }
                break;
                
            case 51:{
                
                cin.ignore();cin.clear();
                cout << "Open a file to start searching (/user/location/FILE_NAME.txt): ";
                getline(cin,file);                                 //  Get file name from user
                cout <<""<<endl;
                
                file_name = new char[file.length() + 1];
                strcpy(file_name, file.c_str());
                find_oldest_movie(file_name);                       // function to find the oldest movie
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