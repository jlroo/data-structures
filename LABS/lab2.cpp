/*
 * BattleShip.cpp
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

bool set_ships(int **& matrix, int size, int num1);

int main()
{
     int ** B;
     int size, num_ships, row, col;
     int num_hits=0;
   
     cout << "***** Battleship *****" << endl;
     cout << "How many rows/columns is the board? ";
     cin >> size;
   
    /* CREATE THE BATTLESHIP BOARD AND SET ALL ELEMENTS TO 0*/


   
     cout << "A " << size << "x" << size << " board has been created.\n";
     cout << "How many ships? ";
     cin >> num_ships;
     set_ships(B,size,num_ships);
   
     while(num_hits!=num_ships)
     {
          cout << "What row:";
          cin >> row;
          cout << "What col: ";
          cin >> col;
       
        /*DETERMINE IF IT’S A HIT. IF SO, UPDATE INFORMATION & TELL USER.*/

     }
   
     cout << "You sunk my battleships!" << endl;
   
    /*CLEAN UP YOUR MEMORY*/

   
     return 1;
}

bool set_ships(int **& matrix, int size, int num1){
 /* CREATE BOOL SET_SHIP*/
}