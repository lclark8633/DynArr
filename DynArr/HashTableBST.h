#ifndef H_HASHTABLEBST
#define H_HASHTABLEBST

#include <vector>
#include <iostream>
using namespace std;

class HashTableBST {
private:
    static const int TABLE_SIZE = 10;
    vector<int> buckets[TABLE_SIZE];

    int hashFunction(int val);
    void sortBucket(vector<int>& bucket);
    bool binarySearch(const vector<int>& bucket, int val);

public:
    HashTableBST();

    void insert(int val);
    bool remove(int val);
    bool search(int val);
    void print();
};

#endif
