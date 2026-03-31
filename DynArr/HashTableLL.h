#ifndef H_LLHASH
#define H_LLHASH

#include "Linkedlist.h"

const int LL_TABLE_SIZE = 10;

class HashTableLL {
private:
    LinkedList<int> hashTable[LL_TABLE_SIZE];
    int hashFunction(int val);
public:
    HashTableLL();
    ~HashTableLL();
    void insert(int val);
    bool remove(int val);
    bool HashSearch(int val);
    void PrintHashTable();
};

#endif
