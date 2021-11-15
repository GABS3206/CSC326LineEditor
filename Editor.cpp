#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include "Editor.h"
#include "Position.h"

using namespace std;

Editor::Editor() // default editor constructor
{

}



Editor::Editor(string file) // editor constructor that reads the text file
{
	fileName = file; // sets filename to the file parameter
	myFile.open(fileName); // defines variable for each line in the text file
	//opens up the file called filename
	while (!myFile.eof()) // gets the text file and each line in the file
	{
		getline(myFile, tempText);    // for loop that continues to get each line in the file until there are no more lines
		for (int i = 0; i <= tempText.length(); i++) 
		{
			allText.insert(i + 1, tempText[i]);
		}
		allText.insert(tempText.length() + 1, '\n');
	}

	myFile.close();
}


void Editor::DisplayLines() // display lines function that displays the info from the text file
{
	for (int i = 1; i <= allText.getLength(); i++) // gets all of the data from the text file
	{
		cout << allText.getEntry(i); // prints out data from text
	}
}

void Editor::run()
{
	system("cls");
	DisplayLines();
	command = _getch(); //gets each char input 

	switch (command) // case switch statement for each char user input 
	{
	case 'x': // backspace case
		DeleteChar(); // user enters backspace, which deletes the leftmost character 
		run(); // keeps the case from breaking
		break;
	case ':':
		// moves cursor to bottom
		cout << "Command found" << endl; //
		run();
		break;
	case 'q': 
		if (Quit()) { break; } // user enters q to quit, the program will quit
		else { run(); break; } // if the user enters something else, the program will still run
		break;
	case 'w':
		Save(); // user enters w to save the proress. save function will save the contents of the file
		run(); // keeps the program running
		break;
	case'j':
		moveDown(); // move down cursor function
		break;
	case 'k':
		moveUp(); // move up cursor function
		break;
	case 'h':
		moveLeft(); // move left cursor function
		break;
	case 'l':
		moveRight(); // move right cursor function
		break;
	case 'dd':
		DeleteCurrentLine();
		break;
	default:
		WriteChar(command); // default case if the user enters anything else other than the commands above
		run();
	}
}

void Editor::WriteChar(char cmd) // function that allows user to edit the file 
{
	allText.insert(allText.getLength(), cmd); // calls the insert function and gets the length of the string 
}

void Editor::DeleteChar() // function that allows user to delete chars in the file
{
	allText.remove(allText.getLength());  // calls the delete function and gets the length of the string 
	// deletes a single char
}

void Editor::Save() // function that allows user to save their progress
{
	myFile.open(fileName, ofstream::out | ofstream::trunc); // opens the data file, and then overwrites the data file

	for (int i = 0; i < allText.getLength(); i++) // for loop that gets the length of the string 
	{
		myFile << allText.getEntry(i + 1); // passes the new text into the file 
	}

	myFile.close(); // closes file

	cout << "\nSaving..." << endl;
	Sleep(1500); // makes the program wait 1.5 seconds to save
}

bool Editor::Quit() // function that quits the program
{
	string cond;
	cout << "Do you want to quit without saving? y/n" << endl; // asks user if they want to quit
	cin >> cond;

	if (cond == "q!") // if user types q!, the program will quit without changes
	{
		return true;
	}
	else if(cond == "q") {
		cout << "Do you want to quit without saving? y/n" << endl; // asks user if they want to quit
		return false; // if the user types something else, the program will continue to run
	}
}

void Editor::DeleteCurrentLine() {

}

