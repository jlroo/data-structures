//
//  BattleShip_game.cpp
//  Game
//
//  Created by jlroo 9/5/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#include <iostream>
using namespace std;

void board(char * * array, int size) {
    
    for (int i = 0; i < size; i++) { //so for every row create a column of size 3
        
        cout << i;
        cout << " ";
        
        for (int j = 0; j < size; j++) {
            cout << array[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

void top_numbers(int user) { // numbers top header
    for (int k = 0; k < user; k++) {
        cout << k;
        cout << " ";
    }
}

void battle_board(char * * board_array, int user_size) {
    
    cout << "  ";
    top_numbers(user_size);
    cout << "" << endl;
    
    for (int i = 0; i < user_size; i++) { //so for every row create a column of size 3
        
        cout << i;
        cout << " ";
        
        for (int j = 0; j < user_size; j++) {
            cout << board_array[i][j];
            cout << " ";
        }
        cout << endl;
    }
    
}

void locate_ship(int * * array, int user_size, int num_ships) {
    
    for (int i = 0; i < num_ships; i++) { //create the ships
        array[rand() % user_size][rand() % user_size] = 1;
    }
    
    /*********************************************************************
     ********* uncomment to see where the ships are located **************
    
    cout<<"  ";top_numbers(user_size);
    cout << "" << endl;
    for (int i = 0; i < user_size; i++) { //so for every row create a column of size 3
        
        cout << i;
        cout << " ";
        
        for (int j = 0; j < user_size; j++) {
            cout << array[i][j];
            cout << " ";
        }
        cout << endl;
    }
     *********************************************************************
     *********************************************************************/
}

bool ships_position(int * * ships_board, char * * initial_board ,int user_size,int row, int col) {
    int num_hits=0;
    
    if (ships_board[row][col] == 1) {
        cout << "xXx You sunk my battleships! xXx" << endl;
        swap(initial_board[row][col], initial_board[row][col] = 88);
        cout<<""<<endl;
        cout <<" ** Current Board **"<<endl;
        cout<<""<<endl;
        battle_board(initial_board, user_size);
       return ++num_hits=1;
    }
    
    else {
        swap(initial_board[row][col], initial_board[row][col] = 42);
        cout << "*** You missed try again! ***" << endl;
        cout <<" ** Current Board **"<<endl;
        cout<<""<<endl;
        battle_board(initial_board, user_size);
        return num_hits=0;
    }
}

int main() {
    int user_size, num_ships;
    char * * initial_board;
    int * * ships_board;
    int row;
    int col;
    char play_again='y';
    
    cout << "***** Battleship *****" << endl;
    cout << "How many rows/columns is the board? ";
    cin >> user_size;
    
    /*************** CREATE THE BATTLESHIP BOARD AND SET ALL ELEMENTS TO 0 *********/
    
    initial_board = new char * [user_size]; // create a row depending in user size
    for (int i = 0; i < user_size; i++) { //create a column for every row depending in user input
        initial_board[i] = new char[user_size];
    }
    
    cout << "" << endl;
    for (int i = 0; i < user_size; i++) { //make division lines
        cout << "--";
    }
    cout << "" << endl;
    cout << "  ";
    top_numbers(user_size);
    cout << "" << endl;
    
    board(initial_board, user_size); //make initial array
    
    for (int i = 0; i < user_size; i++) { //make division lines
        cout << "--";
    }
    cout << "" << endl;
    
    /******************  BATTLESHIP BOARD **********************/
    
    cout<<""<<endl;
    cout << "A " << user_size << "x" << user_size << " board has been created.\n";
    cout << "How many ships? ";
    cin >> num_ships;
    
    ships_board = new int * [user_size];
    
    for (int i = 0; i < user_size; i++) {
        ships_board[i] = new int[user_size];
    }
    
    locate_ship(ships_board, user_size, num_ships); // create ships
    
    int total_hits=0;
    
    do {
        cout << "@@@ Type coordenates to fire a missile @@@"<<endl;
        cout << " Y-coordenate:";
        cin >> row;
        cout << " X-coordenate:";
        cin >> col;
        cout << "" << endl;
        bool num_hits=ships_position(ships_board,initial_board, user_size, row, col); // Determine if ship was hit add to total hit score
        total_hits=total_hits+num_hits;
        cout<<""<<endl;
        cout<<"Total number of Hits: "<<total_hits<<endl;
        
    }while (total_hits != num_ships);
    
    cout <<"########################################"<< endl;
    cout <<"#   *_    _* !!  YOU WIN !! *_    _*   #"<< endl;
    cout <<"#   * \  / *   !!!!!!!!!!   * \  / *   #"<< endl;
    cout <<"#      \/         !!!!         \/      #"<< endl;
    cout <<"#            !!  YOU WIN !!            #"<< endl;
    cout <<"#  ^               !!!!             ^  #"<< endl;
    cout <<"#  ┴  C O N G R A T U L A T I O N S ┴  #"<< endl;
    cout <<"########################################"<< endl;
    
    /*********** Restart Game ***********/
    /*** Restart the ship locations  ***/
    
    for (int j = 0; j < user_size; j++) {
        delete[] ships_board[j]; //delete every column instantiated
    }
    delete[] ships_board; //get rid of the rest of the array
    
    /*** Restart the board ***/
    
    for (char j = 0; j < user_size; j++) {
        delete[] initial_board[j]; //delete every column instantiated
    }
    delete[] initial_board; //get rid of the rest of the array
    
    cout<<""<<endl;
    
    cout<<"Do you want to play again?(y/n)"<<endl;
    cin>>play_again;
    
    if (play_again=='y') {
        return main();
    }
    else{
        cout<<"Thank you for playing, Goodbye!"<<endl;
        return 0;
    }
    
}


