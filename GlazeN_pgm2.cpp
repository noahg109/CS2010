// Noah Glaze - CS 2010 - 9:30 AM
// Program 2 - GlazeN_pgm2.cpp - Due 9/25/2022
//
// Purpose: Calculate points from credit card purchase categories,
// then calculate what rewards the user can earn from those points.

//Preprocessor instruction
#include <iostream>
#include <string>
using namespace std;

int main() {

	// Variable Initializations:
	int pts;			// total points
	int ent;			// $ from entertainment purchases
	int food;			// $ from food purchases
	int other;			// $ from other purchases
	int pizzas = 0;				// # of pizzas available
	int movies = 0;				// # of movies available
	int itunes = 0;				// # of itunes available
	char choice;		// first choice for rewards

	// Inputs:
	cout << "Adventure Campus Rewards Program" << endl;
	cout << "Enter dollar amount of your Entertainment purchases: $";
	cin >> ent;																	// Entertainment $ input
	cout << "Enter dollar amount of your Food purchases:          $";
	cin >> food;																// Food $ input
	cout << "Enter dollar amount of any other purchases:          $";
	cin >> other;																// Other $ input

	// Procesing total points:
	pts = ((5 * ent) + (2 * food) + other);

	// Output total points & user choice
	cout << "Total number of points earned:                       " << pts << endl;		//outputs total pts
	cout << "Enter your first choice for rewards- (M)ovies, (P)izzas or (I)tunes:  ";
	cin >> choice;																		//Inputs user choice

	// Processing rewards:
	if (choice == 'P') {								// calculates # of items, sets points to deduct items, and sets choice
		pizzas = pts / 300;								// to next remaining option, if applicable.
		pts %= 300;
		choice = 'M';
	}
	if (choice == 'M') {								// Same as Above
		movies = pts / 150;
		pts %= 150;
		choice = 'I';
	}
	if (choice == 'I') {								// Same as above
		itunes = pts / 60;
		pts %= 60;
	}
	else {
		cout << "***An error occured. Please check your input, restart the program, and try again***" << endl;
		//Catch-all if user enters invalid char.
	}

	//output rewards
	cout << "You have earned the following rewards for your credit card purchases!" << endl;
	cout << "  " << pizzas << "	Pizzas (300 points each)" << endl;
	cout << "  " << movies << "	Movie Rentals (150 points each)" << endl;
	cout << "  " << itunes << "	iTunes downloads (60 points each)" << endl;
	cout << "  " << pts << "	points leftover" << endl;

	system("pause");
	return 0;
}