#ifndef H_LLHASH
#define H_LLHASH
#include "LinkedList.h"

const int TABLE_SIZE = 10;

class HashTableLL {
private:
    LinkedList<int> hashTable[TABLE_SIZE];
    int hashFunction(int val);
public:
    HashTableLL();
    ~HashTableLL();

    void insert(int val);
    void remove(int val);
    bool HashSearch(int val);

    void PrintHashTable();
};

#endif
