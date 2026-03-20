#ifndef H_LLHASH
#define H_LLHASH

const int TABLE_SIZE = 10;

class HashTable {
private:
    LinkedList<int> hashTable[TABLE_SIZE];
    int hashFunction(int val);
public:
    HashTable();
    ~HashTable();

    void insert(int val);
    bool HashSearch(int val);

    void PrintHashTable();
};

#endif
