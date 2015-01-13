//
//  HW_6.cpp
//  C++
//
//  Created by jlroo on 10/30/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#include "HW_6.h"


int main() {
    
    char key;
    char B_or_Q = '\0';
    int Tree_comparison = 0;
    
    string filename;                                                            //User filename
    string filename_out;                                                        //file to store genome words
    string open_file;
    
    char * genome_file_name;
    char * gnome_test_file;
    char * results_file_out;
    
    vector<string> words;
    vector<string> test_words;
    vector<string> sorted_data;
    vector<string> t_sorted;
    vector<double> code_count;

    BTreeNode * Btree_a = nullptr;
    BTreeNode * Btree_b = nullptr;
    QTreeNode * Qtree_a = nullptr;
    QTreeNode * Qtree_b = nullptr;

    do {
        
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
                
                cout <<""<<endl;
                cout << "* * * * * * * * * * * * * GENOME FILE * * * * * * * * * * * * * *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "*       To start analyzing a genome file please enter           *"<<endl;
                cout << "*             the name and location of your file                *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "*                 [/user/location/FILE_IN.txt]                  *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;
                cout << "File containing Genome sequence to analize:";
                cin.ignore();
                cin.sync();
                
                //getline(cin,filename);                                                                      //  Get file name from user
                filename="/Users/jlroo/Desktop/genome_file.txt";
                genome_file_name = new char[filename.length() + 1];
                strcpy(genome_file_name, filename.c_str());
                
                string genome_read (genome_file_name);
                
                genome_read.erase(21,11);
                
                cout << ""<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
                cout << "*                                                                                             *"<<endl;
                cout << "*                       Choose the data structure to use in your analysis                     *"<<endl;
                cout << R"(*                                                                                             *
*      [Binary Tree]                                [Quaternary Tree]                         *
*           _x_                                _____________x___________                      *
*          /   \                        ______/           /   \         \_______              *
*         /     \                      /              ___/     \__              \             *
*        x       x                    /              /            \              \            *
*       / \     / \                __x__          __x__          __x__          __x__         *
*      x   x   x   x             _/ / \ \_      _/ / \ \_      _/ / \ \_      _/ / \ \_       *
*     / \ / \ / \ / \           /  /   \  \    /  /   \  \    /  /   \  \    /  /   \  \      *
*     x x x x x x x x          x  x     x  x  x  x     x  x  x  x     x  x  x  x     x  x     *)"<<endl;
                cout << "*                                                                                             *"<<endl;
                cout << "*                                                                                             *"<<endl;
                cout << "*                              For Binary Tree       [Press] (B)                              *"<<endl;
                cout << "*                              For Quaternary Tree   [Press] (Q)                              *"<<endl;
                cout << "*                                                                                             *"<<endl;
                cout << "*                                     [Choose one option]                                     *"<<endl;
                cout << "*                                                                                             *"<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;
                cin.sync();
                cin>>B_or_Q;
                
                    switch (B_or_Q) {
                        
                        case 'B'|'b':{
                            sorted_data.clear();
                            code_count.clear();

                            get_words(genome_file_name,words,B_or_Q);
                            
                            genome_read = genome_read.insert(genome_read.length()-4, "test_file_BT");
                            gnome_test_file =  new char[genome_read.length()+1];
                            strcpy(gnome_test_file, genome_read.c_str());
                            
                            get_test_file(gnome_test_file,test_words);
                            
                            string file_reads (gnome_test_file);
                            file_reads.erase(21,12);
                            file_reads = file_reads.insert(file_reads.length()-4, "Results_Btree");
                            results_file_out =  new char[file_reads.length()+1];
                            strcpy(results_file_out, file_reads.c_str());
                            
                            Sort_vector(words,sorted_data,code_count);
                            Sort_vector_test(test_words,t_sorted);
                            
                            int end = floorl(sorted_data.size());
                            int end_2 = floorl(t_sorted.size());

                            Btree_a = vector_To_BST(sorted_data,0,end);
                            Btree_b = vector_To_BST(t_sorted,0,end_2);
                           
                            Tree_comparison = TreeEqual(Btree_a,Btree_b);
                            
                            write_vector_to_screen(sorted_data,code_count,Tree_comparison);
                            write_vector_to_file(sorted_data,code_count,results_file_out,Tree_comparison);            //resutls of the analisys
          
                            test_words.clear();
                            t_sorted.clear();
                            words.clear();
                            
                        }
                            break;
                        
                        case 'Q'|'q':{
                            
                            sorted_data.clear();
                            code_count.clear();
                            
                            get_words(genome_file_name,words,B_or_Q);
                            genome_read = genome_read.insert(genome_read.length()-4, "test_file_QT");
                            gnome_test_file =  new char[genome_read.length()+1];
                            strcpy(gnome_test_file, genome_read.c_str());
                            get_test_file(gnome_test_file,test_words);
                            
                            string file_reads (gnome_test_file);
                            file_reads.erase(21,12);
                            file_reads = file_reads.insert(file_reads.length()-4, "Results_Qtree");
                            results_file_out =  new char[file_reads.length()+1];
                            strcpy(results_file_out, file_reads.c_str());

                            Sort_vector(words,sorted_data,code_count);
                            Sort_vector_test(test_words,t_sorted);
                    
                            int end = floorl(sorted_data.size());
                            int end_2 = floorl(t_sorted.size());
                            
                            Qtree_a = vector_To_QST(sorted_data,0,end);
                            Qtree_b = vector_To_QST(sorted_data,0,end_2);
                            
                            Tree_comparison = QTreeEqual(Qtree_a,Qtree_b);

                            write_vector_to_screen(sorted_data,code_count,Tree_comparison);
                            write_vector_to_file(sorted_data,code_count,results_file_out,Tree_comparison);            //resutls of the analisys
                            
                            test_words.clear();
                            t_sorted.clear();
                            words.clear();
                            
                        }
                            break;
                        
                    default:{
                            cout << "This is not an option, try again or exit (4)"<<endl<<endl;
                            cout << "You can create a Binary Tree OR a Quaternary Tree"<<endl;
                            cout << " "<<endl;
                        return main();
                    }
                }
            }
                break;
                
            case 50:{
                cin.ignore();
                cout << "* * * * * * * * * * * * GENOME  ARCHIVE * * * * * * * * * * * * *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "*        To open a file with genome sequence results            *"<<endl;
                cout << "*            please enter a filename and location               *"<<endl;
                cout << "*                                                               *"<<endl;
                cout << "*              [/user/location/file_RESULTS.txt]                *"<<endl;
                cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
                cin.ignore();
                cin.sync();

                display_results();

            }
                break;
                
            case 51:{
                cin.ignore();
                cin.sync();
                
                if (B_or_Q=='\0') {
                    cout<<"First create a Binary tree with of the sequence"<<endl;
                    cout<<"in the main menu select [1] "<<endl;
                    cout<<""<<endl;
                    return main();
                    }
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
                switch (B_or_Q) {
                    
                    case 'b'|'B': {
                        int s_val = Search(val, Btree_a);
                        if (s_val==1){
                            for (int i=0; i<sorted_data.size(); i++) {
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
                    case 'q'|'Q':{
                        
                        int s_val = QSearch(val, Qtree_a);
                        if (s_val==1){
                            for (int i=0; i<sorted_data.size(); i++) {
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
                    default:
                        break;
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


