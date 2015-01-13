//
//  gnome_tree.cpp
//  C++
//
//  Created by jlroo and Zijun Chen on 12/4/14.
//  Copyright (c) 2014 Jose L Rodriguez & Zijun Chen. All rights reserved.
//

#include "gnome_tree.h"


int main() {
    
    char key;
    int Tree_comparison;
    string filename;                                            //ORIGIN GENOME INFILE
    string filename_out;                                        //FILE TO STORE GENOME WORDS
    string filename_test;                                       //INFILE TO TEST THE ORIGIN GENOME FILES
    string open_file;
    
    char * genome_file_name;
    char * gnome_test_file;
    char * results_file_out;
    
    vector<string> words;                                       //VECTORS TO STORE THE DATA FROM THE INFILES
    vector<string> test_words;
    vector<string> sorted_data;
    vector<string> t_sorted;
    vector<double> code_count;
    
    genome_node * Gtree_a = nullptr;                            // INITIALIZE TREES GLOBALY
    genome_node * Gtree_b = nullptr;
  
    do {
        
         cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
         cout<<"*                                                                   *"<<endl;
         cout<<"*                    INSTRUCTIONS OF HOW TO USE                     *"<<endl;
         cout<<"*                          THIS PROGRAM                             *"<<endl;
         cout<<"*                                                                   *"<<endl;
         cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
         cout<<"*                                                                   *"<<endl;
         cout<<"* This program recognize exact matches in a DNA sequences of a      *"<<endl;
         cout<<"* sample genome sequence file and compares it with an original DNA  *"<<endl;
         cout<<"* sequence file and determines if there are mutation on the sample  *"<<endl;
         cout<<"* from the original DNA sequence,User have to input an:             *"<<endl;
         cout<<"*                                                                   *"<<endl;
         cout<<"* ORIGIN Gnome sequence FILE: [/user/location/ORIGIN_GENOME.txt]    *"<<endl;
         cout<<"*                                                                   *"<<endl;
         cout<<"* The user also have to input the TEST Genome sequence file that    *"<<endl;
         cout<<"* is going to be compare with the original sequence.                *"<<endl;
         cout<<"* User have to input a:                                             *"<<endl;
         cout<<"*                                                                   *"<<endl;
         cout<<"* TEST Gnome sequence FILE: [/user/location/TEST_GENOME.txt]        *"<<endl;
         cout<<"*                                                                   *"<<endl;
         cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
         cout<<endl;
         cout<<endl;
        //welcome message and menu options
        cout << "* * * * * * * * * * * * * GENOME SEQUENCE * * * * * * * * * * * * * *"<<endl;
        cout << "*                                                                   *"<<endl;
        cout << "*                      Genome Sequence Analysis                     *"<<endl;
        cout << "*                                                                   *"<<endl;
        cout << "*        To analyse a Genome Sequence file          [press] (1)     *"<<endl;
        cout << "*        To open previous Genome Sequence Results   [press] (2)     *"<<endl;
        cout << "*        To search for a 'code' in the sequence     [press] (3)     *"<<endl;
        cout << "*        To Exit                                    [press] (4)     *"<<endl;
        cout << "*                                                                   *"<<endl;
        cout << "*                         [Choose one option]                       *"<<endl;
        cout << "*                                                                   *"<<endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;
        cin >> key;
        
        switch (key) {
                
            case 49:{
                cout <<endl;
                cout <<endl;
                cout << "                * * * * * * * * * * * * * * * * * * * * *"<<endl;
                cout << R"(                *                                       *
                *      [Balanced Binary Search Tree]    *
                *                  _x_                  *
                *                 /   \                 *
                *                /     \                *
                *               x       x               *
                *              / \     / \              *
                *             x   x   x   x             *
                *            / \ / \ / \ / \            *
                *            x x x x x x x x            *)"<<endl;
                cout << "                * * * * * * * * * * * * * * * * * * * * *"<<endl;
                
                cout <<endl;
                cout <<endl;
                
                cout << "* * * * * * * * * * * ORIGIN GENOME FILE * * * * * * * * * * * *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "*       To start analyzing a genome file please enter           *"<<endl;
                cout << "*             the location and name of your file                *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "*                 [/user/location/FILE_IN.txt]                  *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;
               
                cout << "File containing Genome sequence to analize:";

                cin.ignore();
                cin.sync();
                // getline(cin,filename);                               //  Get file name from user
                cout<<endl;
                filename="/Users/jlroo/Desktop/ORIGIN_GENOME.txt";   // NO EQUIVALENT TREES NEED TO CHANGE PATH TO YOUR PC
              //  filename="/Users/jlroo/Desktop/genome_file.txt";       // EQUIVALENT TREES NEED TO CHANGE PATH TO YOUR PC
                genome_file_name = new char[filename.length() + 1];
                strcpy(genome_file_name, filename.c_str());
                string genome_read (genome_file_name);
                genome_read.erase(21,11);
                
                get_words(genome_file_name,words);
                
                cout << "Enter Test Genome Sequence:";
            //    getline(cin,filename_test);                           //  Get file name from user
                cout<<endl;
                filename_test="/Users/jlroo/Desktop/TEST_GENOME.txt"; // FILE TO COMPARE TREES NEED TO CHANGE PATH TO YOUR PC
                gnome_test_file =  new char[filename_test.length()+1];
                strcpy(gnome_test_file, filename_test.c_str());
                
                get_test_file(gnome_test_file,test_words);
                        
                string file_reads (gnome_test_file);
                file_reads.erase(21,11);
                file_reads = file_reads.insert(file_reads.length()-4, "Results_Gtree");     // CREATE FILE IN THE SAME PATH OF THE ORIGIN FILE
                results_file_out =  new char[file_reads.length()+1];
                strcpy(results_file_out, file_reads.c_str());
                
                Sort_vector(words,sorted_data,code_count);              //SORT THE VECTOR CREATED FROM THE INFILE, DELETE REPATED WORDS
                Sort_vector_test(test_words,t_sorted);                  //SORT THE TEST VECTOR CREATED FROM THE INFILE, DELETE REPEATED WORDS
                
                int end = floorl(sorted_data.size());
                int end_2 = floorl(t_sorted.size());
                
                Gtree_a = vector_To_GST(sorted_data,0,end);             // TREE IMPLEMENTATION
                Gtree_b = vector_To_GST(t_sorted,0,end_2);              // TREE IMPLEMENTATION
                
                Tree_comparison = genome_tree_Equal(Gtree_a,Gtree_b,sorted_data,code_count);    //COMPARE THE TWO TREES
                
                write_vector_to_file(sorted_data,code_count,results_file_out,Gtree_a,Gtree_b,Tree_comparison); //SAVE RESULTS OF THE ANALYSIS
                
                test_words.clear();
                t_sorted.clear();
                words.clear();

            }
            
                break;
                
            case 50:{           //OPEN A PREVIOUS RESULTS AND DISPLAY IT IN THE SCREEN
                cin.ignore();
                cout << "* * * * * * * * * * * * GENOME ANALYSIS * * * * * * * * * * * * *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "*        To open a file with genome sequence results            *"<<endl;
                cout << "*            please enter a filename and location               *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "*              [/user/location/ANALYSIS_RESULTS.txt]            *"<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
                
                display_results();  // NEED TO CHANGE THE PATH FROM  THE HEADER FILE TO YOUR OWN PATH TO DISPLAY RESULTS
                
            }
                break;
        
    case 51:{               // SEARCH FOR A WORD IN THE TREE AND PRINT OUT ITS STATISTICS
        cin.ignore();
        cin.sync();
        
        if (Gtree_a==nullptr) {     // IF THERE ISNT A TREE GO BACK TO THE MAIN AND CREATE A TREE
            cout<<"First create a Binary tree of a Genome sequence"<<endl;
            cout<<"to do that select [1] in the main menu"<<endl;
            cout<<""<<endl;
            return main();
        }
        cout << " "<<endl;
        cout << "* * * * * * * * * * * * * GENOME SEARCH * * * * * * * * * * * * *"<<endl;
        cout << "*                                                               *"<<endl;
        cout << "*       You can search for a 'code' in the genome sequence      *"<<endl;
        cout << "*                and look for its statistics                    *"<<endl;
        cout << "*                                                               *"<<endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
        cout << "Search for a code in the genome sequence "<<endl;
        string val;
        cout<<"Search genome sequence: ";
        cin>>val;
        cin.sync();
        
                int s_val = Search(val, Gtree_a);           //SEARCH IF THE WORD IS IN THE TREE
                if (s_val==1){                              // IF THE WORD IS IN THE TREE RETURN 1
                    int data_sise =floorl(sorted_data.size());
                    for (int i=0; i<data_sise; i++) {       // FIND THE WORD AND PRINT ITS COUNT IN THE SCREEN
                        if (val==sorted_data[i]) {
                            cout<<"You are searching for the genome code: "<<val<<endl;
                            cout<<"This code appears: "<< code_count[i]<<" times."<<endl;
                            cout<<"In the genome sequnce file."<<endl;
                            cout<<""<<endl;
                        }
                    }
                }
                else {
                    cout<<"The code "<<val<<" was not found in the genome sequence"<<endl;
                }

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
