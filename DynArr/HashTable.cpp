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
 * Function: ~HashTable()
 * Return: void (destructor)
 * Input:  none
 * Output: Destroys table
 * author: John Grevins
 **************************************************************/
HashTable::~HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* curr = hashTable[i];
        while (curr != nullptr) // check if destroyed
        {
            Node* temp = curr;
            curr = curr->next; // next value
            
            delete temp; // delete previous value
        }
    }

    cout << "Hash table destroyed" << endl;
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
 * Function: insert
 * Return: none
 * Input:  int val - value to insert
 * Output: Inserts val into beginning of bucket
 * author: John Grevins
 **************************************************************/
void HashTable::insert(int val)
{
    int index = hashFunction(val);

    Node* newNode = new Node(val);

    // Insert at beginning
    newNode->next = hashTable[index]; // preserve next node
    hashTable[index] = newNode; // insert value

    cout << "Inserted " << val << " into bucket " << index << endl;
}

/**************************************************************
 * Function: remove
 * Return: bool
 * Input:  int val - value to remove
 * Output: removes value
 * author: Liam Clark
 **************************************************************/
bool HashTable::remove(int val)
{
    int index = hashFunction(val);
    Node* curr = hashTable[index];
    Node* prev = nullptr;

    while (curr != nullptr)
    {
        if (curr->data == val)
        {
            if (prev == nullptr)
                hashTable[index] = curr->next;
            else
                prev->next = curr->next;

            delete curr;
            return true;
        }

        prev = curr;
        curr = curr->next;
    }

    return false;
}

/**************************************************************
 * Function: HashSearch
 * Return: bool
 * Input:  int val - value to search for
 * Output: Returns true if value was found and false if not
 * author: John Grevins
 **************************************************************/
bool HashTable::HashSearch(int val)
{
    int index = hashFunction(val);
    Node* curr = hashTable[index];

    while (curr != nullptr) // while val is not found
    {
        if (curr->data == val) // check for value
        {
            return true;
        }
        curr = curr->next; // next value
    }
    return false;
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
