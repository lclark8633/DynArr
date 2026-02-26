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
	// Check if cursor is valid
	if (r < 0 || c < 0 || r >= rows || c >= cols)
	{
		return false;
	}
	
	// Get value at cursor
	val = dynarr[r][c];
	
	// Reset value to 0
	dynarr[r][c] = 0;
	
	return true;
}

// Search Item
bool DynArr::SearchItem(int val, int &r, int &c) {
	// Check cursors
	if (this->r == -1 && this->c == -1)
	{
		return false;
	}
	
	// Search array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (dynarr[i][j] == v)
			{
				// Found
				r = i;
				c = j;
	
				// Move cursor to position
				this->r = i;
				this->c = j;
	
				return true;
			}
		}
	}
	
	// Not Found
	this->r = 0;
	this->c = 0;
	
	return false;
}

// Print Col Major
void DynArr::PrintColMajor() {
	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << dynarr[i][j] << " ";
		}
		cout << endl;
	}
}

// Print Rows Major 
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
