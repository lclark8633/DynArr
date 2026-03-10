#include "HashTable.h"
#include <iostream>
using namespace std;

/**************************************************************
 * Function: HashTable::HashTable
 * Return: void (constructor)
 * Input:  none
 * Output: Initializes all buckets in the hash table to nullptr
 * author: Jay Neill
 **************************************************************/
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = nullptr;
    }
    cout << "HashTable created with " << TABLE_SIZE << " buckets" << endl;
}

/**************************************************************
 * Function: HashTable::hashFunction
 * Return: int - the bucket index for the given value
 * Input:  int val - value to hash
 * Output: Returns val % TABLE_SIZE as the bucket index
 * author: Jay Neill
 **************************************************************/
int HashTable::hashFunction(int val) {
    return val % TABLE_SIZE;
}

/**************************************************************
 * Function: HashTable::PrintHashTable
 * Return: void
 * Input:  none
 * Output: Prints each bucket and its chained values
 * author: Jay Neill
 **************************************************************/
void HashTable::PrintHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Bucket [" << i << "]: ";
        Node* curr = hashTable[i];
        if (curr == nullptr) {
            cout << "empty";
        }
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next != nullptr)
                cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
}
