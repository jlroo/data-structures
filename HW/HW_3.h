//
//  HW_3.h
//  C++
//  COMP_271
//  FALL 2014
//  Created by jlroo on 9/25/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//
#ifndef HW_3
#include<fstream>
#include <iostream>
#include <algorithm>
using namespace std;

class Movie{
    
private:
    
    char * title; //title of movie
    char * director; //director of movie
    int runtime; //how long in mins the movie is
    int release_year; //year it was released
    char * genre; //is it romance comedy
    char * rating; //is it pg-13 or R
    
public:
    //constructors
    Movie(char *t, char *d, int r, int yr, char *gn, char *rt);
    
    //deconstructor
    //~Movie();
    
    //mutators (SETTERS)
    bool set_title(char *t);
    bool set_director( char *d);
    bool set_runtime(int time);
    bool set_release_year(int year);
    bool set_genre(char * gn);
    bool set_rating(char * rt);
    bool set_movie_name(char * name);
    
    //accessor (GETTERS)
    char * get_title();
    char * get_director();
    int get_runtime();
    int get_release_year();
    char * get_genre();
    char * get_rating();
    char * get_movie_name();
};

Movie::Movie(char *t,char *d,int r, int yr, char *gn, char *rt) {
    title=t;
    director=d;
    runtime=r;
    release_year=yr;
    genre=gn;
    rating=rt;
}

/*********************************************************************************************************
 The mutators(SETTERS):A mutator is a member function for editing the contents of a protected data member.
 ********************************************************************************************************/

bool Movie::set_title(char * t) {
    
    if (title!=NULL) {
        delete title;
    }
    
    title = new char(strlen(t) + 1);
    strcpy(title,t);
    return 1;
    
}

bool Movie::set_director(char * d){
    
    if(director!=NULL){
        delete director;
    }
    
    director = new char(strlen(d) + 1);
    strcpy(director, d);
    return 1;
}

bool Movie::set_runtime(int r){
    if(runtime!=0){
        runtime=r;
        return 1;
    }
    return 1;
}

bool Movie::set_release_year(int yr){
    if(release_year!=0){
        release_year=yr;
        return 1;
    }
    return 0;
}

bool Movie::set_genre(char * gn){
    if(genre!=NULL){
        delete genre;
    }
    genre = new char(strlen(gn) + 1);
    strcpy(genre, gn);
    return 1;
}

bool Movie::set_rating(char * rt){
    if (rating!=NULL) {
        delete rating;
    }
    rating =new char(strlen(rt)+1);
    strcpy(rating,rt);
    return 1;
}


/*********************************************************************************************************
 The accessors(GETTERS):An accessor is a member function to retrieve the contents of a protected data member.
 *********************************************************************************************************/

char * Movie::get_title(){
    return title;
}
char * Movie::get_director(){
    return director;
}

int Movie::get_runtime(){
    return runtime ;
}

int Movie::get_release_year(){
    return release_year;
}

char * Movie::get_genre(){
    return genre;
}

char * Movie::get_rating(){
    return rating;
}


bool find_oldest_movie(string filename){
    
    char input[300];
    char * t_user = nullptr;
    char * d_user = nullptr;
    char * gn_user = nullptr;
    char * rt_user = nullptr;
    int  du_user = 0;
    int  yr_user=0;
    int num=0;
    int total_num=0;
    string line;
    string head;
    ifstream file_search;
    
    file_search.open(filename);
    Movie ** Movie_file; // Movie File
    Movie_file = new Movie *;
   
    if (file_search.is_open())
    {
        while ( getline (file_search,line) ){
            ++total_num;                        //get the number of lines
        }
        file_search.close();
    }
    num=total_num-1;                            //number of lines minus the top line
    
    file_search.open(filename);
    getline(file_search,head); //This line gets the number at the top of the file
    
    do {
        if (file_search.is_open()){
            while (!file_search.eof()) {
                
                for (int i=0; i<num; i++) {
                file_search.getline(input, 300, ',');
                t_user= new char[strlen(input)+1];
                strcpy(t_user,input);

                file_search.getline(input, 300, ',');
                d_user= new char[strlen(input)+1];
                strcpy(d_user,input);
                
                file_search >>du_user;
                file_search.ignore();                  //ignore any unread character after the last operator
                
                file_search>>yr_user;
                file_search.ignore();
                
                file_search.getline(input, 300, ',');
                gn_user= new char[strlen(input)+1];
                strcpy(gn_user,input);
                
                file_search.getline(input, 300, '\n');
                rt_user= new char[strlen(input)+1];
                strcpy(rt_user,input);
                
                Movie_file[i]= new Movie(t_user,d_user,du_user,yr_user,gn_user,rt_user);
                }
            }
        }
    } while (!file_search.eof());
    
    file_search.clear();
    file_search.close();
    
    int * year;
    year= new int [num];
    
    string * oldest_t;
    string oldest_title;
    oldest_t= new string [num];
    
    cin.sync();   //remove any unread character from the standard input queue of characters
    
    for (int i=0; i<num; i++) {
        year[i]=Movie_file[i] -> get_release_year();
        oldest_t[i]=Movie_file[i] -> get_title();
    }
    
    int oldest_movie= *std::min_element(year,year+num);//find the smallest year from movies in the file
    
    for (int i=0; i<num; i++) {
        if (year[i]==oldest_movie) {
            oldest_title=oldest_t[i];
        }
    }
    
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout << "                                                 "<<endl;
    cout << "  The oldest movie is : "<<    oldest_title       <<endl;
    cout << "  it  was released in : "<<    oldest_movie       <<endl;
    cout << "                                                 "<<endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<""<<endl;
    
    delete [] Movie_file;
    delete [] year;
    return 1;
}

