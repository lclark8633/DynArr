#ifndef H_HASHTABLELP
#define H_HASHTABLELP
 
#include <iostream>
#include <climits>
using namespace std;
 
/**************************************************************
 * Class: HashTableLP
 * A hash table using linear probing for collision resolution.
 * Uses INT_MIN as the empty sentinel and INT_MIN+1 as the
 * deleted sentinel.
 **************************************************************/
class HashTableLP {
private:
    int* hashTable;
    int tableSize;
    int count;
 
    int hashFunction(int val);
 
public:
    HashTableLP(int size);
    ~HashTableLP();
 
    bool InsertItem(int val);
    bool RemoveItem(int val);
    bool SearchItem(int val, int& index);
    void PrintHashTable();
    void PrintLoadFactor();
};
 
#endif
 
