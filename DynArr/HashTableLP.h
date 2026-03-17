#include "HashTableLP.h"
#include <iostream>
#include <climits>
using namespace std;

/**************************************************************
 * Function: HashTableLP::HashTableLP
 * Return: void (constructor)
 * Input:  int size - number of buckets to allocate
 * Output: Dynamically allocates the hash table array and
 *         initializes all slots to INT_MIN (empty sentinel).
 * author: Jay Neill
 **************************************************************/
HashTableLP::HashTableLP(int size) {
    tableSize = size;
    count = 0;
    hashTable = new int[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = INT_MIN;
    }
    cout << "HashTableLP created with " << tableSize << " buckets" << endl;
}

/**************************************************************
 * Function: HashTableLP::~HashTableLP
 * Return: void (destructor)
 * Input:  none
 * Output: Deallocates the dynamically allocated hash table array.
 * author: Jay Neill
 **************************************************************/
HashTableLP::~HashTableLP() {
    delete[] hashTable;
    cout << "HashTableLP destroyed" << endl;
}

/**************************************************************
 * Function: HashTableLP::hashFunction
 * Return: int - bucket index for the given value
 * Input:  int val - value to hash
 * Output: Returns val % tableSize as the bucket index
 * author: Jay Neill
 **************************************************************/
int HashTableLP::hashFunction(int val) {
    return val % tableSize;
}

/**************************************************************
 * Function: HashTableLP::InsertItem
 * Return: bool
 * Input:  int val - value to insert
 * Output: Inserts val using linear probing. Empty (INT_MIN) and
 *         deleted (INT_MIN+1) slots are reusable.
 *         Returns true if inserted, false if table is full.
 * author:Jay Neill
 **************************************************************/
bool HashTableLP::InsertItem(int val) {
    if (count == tableSize) {
        cout << "Table is full" << endl;
        return false;
    }
    int index = hashFunction(val);
    int start = index;
    while (hashTable[index] != INT_MIN && hashTable[index] != INT_MIN + 1) {
        index = (index + 1) % tableSize;
        if (index == start) {
            cout << "Table is full" << endl;
            return false;
        }
    }
    hashTable[index] = val;
    count++;
    return true;
}

/**************************************************************
 * Function: HashTableLP::RemoveItem
 * Return: bool
 * Input:  int val - value to remove
 * Output: Searches for val using linear probing. If found,
 *         marks slot with INT_MIN+1 (deleted sentinel) and
 *         returns true. Returns false if not found.
 * author: Jay Neill
 **************************************************************/
bool HashTableLP::RemoveItem(int val) {
    int index = hashFunction(val);
    int start = index;
    while (hashTable[index] != INT_MIN) {
        if (hashTable[index] == val) {
            hashTable[index] = INT_MIN + 1;
            count--;
            return true;
        }
        index = (index + 1) % tableSize;
        if (index == start) break;
    }
    return false;
}

/**************************************************************
 * Function: HashTableLP::SearchItem
 * Return: bool
 * Input:  int val - value to search for
 *         int &index - receives the index where val was found
 * Output: Searches using linear probing, skipping deleted slots.
 *         If found, sets index and returns true.
 *         Returns false if not found.
 * author: Jay Neill
 **************************************************************/
bool HashTableLP::SearchItem(int val, int& index) {
    index = hashFunction(val);
    int start = index;
    while (hashTable[index] != INT_MIN) {
        if (hashTable[index] == val) {
            return true;
        }
        index = (index + 1) % tableSize;
        if (index == start) break;
    }
    return false;
}

/**************************************************************
 * Function: HashTableLP::PrintHashTable
 * Return: void
 * Input:  none
 * Output: Prints each slot, its value, and its status
 *         (occupied, deleted, or empty)
 * author: Jay Neill
 **************************************************************/
void HashTableLP::PrintHashTable() {
    cout << "Index | Value | Status" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < tableSize; i++) {
        cout << "  [" << i << "]  |  ";
        if (hashTable[i] == INT_MIN)
            cout << "---  | Empty";
        else if (hashTable[i] == INT_MIN + 1)
            cout << "---  | Deleted";
        else
            cout << hashTable[i] << "    | Occupied";
        cout << endl;
    }
}

/**************************************************************
 * Function: HashTableLP::PrintLoadFactor
 * Return: void
 * Input:  none
 * Output: Prints the current load factor (stored items / total buckets)
 * author: Jay Neill
 **************************************************************/
void HashTableLP::PrintLoadFactor() {
    double loadFactor = (double)count / tableSize;
    cout << "Load Factor: " << count << "/" << tableSize
         << " = " << loadFactor << endl;
}
