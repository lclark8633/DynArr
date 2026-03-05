#include "DynArr.h"
#include <iostream>
using namespace std;

/**************************************************************
 * Function: DynArr::DynArr
 * Return: void (constructor)
 * Input:  int rows - number of rows to allocate
 *         int cols - number of columns to allocate
 * Output: Allocates a rows x cols 2D dynamic array (ptr) and
 *         initializes all elements to 0; sets cursor (r,c) to (-1,-1).
 * author: Liam Clark
 **************************************************************/
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

/**************************************************************
 * Function: DynArr::~DynArr
 * Return: void (destructor)
 * Input:  none
 * Output: Deallocates all memory used by the dynamic 2D array (ptr).
 * author: Liam Clark
 **************************************************************/
DynArr::~DynArr(){
	if (ptr != nullptr) {
		for (int i = 0; i < rows; i++) {
			delete[] ptr[i];
		}
		delete[] ptr;
	}
	cout << "Array destroyed" << endl;
}

/**************************************************************
 * Function: DynArr::InsertItem
 * Return: bool
 * Input:  int val - value to insert
 *         int r - target row index
 *         int c - target column index
 * Output: If (r,c) is in bounds, stores val at ptr[r][c] and moves
 *         the cursor to (r,c), then returns true. If out of bounds,
 *         prints an error message and returns false.
 * author: Liam Clark
 **************************************************************/
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

/**************************************************************
 * Function: DynArr::RemoveItem
 * Return: bool
 * Input:  int &val - receives the value removed from the current cursor
 * Output: If the cursor (r,c) is valid, copies ptr[r][c] into val,
 *         sets ptr[r][c] to 0, and returns true. If cursor is invalid,
 *         returns false and does not modify the array.
 * author: John Grevins 
 **************************************************************/
bool DynArr::RemoveItem(int &val) {
	// Check if cursor is valid
	if (r < 0 || c < 0 || r >= rows || c >= cols)
	{
		return false;
	}
	
	// Get value at cursor
	val = ptr[r][c];
	
	// Reset value to 0
	ptr[r][c] = 0;
	
	return true;
}

/**************************************************************
 * Function: DynArr::SearchItem
 * Return: bool
 * Input:  int val - value to search for
 *         int &r - receives the row index where val is found
 *         int &c - receives the column index where val is found
 * Output: Searches the entire 2D array. If found, sets r and c to the
 *         position, moves the cursor to that position, and returns true.
 *         If not found, sets the cursor to (0,0) and returns false.
 * author: John Grevins 
 **************************************************************/
bool DynArr::SearchItem(int val, int &r, int &c) {
	
	// Search array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (ptr[i][j] == val)
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

/**************************************************************
 * Function: DynArr::PrintColMajor
 * Return: void
 * Input:  none
 * Output: Prints the array in column-major order (by columns first),
 *         outputting each column on its own line.
 * author: John Grevins
 **************************************************************/
void DynArr::PrintColMajor() {
	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
}

/**************************************************************
 * Function: DynArr::PrintRowMajor
 * Return: void
 * Input:  none
 * Output: Prints the array in row-major order (by rows first),
 *         outputting each row on its own line.
 * author: Liam Clark
 **************************************************************/
void DynArr::PrintRowMajor() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
}

/**************************************************************
 * Function: DynArr::DynArr (copy constructor)
 * Return: void (constructor)
 * Input:  const DynArr &other - source DynArr to copy from
 * Output: Constructs a DynArr as a copy of other.
 * author: Liam Clark
 **************************************************************/
DynArr::DynArr(const DynArr& other){
	cout << "Copy constrcutor" << endl;
	ptr = nullptr;
	rows = 0;
	cols = 0;
	r = -1;
	c = -1;
}

/**************************************************************
 * Function: DynArr::operator=
 * Return: DynArr&  (reference to the current object)
 * Input:  const DynArr &other - source DynArr to assign from
 * Output: Assigns the contents of other into *this and returns *this.
 * author: Liam Clark
 **************************************************************/
DynArr& DynArr::operator=(const DynArr& other){
	cout << "Assignmengt operator" << endl;
	return *this;
}
