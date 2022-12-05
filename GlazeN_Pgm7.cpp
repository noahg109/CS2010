// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// Program Description: 2 - player tic-tac-toe game that draws a game board, accepts player input, and validates game outcomes.	//
// Program Author: Noah Glaze																									//
// Class and Term: CS 2010, Fall 2022																							//
// Date Completed: 12/4/2022		
// Program Reflection:
//	This is by far the hardest project I've done. There was a lot of small mistakes I made that caused big errors,
//	including flipping the rows and columns at one point. Yet I persevered and fixed them all, and it ended up working!
//	I'm pretty proud of it, to be honest.																							//
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// Preporcesor Instruction
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// Global Constants for grid rows and cols:
const int ROWS = 6;
const int COLS = 13;

// Function Prototypes. Function documentation with each function at bottom of main.
void readInitialGrid(char[][COLS], ifstream& );
void initializeGrid(char[][COLS]);
void displayGrid(char[][COLS]);
bool isWin(char[][COLS], int );

// Main Program:
int main() {
	
	// Main Program variables:
	ifstream gameFile;					// Used for file operations
	int move;							// Keeps track of move number and calls game tie if all spaces filled.
	int i = 0;							// Used with switch to detemine array position player is placing their icon at
	int j = 0;							// Used with switch to detemine array position player is placing their icon at
	bool turn;							// True if X's turn, false if O's turn.
	bool playGame;						// Used to determine if players want to play again
	bool win;							// True if isWin detects a winner, false otherwise
	char gameArray[ROWS][COLS];			// Array for game board, passed to functions
	char playerChar;					// Determined by turn, used to output X or O when asking for input and on game board
	char rowSelection;					// Row active player wants to place their icon in
	char colSelection;					// Column active player wants to place their icon in
	char choice;						// Used to accept input if the player wants to play again.

	
	// Open file & call readInitialGrid to write file to array.
	gameFile.open("pgm7-input.txt");
	if (gameFile.is_open()) {
		readInitialGrid(gameArray, gameFile);
	}
	else { // File open validation, hopefully we never have to see this :)
		cout << "ERROR: Unable to open file = pgm7-input.txt = . Make sure file exists and try again.";
		return 1;
	}
	playGame = true;

	// Initialize (reset) game and board:
	while (playGame == 1) {
		initializeGrid(gameArray);				// Resets any X's or O's on grid to spaces
		turn = true;							// X always goes first
		move = 1;								// Reset move counter to first move
		win = false;							// Resets win state before game starts
		displayGrid(gameArray);					// Shows game grid to player
		while (win == false && move < 10) {		// Makes sure no winner or tie has been determined
			if (turn == true) {					// Used to say X or O in output text, and later on game board
				playerChar = 'X';
			}
			else {
				playerChar = 'O';
			}
			// Ask player for their move:
			cout << "Your move, " << playerChar << "! Enter column [A, B, or C], followed by row [1, 2, or 3]" << endl;
			cout << "=> ";
			cin >> colSelection;
			cin >> rowSelection;
			colSelection = toupper(colSelection);		// If player enters a, b, or c instead of their capitial verions, this corrects it without needing input again
			if ((colSelection != 'A' && colSelection != 'B' && colSelection != 'C') ||		//Input error detection
				(rowSelection != '1' && rowSelection != '2' && rowSelection != '3')) {
				cout << "There was an error in your input. Enter column [A, B, or C], followed by row [1, 2, or 3]" << endl;
			}
			else {
				switch (colSelection) {			// Turns grid selections into array spaces
					case 'A':
						j = 3;
						break;
					case 'B':
						j = 7;
						break;
					case 'C':
						j = 11;
						break;
					default:
						cout << "An unexpected error has occurred (cols). Restart Program";
						return 1;		 //In case input somehow gets past input error detection. It shoud never have to be used.
				}
				switch (rowSelection) {			// Turns grid selection into array spaces
					case '1':
						i = 1;
						break;
					case '2':
						i = 3;
						break;
					case '3':
						i = 5;
						break;
					default:
						cout << "An unexpected error has occurred (rows). Restart Program";
						return 1;		 //In case input somehow gets past input error detection. It shoud never have to be used.
				}
				if (gameArray[i][j] == 'X' || gameArray[i][j] == 'O') {			// Checks to make sure space is free
					cout << "The space you chose is already taken by you or your opponent. Select another space." << endl;
				}
				else {									// Program continues if space is free.
					gameArray[i][j] = playerChar;		// Places player's icon in their chosen space.
					win = isWin(gameArray, move);		// Determines if there is a winner.
					move++;								// Adds move to count
					displayGrid(gameArray);				// Shows game grid to player
					turn = !turn;						// Switches player from X to O and vice versa
				}
			}
		}
		if (move > 9) {			// No spaces left = tie game
			cout << "Tie game! No winner." << endl;
		}
		else if (win == true) {	// Declares winner
			cout << playerChar << " Wins! Great job!" << endl;
		}
		choice = 'x';		// Just set to x to make sure player is asked for their choice
		while (choice != 'y' && choice != 'n') {		// loop for input error detection
			cout << "Would you like to play again? (y/n) ";
			cin >> choice;
			if (choice == ' y') {
				playGame = true;
			}
			else if (choice == 'n') {
				playGame = false;
			}
			else {		// Input error detection
				cout << "Error with input, type y or n." << endl;
			}
		}
	}
	return 0;
}

