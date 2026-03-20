#ifndef H_HASHTABLE
#define H_HASHTABLE

const int TABLE_SIZE = 10;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class HashTable {
private:
    Node* hashTable[TABLE_SIZE];
    int hashFunction(int val);
public:
    HashTable();
    ~HashTable();

    void insert(int val);
    bool HashSearch(int val);

    void PrintHashTable();
};

#endif
