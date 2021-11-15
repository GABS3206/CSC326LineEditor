#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include <string>
#include <list>
#include "Node.h"
#include "LinkedList.h"
#include "ListInterface.h"
#include "Position.h"

using namespace std;

class Editor
{
public:
	Editor(); // default editor construtor
	Editor(string fileName); // editor construtor that passes the file through 
	void run(); // function that runs the editor program and runs the case switch
	void DisplayLines(); // function that displays the strings from the text file
	void CurrentLine(); // function that gets the current line in the text file 
	void WriteChar(char cmd); // function that allows the user to type in a new char, passes in a parameter that 
	void DeleteChar(); // function that allows the user to delete a char
	void Save(); // function that saves the user progress
	bool Quit(); // function that quits the program
	void DeleteCurrentLine(); // function that deletes the current line
private:
	string fileName, tempText; // filename variable
	char command; // command variable that is the variable used in the switch statement
	bool isRunning = true; // bool that checks if the code is running
	LinkedList<char> allText; // linked list definition that connects to the allText 
	fstream myFile; // variable for the file
};

#endif // !EDITOR_H
#pragma once
