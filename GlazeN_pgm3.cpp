// Noah Glaze - CS 2010 - 9:30 AM
// Program 3 - GlazeN_pgm3.cpp - Due 10/09/2022
//
// Purpose: play an automated game of rock, paper, scissors.

//Preprocessor instruction
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	// Variable and Constant Declarations
	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;
	string name1;	// name of player 1
	string name2;	// name of player 2
	int rounds;		// number of rounds
	int p1Value;	// player 1 rock paper or scissors
	int p2Value;	// same as above for player 2
	int p1Win = 0;		// number of round wins for player 1
	int p2Win = 0;		// number of round wins for player 2
	int play = 1;	// Used to tell if player wants to play again

	// While loop for starting over and playing again
	while (play == 1) {
		// User input and game start
		cout << "Enter Player 1's name: ";
		cin >> name1;
		cout << "Enter Player 2's name: ";
		cin >> name2;
		cout << "Enter number of round(s): ";
		cin >> rounds;
		while (rounds < 1) {		// This loop is for round number validation
			cout << "Rounds must be > 0" << endl;
			cin >> rounds;
		}
		cout << name1 << " vs " << name2 << " for " << rounds << " round(s)" << endl;
		cout << "-------------------------" << endl;

		//Game play
		for (int i = 0; i < rounds; ++i) {
			do {
				p1Value = rand() % 3;				// Generates random numbers for player 1
				p2Value = rand() % 3;				// Generates random numebrs for Player 2
				if (p1Value == p2Value) {			// Output for tie game
					cout << "Tie" << endl;
				}
				else {								// Output for non-tied games based on each player's value
					if (p1Value == 0) {
						if (p2Value == 1) {
							cout << name2 << " wins with paper" << endl;
							p2Win++;
						}
						else {
							cout << name1 << " wins with rock" << endl;
							p1Win++;
						}
					}
					if (p1Value == 1) {
						if (p2Value == 2) {
							cout << name2 << " wins with scissors" << endl;
							p2Win++;
						}
						else {
							cout << name1 << " wins with paper" << endl;
							p1Win++;
						}
					}
					if (p1Value == 2) {
						if (p2Value == 0) {
							cout << name2 << " wins with rock" << endl;
							p2Win++;
						}
						else {
							cout << name1 << " wins with scissors" << endl;
							p1Win++;
						}
					}
				}

			} while (p1Value == p2Value);
		}
		cout << "-------------------------" << endl;
		cout << name1 << " wins " << p1Win << " and " << name2 << " wins " << p2Win << endl;		//Displays total number of wins
		cout << "Would you like to play another game (1-YES 2-NO)? ";
		cin >> play;
		while ((play != 1) && (play != 2)) {			// Input Validation
			cout << "ERROR: Invalid number, input 1 or 2" << endl;
			cin >> play;
		}

	}
	
	
	return 0;
}
// REFLECTION:
// This one was tricky. Part of the reason why is because of the way we had to add loops around pre-existing loops,
// it caused a few errors for me, such as "cout is ambiguous". In the end though, I got it to work. While I think
// the code could be a little cleaner, I am happy with the way it turned out :)