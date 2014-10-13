//
//  HW_2.cpp
//  COMP_271
//  FALL 2014
//  Created by jlroo on 9/3/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#include <iostream>
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

int main(){
    
    char key;
    char input[300];
    int archive_size=0;
    int num_movies=0;
    char * t_user = nullptr;
    char * d_user = nullptr;
    char * gn_user = nullptr;
    char * rt_user = nullptr;
    int  du_user = 0;
    int  yr_user=0;

    //initialize user input variables
    do {
        
        Movie ** Movie_file;// File

        //welcome message and menu options
        cout << "Welcome to your Movie archive"<<endl;
        cout << "Lets start adding movies to your archive"<< endl;
        cout << "To Start         press  (1)"<<endl;
        cout << "To Open archive  press  (2)"<<endl;
        cout << "To Exit          press  (3)"<<endl;
        cout << "Choose one option:"<<endl;

        cin >> key; //get option for the swicth
        
        switch (key) {
            
            case 49:{
                
                cout << "How many movies are you entering today:" <<endl;
                cin >> num_movies;
                archive_size=num_movies;
                
                Movie_file = new Movie * [num_movies];
                
                cout << "Consider Movie schema: " <<endl;
                cout << "Title:     <YOUR MOVIE TITLE>" <<endl;
                cout << "Director:  <YOUR MOVIE DIRECTOR >" <<endl;
                cout << "Duration:  <YOUR MOVIE DURATION>" <<endl;
                cout << "Year:      <YEAR OF MOVIE RELEASE>" <<endl;
                cout << "Genre:     <YOUR MOVIE GENRE>" <<endl;
                cout << "Rating:    <X,XX,XXX,XXXX,XXXXX>"<<endl;
                cout << "Start Entering your Movies"<<endl<<endl;
                
                cin.ignore();
                
                for (int i = 0; i < num_movies; i++) {
                
                cout << "Title:";
                cin.getline(input,300);
                t_user= new char[strlen(input)+1];
                strcpy(t_user,input);
                
                cout << "Director:";
                cin.getline(input,300);
                d_user= new char[strlen(input)+1];
                strcpy(d_user,input);
                
                cout << "Duration:";
                cin>>du_user;
                
                cout << "Release Year:";
                cin>>yr_user;
                cin.ignore();
                
                cout << "Genre:";
                cin.getline(input,300);
                gn_user= new char[strlen(input)+1];
                strcpy(gn_user,input);
                
                cin.sync();
                
                cout << "Rating:";
                cin.getline(input,300);
                rt_user= new char[strlen(input)+1];
                strcpy(rt_user,input);
                cout<<""<<endl;
                
                Movie_file[i]= new Movie(t_user,d_user,du_user,yr_user,gn_user,rt_user);
                
                string title =      Movie_file[i]->get_title();
                string director =   Movie_file[i]->get_director();
                string duration =   to_string(Movie_file[i]->get_runtime());
                string year =       to_string(Movie_file[i]->get_release_year());
                string genre =      Movie_file[i]->get_genre();
                string rating =     Movie_file[i]->get_rating() ;
                    
                cout<<"***************** INFORMATION ABOUT *******************"<<endl;
                cout<<"                ****  YOUR MOVIE ****                  "<<endl;
                cout<<"* Title: "       <<  title                              <<endl;
                cout<<"* Director: "    <<  director                           <<endl;
                cout<<"* Duration: "    <<  duration                           <<endl;
                cout<<"* Release Year: "<<  year                               <<endl;
                cout<<"* Genre: "       <<  genre                              <<endl;
                cout<<"* Rating: "      <<  rating                             <<endl;
                cout<<"*******************************************************"<<endl<<endl;
                    
                }
                
            }
                break;
            
            case 50:{
                cout <<"Archive"<<endl;
                cout<<"Current Movies in the Archive: "<<endl;
                
                for(int i=0; i<archive_size; i++){
                    
                    cout<<"********************** MOVIE ARCHIVE ******************"<<endl;
                    cout<<"* Title: "       <<  Movie_file[i]->get_title()         <<endl;
                    cout<<"* Director: "    <<  Movie_file[i]->get_director()      <<endl;
                    cout<<"* Duration: "    <<  Movie_file[i]->get_runtime()       <<endl;
                    cout<<"* Release Year: "<<  Movie_file[i]->get_release_year()  <<endl;
                    cout<<"* Genre: "       <<  Movie_file[i]->get_genre()         <<endl;
                    cout<<"* Rating: "      <<  Movie_file[i]->get_rating()        <<endl;
                    cout<<"*******************************************************"<<endl<<endl;
                    
                }

            }
                break;
            
            case 51:{
                cout << "!BYE!"<<endl;
            }
                break;
            
            default:{
                cout << "Not an option, try again or exit (2)"<<endl<<endl;
            }
        }
        
    }
    while (key!=51);
    delete [] t_user;
    delete [] d_user;
    delete [] gn_user;
    delete [] rt_user;
}

