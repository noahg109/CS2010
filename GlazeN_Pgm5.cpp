// Noah Glaze - CS 2010 - 9:30 AM
// Program 5 - GlazeN_pgm5.cpp - Due 10/30/2022
//
// Purpose: Analyze the results of a book reading contest from a file and display results accordingly.

// Preprocessor instructions:
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	//Variable Declarations:
	ifstream inFS;
	int const MAX_BOOKS = 25;
	string names[MAX_BOOKS];	// Array of names
	int books[MAX_BOOKS];		// Array of # books each person read
	int i = 0;					// Used for first loop and for keeping track of last reader index in case of less than 25 readers.
	int j = 0;					// Used for second loop, as i is being used for purpose above.
	int most = 0;				// Index value of who read the most books
	int least = 0;				// Index value of who read the least books
	int currBooks;				// Temp variable used for getting abs. value of books
	int total = 0;				// Total number of books read by all readers.


	// Opening File:
	inFS.open("pgm5.txt");
	if (!inFS.is_open()) {			// File open check
		cout << "Could not open the file. \n";
		return 1;
	}
	// Data input from file:
	while (!inFS.eof()) {
		inFS >> names[i];
		inFS >> currBooks;
		books[i] = fabs(currBooks);			// Absolute value to account for negative input
		if (books[i] > books[most]) {		// Updates reader with most books when applicable.
			most = i;
		}
		if (books[i] < books[least]) {		// Updates reader with least books when applicable.
			least = i;
		}
		total += books[i];					// Keeps running total of all books read
		++i;
	}
	// Display Name & Books of each reader:
	for (j = 0; j < i; ++j) {				// j used instead of i to keep track of last array value, see reflection below.
		cout << "Reader " << j + 1 << ", who's named " << names[j] << ", read " << books[j] << " books." << endl;
	}
	// Display most, least, and total:
	cout << "The winner is Reader " << most + 1 << ", who's named " << names[most] << ", by reading " << books[most] << " books." << endl;
	cout << "Reader " << least + 1 << ", who's named " << names[least] << ", read the least number of books: " << books[least] << endl;
	cout << "And in total, all readers read " << total << " books." << endl;

	// Close file:
	inFS.close();
	return 0;
}
// == Reflection ==
// This was *much* easier than project 4. At first I used i for both loops, but garbage data from unused array spaces would show up as well.
// variable i already held the last index number before the end of the file, so I used it to stop output when the second loop reached the
// last row in the file. This was pretty easy to impliment, as all I had to do was use a different loop variable, j.