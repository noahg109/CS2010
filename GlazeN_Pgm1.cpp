// Noah Glaze, CS 2010 Sec 1002 @ 9:30
// Program 1, GlazeN_Pgm1.cpp
// Due 9/12/22

// Purpose: Given a movie's name and ticket sales, find
//			gross revenue, theater profit, and the
//			distributor's cut.

// Libraries and namespace:
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	
	// Variable initializations:
	string name;		// name of movie
	double adult;		// No. of adult tickets
	double child;		// No. of child tickets
	double gross;		// Total ticket gross
	double profit;		// Theater profit
	double paid;		// Amount Paid to Distributor

	// Input:
	cout << "Enter the movie name: ";
	getline(cin, name);										//In case movie name has spaces
	cout << "How many adult tickets were sold: ";
	cin >> adult;											//No. Adult Tickets Sold
	cout << "How many children's tickets were sold: ";
	cin >> child;											//No. Child Tickets Sold

	// Processing:
	gross = 10.00 * adult + 6.00 * child;		//Calculates gross profit by multiplying ticket price by number of tickets sold
	profit = gross * 0.2;						//Calculates total profit as 20 percent of gross sales
	paid = gross * 0.8;							//Calculates distributor share as 80 percent of gross sales

	// Output:
	cout << "Gross Ticket Sales:  $" << gross << endl;
	cout << "Theater Net Profit:  $" << profit << endl;
	cout << "Amount Paid to Distributor:  $" << paid << endl;

	system("pause");

	return 0;
}
