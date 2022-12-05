// Noah Glaze - CS 2010 - 9:30 AM
// Program 4 - GlazeN_pgm4.cpp - Due 10/19/2022
//
// Purpose: recieve numbers from a file and graph their values on a chart.

// Preprocessor instructions:
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {
	// Variable Declarations
	ifstream inFS;
	int num1;			//Current number from file
	int i = 1;			// line number for graphs
	int big1 = -9999;	// biggest value
	int big2 = -9999;
	int big3 = -9999;
	int small1 = 9999;	// smallest value
	int small2 = 9999;
	int small3 = 9999;
	int invalid = 0;	// # of invalid numbers
	int fselect;		// # of file user selected
	HANDLE hConsole;
	const int WHITE = 7;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//file seclect menu
	do {
		cout << "Select file to process: \n";
		cout << "1. mixed.txt \n";
		cout << "2. valid.txt \n";
		cout << "3. three.txt \n";
		cout << "4. missing.txt \n";
		cout << "Choice: ";
		cin >> fselect;
		if (fselect > 4 || fselect < 1) {
			system("cls");
		}
	} while (fselect > 4 || fselect < 1);

	//open files
	switch (fselect) {
	case 1:
		inFS.open("mixed.txt");
		break;
	case 2:
		inFS.open("valid.txt");
		break;
	case 3:
		inFS.open("three.txt");
		break;
	default:
		cout << "ERROR: Data file not found.";
		return 1;
	}
	if (!inFS.is_open()) {			// File open check
		cout << "Could not open the file. \n";
		return 1;
	}
	// Display values:
	cout << "Bar graph for data contained in file:\n";
	inFS >> num1;
	while (num1 != 9999) {
		// Calculate largest/smallest before formatting for graph
		if (num1 > big1) {
			big3 = big2; 
			big2 = big1; 
			big1 = num1; 
		}
		else if (num1 > big2) { 
			big3 = big2; 
			big2 = num1; 
		}
		else if (num1 > big3) { 
			big3 = num1; 
		}
		if (num1 < small1) { 
			small3 = small2; 
			small2 = small1; 
			small1 = num1; 
		}
		else if (num1 < small2) { 
			small3 = small2; 
			small2 = num1; 
		}
		else if (num1 < small3) { 
			small3 = num1; 
		}
		// Format text for large/negative values
		SetConsoleTextAttribute(hConsole, WHITE); // resets to white
		if (num1 < 0) {
			invalid++; 
			SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
		}
		if (num1 > 110) { 
			num1 = 110; 
			invalid++; 
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
		}
		// Output values onto chart:
		cout << i << "	| ";
		for (int j = 0; j < (fabs(num1)); ++j) { cout << "X"; }
		cout << "\n";
		++i;
		inFS >> num1; // Grab value for next cycle of loop
	}
	// Output chart X-axis
	cout << setfill('-') << setw(120) << "\n";
	cout << "	  1        10        20        30        40        50        60        70        80        90        100\n";
	// Output largest/smallest/invalid value numbers
	cout << "\nSMALLEST\n--------\nThe smallest value: " << small1;
	cout << "\n2nd smallest value: " << small2;
	cout << "\n3rd smallest value: " << small3 << "\n";
	cout << "\nLARGEST\n-------\nThe largest value: " << big1;
	cout << "\n2nd largest value: " << big2;
	cout << "\n3rd largest value: " << big3 << "\n";
	cout << "\nINVALID\n-------\nThere are " << invalid << " invalid values in the data.\n";
	inFS.close();	// Close file
	return 0;
	
	// Reflection: other than getting used to not using endl, the actual coding for this one was not that bad.
	// the most challenging part for me was an error saying it could not find the file when debugging. I have no idea
	// how it happened or how it went away.
}