#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <conio.h>
#include "Editor.h"
#include "Position.h"

using namespace std;

//Initialize cursor 
void CursorInit(Position coordinate) { // function that gets the cursor placement and connects it to each coordinate

	HANDLE hStdout; 
	COORD coord;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	coord.X = coordinate.getX(); // gets the x coordinate of the cursor

	coord.Y = coordinate.getY(); // gets the y coordinate of the cursor 

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
}

int main()
{
	Position pos(0, 0); //sets the coordinate position to (0,0)
	Editor ed("input.txt"); // passes the text file into the editor class

	CursorInit(pos); // calls the cursorInIt function 

	ed.run(); // calls the program to run the run function from the editor implementation file


}