#ifndef H_HASHTABLEBST
#define H_HASHTABLEBST

#include "BST.h"
#include <iostream>
using namespace std;

class HashTableBST {
private:
    static const int TABLE_SIZE = 10;
    BST<int> buckets[TABLE_SIZE];
    int hashFunction(int val);

public:
    HashTableBST();

    void insert(int val);
    bool search(int val);
    bool remove(int val);
    void print();
};

#endif