// ==========
// Funtion Name: readInitialGrid
// Function Description: Reads from file, converts numbers to char, then places them in the array
// Function Parameters: gameArray - array of space chars, gameFile - txt file game reads from
// Function Return Value: void
// Function Author: Noah Glaze
// ==========
void readInitialGrid(char gameArray[][COLS], ifstream& gameFile) {
	int i = 0;
	int j = 0;
	int inVal;
	for (i = 0; i < ROWS; ++i) {
		for (j = 0; j < COLS; ++j) {
			gameFile >> inVal;
			gameArray[i][j] = static_cast <char> (inVal);
		}
	}
	return;
}

// ==========
// Funtion Name: initalizeGrid
// Function Description: Clears grid for new games, setting X's or O's to spaces
// Function Parameters: gameArray - array of chars used for game
// Function Return Value: Void
// Function Author: Noah Glaze
// ==========
void initializeGrid(char gameArray[][COLS]) {
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; ++i) {
		for (j = 0; j < COLS; ++j) {
			if (gameArray[i][j] == 'X' || gameArray[i][j] == 'O') {
				gameArray[i][j] = ' ';
			}
		}
	}
	return;
}

// ==========
// Funtion Name: displayGrid
// Function Description: Draws grid on user's screen from array
// Function Parameters: gameArray - array of chars used for game
// Function Return Value: void
// Function Author: Noah Glaze
// ==========
void displayGrid(char gameArray[][COLS]) {
	int i, j;
	system("CLS");		// Clears screen
	for (i = 0; i < ROWS; ++i) {
		for (j = 0; j < COLS; ++j) {
			cout << gameArray[i][j];		// Displays chars from array
		}
		cout << endl;
	}
	return;
}

// ==========
// Funtion Name: isWin
// Function Description: Determines if a player won the game
// Function Parameters: gameArray - array of chars used for game, move - move number used to determine x or o
// Function Return Value: true if someone won, false otherwise
// Function Author: Noah Glaze
// ==========
bool isWin(char gameArray[][COLS], int move) {
	char playerChar; // functions same as playerChar in main
	if (move > 4) {
		if (move % 2 == 1) {		// Determines playerChar from move
			playerChar = 'X';
		}
		else {
			playerChar = 'O';
		}							// Below is all winning space combinations
		if (gameArray[1][3] == playerChar && gameArray[1][7] == playerChar && gameArray[1][11] == playerChar) {
			return true;
		}
		else if (gameArray[3][3] == playerChar && gameArray[3][7] == playerChar && gameArray[3][11] == playerChar) {
			return true;
		}
		else if (gameArray[5][3] == playerChar && gameArray[5][7] == playerChar && gameArray[5][11] == playerChar) {
			return true;
		}
		else if (gameArray[1][3] == playerChar && gameArray[3][3] == playerChar && gameArray[5][3] == playerChar) {
			return true;
		}
		else if (gameArray[1][7] == playerChar && gameArray[3][7] == playerChar && gameArray[5][7] == playerChar) {
			return true;
		}
		else if (gameArray[1][11] == playerChar && gameArray[3][11] == playerChar && gameArray[5][11] == playerChar) {
			return true;
		}
		else if (gameArray[1][3] == playerChar && gameArray[3][7] == playerChar && gameArray[5][11] == playerChar) {
			return true;
		}
		else if (gameArray[1][11] == playerChar && gameArray[3][7] == playerChar && gameArray[5][3] == playerChar) {
			return true;
		}
		else {		// If no combo of winning spaces
			return false;
		}
	}
	else {			// If less than 4 moves
		return false;
	}
}