#include <iostream>
#include "Position.h"

Position::Position() {}
//default constructor


Position::Position(int x, int y) //constructor that sends parameters x and y of type int to setCursorPos fnc

{
	setCursorPos(x, y);
}

void Position::setCursorPos(int x, int y) //sets users cursor coord.X to x and cord.Y to y where each coordinate space is one char 

{
	coord.X = x;

	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Position::setX(int x)  //sets the x coordinate 

{
	coord.X = x;
}

void Position::setY(int y) //sets the y coordinate

{
	coord.Y = y;
}

int Position::getX() //returns the x coordinate

{
	return coord.X; ; //defines coordinates of a character cell, top left of console is (0,0)

}

int Position::getY() //returns the y coordinate 

{
	return coord.Y; ; //defines coordinates of a character cell, top left of console is (0,0)

}