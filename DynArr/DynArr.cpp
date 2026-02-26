#include "DynArr.h"
#include <iostream>
using namespace std;

// Constructor
DynArr::DynArr(int rows, int cols) {
	// Initializing variables
	this->rows = rows;
	this->cols = cols;
	r = -1;
	c = -1;

	// Allocating rows
	ptr = new int* [rows];

	// Allocate columns for each row and initialize to 0
	for (int i = 0; i < rows; i++) {
		ptr[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			ptr[i][j] = 0;
		}
	}
	cout << "DynArr created: " << rows << "x" << cols << " 2D array" << endl;
}

// Destructor 
DynArr::~DynArr(){
	if (ptr != nullptr) {
		for (int i = 0; i < rows; i++) {
			delete[] ptr[i];
		}
		delete[] ptr;
	}
	cout << "Array destroyed" << endl;
}

// Insert Item 
bool DynArr::InsertItem(int val, int r, int c) {
	if (r < 0 || r >= rows || c < 0 || c >= cols) {
		cout << "Error: Position [" << r << "," << c << "] out of bounds" << endl;
		return false;
	}

	// Insert value and set cursor
	ptr[r][c] = val;
	this->r = r;
	this->c = c;
	return true;
}

// Remove Item
bool DynArr::RemoveItem(int &val) {
	cout << "Remove value: " << val << " at [" << r << "," << c << "]" << endl;
	//ptr[r][c] = 0;
	return false;
}

// Search Item
bool DynArr::SearchItem(int val, int &r, int &c) {
	cout << "Searching for value: " << val << endl;
	return false;
}

// Print Col Major
void DynArr::PrintColMajor() {
	cout << "Printing Col Major" << endl;
}

// Print Ros Major 
void DynArr::PrintRowMajor() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
}

// Copy Constructor 
DynArr::DynArr(const DynArr& other){
	cout << "Copy constrcutor" << endl;
	ptr = nullptr;
	rows = 0;
	cols = 0;
	r = -1;
	c = -1;
}

DynArr& DynArr::operator=(const DynArr& other){
	cout << "Assignmengt operator" << endl;
	return *this;
}