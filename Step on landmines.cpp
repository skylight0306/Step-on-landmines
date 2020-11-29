#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
void SetGame();
int main()
{
	int command = -1;
	cout << "*********Step on landmines*********" << endl;
  	cout << "* 0. QUIT                         *" << endl;
 	cout << "* 1. Start Game                   *" << endl;
 	cout << "***********************************" << endl;
    cin >> command;
    if ( command == 0 ) return 1;	
 	else if (command == 1 ) SetGame();
	
}

void SetGame()
{
	int row = 0;
	int col = 0;
	int x , y;	
	int k = 0; // total landmines
	// set the value of the array
	cout << "Input row number:" ; 	
	cin >> row;	
 	cout << endl << "Input col number:" ; 	
	cin >> col;		
 	cout << endl << "Input k number(total landmines):" ;
	cin >> k; 		
	
	char map[row][col];
	
	// initial the array of map
	for (int i = 0;i < row ; i++)
		for (int j = 0; j < col ; j++)
			map[i][j] = '0';
			

	// set the landmines 
	for (int i = 0; i < k ;i++) 
	{
		cout << endl << "Input the landmine location:" ;
		cin >> x >> y;
		map[x-1][y-1] = '*'; // set landmine at the location (x,y)
		
		
		
		// count the surrounding mines
		if ( x != 1 ) // not the first row of the map
		{
			if ( y != 1 && map[x-2][y-2] != '*') map[x-2][y-2] ++; // not the first col of the map
			if (map[x-2][y-1] != '*') map[x-2][y-1] ++; // not the first col of the map		
			if ( y != col && map[x-2][y] != '*') map[x-2][y] ++; // not the first col of the map			
		}
		

		if ( y != 1 && map[x-1][y-2] != '*') map[x-1][y-2] ++;
		if ( y != col &&map[x-1][y] != '*') map[x-1][y] ++;
		
		if (x != row)	// not the last row of the map
		{
			if ( y != col && map[x][y] != '*') map[x][y] ++; // not the last col of the map	
			if ( y != 1 && map[x][y-2] != '*') map[x][y-2] ++; // not the last col of the map 
			if ( map[x][y-1] != '*') map[x][y-1] ++; // not the last col of the map				
		}
	
	
	
	
		for (int i = 0;i < row ; i++)
		{
			for (int j = 0; j < col ; j++)
				cout << map[i][j] << "  ";
			cout << endl << endl;				
		}
		
	
		cout << "------------------------------------" << endl;
	
	
	}
	/*
	// show the map
	for (int i = 0;i < row ; i++)
	{
		for (int j = 0; j < col ; j++)
			cout << map[i][j] << "  ";
		cout << endl << endl;				
	}
	*/
} 


