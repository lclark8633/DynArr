/*
* Names: Liam Clark, Jay Neill, John Grevins
* Class: CS-355
*/
#include <iostream>
#include "DynArr.h"
#include "HashTable.h"
#include "HashTableLP.h"
#include "HashTableBST.h"
using namespace std;

const string STARS = "**********************************************";

int main() {
	char command;
	char tableChoice;
	int val, index, size;
	bool result;
	cout << STARS << endl;
	cout << "Choose hash table type:" << endl;
	cout << "1 <-- Linked List Chaining" << endl;
	cout << "2 <-- Linear Probing" << endl;
	cout << "3 <-- Binary Search Buckets" << endl;
	cout << "Enter choice: ";
	cin >> tableChoice;
	cout << STARS << endl;

	HashTable linkedTable;

	size = 10;
	HashTableLP lpTable(size);

	HashTableBST bstTable;

	cout << STARS << endl;
	cout << "Command List :" << endl;
	cout << "+ <-- Insert command (val)" << endl;
	cout << "- <-- Remove command (val)" << endl;
	cout << "? <-- Search command (val)" << endl;
	cout << "P/p <-- Print hash table" << endl;
	cout << "L/l <-- Print load factor (linear probing only)" << endl;
	cout << "Q/q <-- Quit loop" << endl;
	cout << "M/m <-- Menu command" << endl;
	cout << STARS << endl;
	
	do {
		cout << "Enter a command : ";
		cin >> command;

		// Insert command
		if (command == '+') {
			cin >> val;
			cout << "Inserting " << val << "..." << endl;
			
			if (tableChoice == '1') {
				linkedTable.insert(val);
				cout << "Done" << endl;
			}
			else if (tableChoice == '2') {
				result = lpTable.InsertItem(val);
				if (result)
					cout << "Done" << endl;
				else
					cout << "Not Done" << endl;
			}
			else if (tableChoice == '3') {
				bstTable.insert(val);
				cout << "Done" << endl;
			}
			else {
				cout << "Invalid table type selection." << endl;
			}
		}
		// Remove command
		else if (command == '-') {
			cin >> val;
			cout << "Removing " << val << "..." << endl;
			
			if (tableChoice == '1') {
				result = linkedTable.remove(val);
				if (result)
					cout << "Removed" << endl;
				else
					cout << "Not Done" << endl;
			}
			else if (tableChoice == '2') {
				result = lpTable.RemoveItem(val);
				if (result)
					cout << "Removed" << endl;
				else
					cout << "Not Done" << endl;
			}
			else if (tableChoice == '3') {
				result = bstTable.remove(val);
				if (result)
					cout << "Removed" << endl;
				else
					cout << "Not Done" << endl;
			}
			else {
				cout << "Invalid table type selection." << endl;
			}
		}
		// Search command
		else if (command == '?') {
			cin >> val;
			cout << "Searching for " << val << "..." << endl;
			
			if (tableChoice == '1') {
				result = linkedTable.HashSearch(val);
				if (result)
					cout << "Found" << endl;
				else
					cout << "Not found" << endl;
			}
			else if (tableChoice == '2') {
				result = lpTable.SearchItem(val, index);
				if (result)
					cout << "Found at index [" << index << "]" << endl;
				else
					cout << "Not found" << endl;
			}
			else if (tableChoice == '3') {
				result = bstTable.search(val);
				if (result)
					cout << "Found" << endl;
				else
					cout << "Not found" << endl;
			}
			else {
				cout << "Invalid table type selection." << endl;
			}
		}
		// Print Row Major
		else if (command == 'P' || command == 'p') {
			cout << "Hash Table Output:" << endl;
			
			if (tableChoice == '1') {
				linkedTable.PrintHashTable();
			}
			else if (tableChoice == '2') {
				lpTable.PrintHashTable();
			}
			else if (tableChoice == '3') {
				bstTable.print();
			}
			else {
				cout << "Invalid table type selection." << endl;
			}
		}
		// Print Col Major
		else if (command == 'L' || command == 'l') {
			if (tableChoice == '2') {
				lpTable.PrintLoadFactor();
			}
			else {
				cout << "Load factor display only applies to the linear probing table." << endl;
			}
		}
		// Print Menu
		else if (command == 'M' || command == 'm') {
			cout << "Command List :" << endl;
			cout << "+ <-- Insert command (val, x pos, y pos)" << endl;
			cout << "- <-- Remove command (removes value at cursor)" << endl;
			cout << "? <-- Search command (searchVal)" << endl;
			cout << "P/p <-- Print Hash Table" << endl;
			cout << "L/l <-- Print load factor (linear probing)" << endl;
			cout << "Q/q <-- Quit loop" << endl;
			cout << "M/m <-- Menu command" << endl;
		}
		// Quit loop
		else if (command == 'Q' || command == 'q') {
			cout << "Ending loop..." << endl;
		}
		// Handling invalid commands
		else {
			cout << "Invalid command. please choose from the following: " << endl;
			cout << "(+, -, ?, P, L, M, or Q to quit)";
		}
		// Spacer 
		cout << STARS << endl;
	} while (command != 'Q' && command != 'q');
	return 0;
}