bool write_console(string file_name){                //get the file name from the user
    
    string title;
    string director;
    int runtime;
    int year;
    string genre;
    string rating;
    string head;
    
    ifstream fin;
    fin.open(file_name);
    getline(fin,head); //get the number at the top of the file
    
    cout<<"* * * * * * * * "<<endl;
    cout<<" "<<endl;
    cin.ignore();
    
        do {
            if (fin.is_open()){
                while (!fin.eof()) {
                    
                    getline(fin, title, ',');
                    getline(fin, director, ',');
                    fin >>runtime;
                    fin.ignore();                  //ignore any data line left after the last operator
                    fin>>year;
                    fin.ignore();
                    getline(fin, genre, ',');
                    getline(fin, rating, '\n');

                    cout <<"Title:"         << title    <<endl;
                    cout <<"Director:"      << director <<endl;
                    cout <<"Duration:"      << runtime  <<endl;
                    cout <<"Release Year:"  << year     <<endl;
                    cout <<"Genre:"         << genre    <<endl;
                    cout <<"Rating:"        << rating   <<endl;
                    cout <<""<<endl;

                    
                }
            }
        }
        while (!fin.eof());
        fin.clear();
        fin.close();
        cout<<"* * * * * * * * "<<endl;
        cout<<"End of the file "<<endl;
        cout<<"                "<<endl;
        return 1;
}


bool write_file( string filename, int num_movies){
    
    int  du_user = 0;
    int  yr_user=0;
    
    ofstream file;

        cout << "      !CONSIDER MOVIE SCHEMA!        "<<endl;
        cout << "*************************************"<<endl;
        cout << "* Title:     < MOVIE TITLE>         *"<<endl;
        cout << "* Director:  < MOVIE DIRECTOR>      *"<<endl;
        cout << "* Duration:  < MOVIE DURATION>      *"<<endl;
        cout << "* Year:      < YEAR OF RELEASE>     *"<<endl;
        cout << "* Genre:     < MOVIE GENRE>         *"<<endl;
        cout << "* Rating:    <X,XX,XXX,XXXX,XXXXX>  *"<<endl;
        cout << "*************************************"<<endl;
        cout<<" "<<endl;
    
        cin.ignore();cin.sync();    //remove any unread character from the standard input queue of characters

        file.open(filename.c_str(),std::ios::app); //open the file to write at the end of it without deliting other movies
    
    for (int i = 0; i < num_movies; i++) {
        
            file <<"\r\n";          //creates a new line to start writing on the file
            cout << "Title:";
            string title_user;
            getline(cin,title_user);
            file <<title_user << ",";

            cout << "Director:";
            string director_user;
            getline(cin,director_user);
            file <<director_user << ",";

            cout << "Duration:";
            cin>>du_user;
            file << du_user<< ",";

            cout << "Release Year:";
            cin>>yr_user;
            file <<yr_user << ",";
            cin.ignore();cin.sync();            //remove any unread character from the standard input queue of characters

            cout << "Genre:";
            string gen_user;
            getline(cin,gen_user);
            file << gen_user << ",";

            cout << "Rating:";
            string ra_user;
            getline(cin,ra_user);
            file << ra_user;
            cout<<" "<<endl;
        }
        file.close();
    
    return 1;
}
#endif /* defined(__C____HW_3__)*/
