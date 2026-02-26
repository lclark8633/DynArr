/*
* Name: Liam Clark
* Class: CS-355
* Date: 2/23/26
* Assignment: Pass 1
*/
#include <iostream>
#include "DynArr.h"
using namespace std;

const string STARS = "**********************************************";

int main() {
	DynArr arr(3, 3);

	char command;
	int val, r, c;
	bool result;

	cout << "Enter a command (+, -, ?, R, C, or Q to quit): ";
	
	do {
		cin >> command;

		// Insert command
		if (command == '+') {
			cin >> val;
			cin >> r;
			cin >> c;
			cout << "Inserting " << val << " at [" << r << "," << c << "]..." << endl;

			result = arr.InsertItem(val, r, c);
			if (result) {
				cout << "Done" << endl;
			}
			else {
				cout << "Not Done" << endl;
			}
		}
		// Remove command
		else if (command == '-') {
			cout << "Removing value at cursor..." << endl;
			result = arr.RemoveItem(val);
			if (result) {
				cout << "Removed: " << val << endl;
			}
			else {
				cout << "Not Done" << endl;
			}
		}
		// Search command
		else if (command == '?') {
			cin >> val;
			cout << "Searching for " << val << "..." << endl;
			result = arr.SearchItem(val, r, c);
			if (result) {
				cout << "Found at [" << r << "," << c << "]" << endl;
			}
			else {
				cout << "Not found. Cursors set to [0,0]" << endl;
			}
		}
		// Print Row Major
		else if (command == 'R' || command == 'r') {
			cout << "Row Major Output: " << endl;
			arr.PrintRowMajor();
		}
		// Print Col Major
		else if (command == 'C' || command == 'c') {
			cout << "Column Major Output: " << endl;
			arr.PrintColMajor();
		}
		// Quit loop
		else if (command == 'Q' || command == 'q') {
			cout << "Ending loop..." << endl;
		}
		// Handling invalid commands
		else {
			cout << "Invalid command. please choose from the following: " << endl;
			cout << "(+, -, ?, R, C, or Q to quit)";
		}
		// Spacer 
		cout << STARS << endl;
	} while (command != 'Q' && command != 'q');
	return 0;
}
