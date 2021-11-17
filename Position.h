#ifndef POSITION_H
#define POSITION_H

#include <Windows.h>

class Position
{
public:
	Position(); //default position class constructor
	Position(int x, int y); //constructor that sends parameters x and y of type into the setCursorPos fun
	void setCursorPos(int x, int y); //sets users cursor coord.X to x and cord.Y to y where each coordinate space is one char
	void setX(int x); //set x individually
	void setY(int y); //set y invididually
	int getX(); //returns the position coordinate of x
	int getY(); //returns the postion coordinate of y
	void moveDown(); // move down cursor function
	void moveUp(); // move up cursor function
	void moveRight(); // move right cursor function
	void moveLeft(); // move left cursor functionzzc
private:
	COORD coord;
};

#endif // !POSITION_H
#pragma once
