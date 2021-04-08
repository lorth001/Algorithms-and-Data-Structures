/*
* File name: Driver.cpp -- This file is used to test the SelfOrderedListADT and the linked-list implementations.
						   It does this by both prompting the user for input and reading from a "test.txt" file, then orders these inputs.
* CSIS 215-B01
* References: The contained in the link.h and SelfOrderedListADT.h files were provided by Liberty University for use in this assignment.  
			  The TransposeList.h, Transpose.cpp, MovetoFrontList.h, CountList.h, and Driver.cpp files were developed by me.
			  I did reference Clifford A. Shaffer's textbook "A Practical Introduction to Data Structures and Algorithm Analysis, Third Edition (C++)" during the development of this program.
*/

// Include statements
#include <iostream>
#include <string>
#include <fstream>
#include "CountList.h"
#include "MovetoFrontList.h"
#include "TransposeList.h"


int main() {

	// General message with student info and meaning of the program's output
	std::cout << "Luke Orth -- CSIS 215 Programming Assignment 4 -- Self-Organizing Lists" << std::endl << std::endl;

	bool flag; // Flag indicating if value was found

	// ***************************
	//       Count Heuristic 
	// ***************************
	std::cout << " ********** Count Heuristic ********** " << std::endl << std::endl;

	std::cout << " ~ Character Test ~ " << std::endl << std::endl;

	// Creates a Count List object
	CountList<char> CountChar;

	// Add initial chars (per instructions)
	CountChar.add('A');
	CountChar.add('B');
	CountChar.add('C');
	CountChar.add('D');
	CountChar.add('E');
	CountChar.add('F');
	CountChar.add('G');
	CountChar.add('H');

	// Prompt the user to enter chars and use the find function to add them to the list
	char c;
	std::cout << "Please Enter: F D F G E G F A D F G E H I" << std::endl;
	for (int i = 0; i < 14; i++) {
		std::cin >> c;
		flag = CountChar.find(c);
	}

	// Output the results
	std::cout << "Count Heuristic: Size of list: " << CountChar.size() << std::endl;
	std::cout << "Number of compares: " << CountChar.getCompares() << std::endl;
	std::cout << "The final order of the list: " << std::endl;
	CountChar.printlist();

	// Clear the list and remove values
	CountChar.removeall();

	std::cout << std::endl << " ~ String Test ~" << std::endl << std::endl;

	// Create an object for string test
	CountList<std::string> CountString;

	// Open the test file
	std::ifstream countFile;
	countFile.open("test.txt", std::ios::in);

	// Get values from the file and the find function to add them to the list
	std::string countWord;
	while (countFile >> countWord) {
		CountString.find(countWord);
	}

	// Output the results
	std::cout << "Count Heuristic: Size of list: " << CountString.size() << std::endl;
	std::cout << "Number of compares: " << CountString.getCompares() << std::endl;
	std::cout << "The first ten elements of the list are: " << std::endl;
	CountString.printlist(10);

	countFile.close();

	std::cout << std::endl << std::endl;

	// ***************************
	//   Move to Front Heuristic 
	// ***************************
	std::cout << " ********** Move to Front Heuristic ********** " << std::endl << std::endl;

	std::cout << " ~ Character Test ~ " << std::endl << std::endl;

	// Create a new List object
	MovetoFrontList<char> MovetoFrontChar;

	// Add chars to the list (per instructions)
	MovetoFrontChar.add('A');
	MovetoFrontChar.add('B');
	MovetoFrontChar.add('C');
	MovetoFrontChar.add('D');
	MovetoFrontChar.add('E');
	MovetoFrontChar.add('F');
	MovetoFrontChar.add('G');
	MovetoFrontChar.add('H');

	// Prompt the user to enter chars and use the find function to add them to the list
	std::cout << "Please Enter: F D F G E G F A D F G E H I" << std::endl;
	for (int i = 0; i < 14; i++) {
		std::cin >> c;
		flag = MovetoFrontChar.find(c);
	}

	// Output the results
	std::cout << "Move to Front Heuristic: Size of list: " << MovetoFrontChar.size() << std::endl;
	std::cout << "Number of compares: " << MovetoFrontChar.getCompares() << std::endl;
	std::cout << "The final order of the list is: " << std::endl;
	MovetoFrontChar.printlist();

	// Clear the list and remove values
	MovetoFrontChar.removeall();

	std::cout << std::endl << " ~ String Test ~" << std::endl << std::endl;

	// Create a new object for strings
	MovetoFrontList<std::string> MovetoFrontString;

	std::ifstream moveToFrontFile; // File to read in
	std::string moveToFrontWord; // Word to read in

	// Open the file
	moveToFrontFile.open("test.txt", std::ios::in);

	// Get values from the file and the find function to add them to the list
	while (moveToFrontFile >> moveToFrontWord) {
		MovetoFrontString.find(moveToFrontWord);
	}

	// Output the results
	std::cout << "Move to Front Heuristic: Size of list: " << MovetoFrontString.size() << std::endl;
	std::cout << "Number of compares: " << MovetoFrontString.getCompares() << std::endl;
	std::cout << "The first ten elements of the list are: " << std::endl;
	MovetoFrontString.printlist(10);

	moveToFrontFile.close();

	std::cout << std::endl << std::endl;

	// ***************************
	//     Transpose Heuristic 
	// ***************************
	std::cout << " ********** Transpose Heuristic ********** " << std::endl << std::endl;

	std::cout << " ~ Character Test ~ " << std::endl << std::endl;

	// Create a new List object
	TransposeList<char> TransposeChar;

	// Add chars to the list (per instructions)
	TransposeChar.add('A');
	TransposeChar.add('B');
	TransposeChar.add('C');
	TransposeChar.add('D');
	TransposeChar.add('E');
	TransposeChar.add('F');
	TransposeChar.add('G');
	TransposeChar.add('H');

	// Prompt the user to enter chars and use the find function to add them to the list
	std::cout << "Please Enter: F D F G E G F A D F G E H I" << std::endl;
	for (int i = 0; i < 14; i++) {
		std::cin >> c;
		flag = TransposeChar.find(c);
	}

	// Output the results
	std::cout << "Transpose Heuristic: Size of list: " << TransposeChar.size() << std::endl;
	std::cout << "Number of compares: " << TransposeChar.getCompares() << std::endl;
	std::cout << "The final order of the list is: " << std::endl;
	TransposeChar.printlist();

	// Clear the list and remove values
	TransposeChar.removeall();

	std::cout << std::endl << " ~ String Test ~" << std::endl << std::endl;

	// Create a new object for strings
	TransposeList<std::string> TransposeString;

	std::ifstream transposeFile; // File to read in
	std::string transposeWord; // Word to read in

	// Open the "test" file
	transposeFile.open("test.txt", std::ios::in);

	// Get values from the file and the find function to add them to the list
	while (transposeFile >> transposeWord) {
		TransposeString.find(transposeWord);
	}

	// Output the results
	std::cout << "Transpose Heuristic: Size of list: " << TransposeString.size() << std::endl;
	std::cout << "Number of compares: " << TransposeString.getCompares() << std::endl;
	std::cout << "The first ten elements of the list are: " << std::endl;
	TransposeString.printlist(10);

	transposeFile.close();

	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}