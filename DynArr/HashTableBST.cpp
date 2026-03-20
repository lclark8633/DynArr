#include "HashTableBST.h"

/**************************************************************
 * Function: HashTableBST::HashTableBST
 * Return: void (constructor)
 * Input:  none
 * Output: Creates a hash table with BST buckets
 * author: Liam Clark
 **************************************************************/
HashTableBST::HashTableBST() {
    // Nothing needed here since each BST bucket
    // initializes itself through its own constructor
}

/**************************************************************
 * Function: HashTableBST::hashFunction
 * Return: int
 * Input:  int val - value to hash
 * Output: Returns the bucket index for the given value
 * author: Liam Clark
 **************************************************************/
int HashTableBST::hashFunction(int val) {
    return val % TABLE_SIZE;
}

/**************************************************************
 * Function: HashTableBST::insert
 * Return: void
 * Input:  int val - value to insert
 * Output: Inserts the value into the correct BST bucket
 * author: Liam Clark
 **************************************************************/
void HashTableBST::insert(int val) {
    int index = hashFunction(val);
    buckets[index].Insert(val);
}

/**************************************************************
 * Function: HashTableBST::search
 * Return: bool
 * Input:  int val - value to search for
 * Output: Returns true if the value is found, false otherwise
 * author: Liam Clark
 **************************************************************/
bool HashTableBST::search(int val) {
    int index = hashFunction(val);
    return buckets[index].Search(val);
}

/**************************************************************
 * Function: HashTableBST::remove
 * Return: bool
 * Input:  int val - value to remove
 * Output: Removes the value from the correct BST bucket
 *         and returns true if successful, false otherwise
 * author: Liam Clark
 **************************************************************/
bool HashTableBST::remove(int val) {
    int index = hashFunction(val);
    return buckets[index].Remove(val);
}

/**************************************************************
 * Function: HashTableBST::print
 * Return: void
 * Input:  none
 * Output: Prints all buckets and their BST contents
 * author: Liam Clark
 **************************************************************/
void HashTableBST::print() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Bucket [" << i << "] : ";
        buckets[i].Print();
        cout << endl;
    }
}