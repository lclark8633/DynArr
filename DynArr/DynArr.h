#ifndef H_DYNARR
#define H_DYNARR

class DynArr {
private:
	int** ptr;	// int **
	int rows;   // row allocation
	int cols;	// col allocation
	int r;		// row cursor
	int c;		// col cursor
public:
	// Constructor/Destructor 
	DynArr(int rows, int cols);
	~DynArr();

	// Operations 
	bool InsertItem(int val, int r, int c);
	bool RemoveItem(int &val);
	bool SearchItem(int val, int &r, int &c);
	void PrintColMajor();
	void PrintRowMajor();

	// Big Three 
	DynArr(const DynArr& other);
	DynArr& operator=(const DynArr& other);
};



#endif