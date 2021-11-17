#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <conio.h>
#include "Editor.h"
#include "Position.h"

using namespace std;

//Initialize cursor 


int main()
{
	Position pos(0, 0); //sets the coordinate position to (0,0)
	Editor ed("input.txt"); // passes the text file into the editor class

	
	ed.run(); // calls the program to run the run function from the editor implementation file


}