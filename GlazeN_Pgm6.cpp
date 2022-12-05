// Noah Glaze - Program 6 - 11/14/22 - GlazeN_Pgm6.cpp
// Purpose - Play Chutes and Ladders with player name input and results.

// Preprocessor Instruction
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes:
void printHeader();
int rollDice();
int move(int currSpace, int die);
void printMove(string name, int currSpace, int round, int die, int newSpace);
bool checkWin(int move1, int move2);
void checkChutes(int& newSpace);
void checkLadders(int& newSpace);

// Main Program
int main() {
	srand(time(NULL));
	// Main Variables
	string name1;
	string name2;
	int currSpace1 = 0;
	int currSpace2 = 0;
	int round = 1;
	bool win;
	
	// Get Names:
	cout << "Name for Player 1: ";
	cin >> name1;
	cout << "Name for Player 2: ";
	cin >> name2;

	// Play Game!
	printHeader();

	win = 0;
	while (win == 0) { // Calls each function for each player
		int die1 = rollDice();
		int move1 = move(currSpace1, die1);
		printMove(name1, currSpace1, round, die1, move1);
		currSpace1 = move1; // sets current pos to new pos
		int die2 = rollDice();
		int move2 = move(currSpace2, die2);
		printMove(name2, currSpace2, round, die2, move1);
		currSpace2 = move2;
		cout << "-----------------------------------------------------------------" << endl;
		win = checkWin(move1, move2);
		round++;
	}
	if (currSpace1 > 99) {
		cout << "The winner is " << name1 << "!" << endl;
	}
	else {
		cout << "The winner is " << name2 << "!" << endl;
	}
	return 0;
}

void printHeader() { // This one is pretty self explanatory
	cout << "Player    Move Number    Curr Position    Die    New Postion" << endl;
	cout << "****************************************************************" << endl;
	return;
}
int rollDice() { // Returns random number between 1 and 8 //
	return (rand() % 8 + 1);
}
int move(int currSpace, int die) {  // Takes players current space and gives them new one //
	int newSpace;
	newSpace = currSpace + die;
	checkChutes(newSpace);
	checkLadders(newSpace);
	return newSpace;
}
void printMove(string name, int currSpace, int round, int die, int newSpace) { // Outputs move data
	cout << name << "      " << round << "              " << currSpace << "               " << die << "      " << newSpace << endl;
	return;
}
bool checkWin(int move1, int move2) { // Checks for a winning player
	bool result = 0;
	if (move1 > 99 || move2 > 99) {
		 result = 1;
	}
	return result;
}
void checkChutes(int& newSpace) {
	if (newSpace == 8) {
		newSpace = 1;
	}
	if (newSpace == 13) {
		newSpace = 3;
	}
	if (newSpace == 24) {
		newSpace = 18;
	}
	if (newSpace == 36) {
		newSpace = 29;
	}
	if (newSpace == 51) {
		newSpace = 37;
	}
	if (newSpace == 64) {
		newSpace = 54;
	}
	if (newSpace == 86) {
		newSpace = 44;
	}
	return;
}
void checkLadders(int& newSpace) {
	if (newSpace == 7) {
		newSpace = 19;
	}
	if (newSpace == 12) {
		newSpace = 27;
	}
	if (newSpace == 28) {
		newSpace = 41;
	}
	if (newSpace == 39) {
		newSpace = 50;
	}
	if (newSpace == 53) {
		newSpace = 62;
	}
	if (newSpace == 66) {
		newSpace = 78;
	}
	if (newSpace == 75) {
		newSpace = 91;
	}
	return;
}
// Reflection: This one was fun to make, but the functions got confusing at times.
// Overall, there were few snags when making it, I am happy with my results.