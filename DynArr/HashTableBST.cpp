#include "HashTableBST.h"

/**************************************************************
 * Function: HashTableBST::HashTableBST
 * Return: void
 * Input: none
 * Output: Creates hash table with vector buckets
 * author: Liam Clark
 **************************************************************/
HashTableBST::HashTableBST() {
    cout << "HashTableBST created with " << TABLE_SIZE << " buckets" << endl;
}

/**************************************************************
 * Function: HashTableBST::hashFunction
 * Return: int
 * Input: int val
 * Output: Returns bucket index
 * author: Liam Clark
 **************************************************************/
int HashTableBST::hashFunction(int val) {
    return ((val % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
}

/**************************************************************
 * Function: HashTableBST::sortBucket
 * Return: void
 * Input: vector<int>& bucket
 * Output: Sorts bucket in ascending order
 * author: Liam Clark
 **************************************************************/
void HashTableBST::sortBucket(vector<int>& bucket) {
    for (int i = 0; i < (int)bucket.size() - 1; i++) {
        for (int j = 0; j < (int)bucket.size() - 1 - i; j++) {
            if (bucket[j] > bucket[j + 1]) {
                int temp = bucket[j];
                bucket[j] = bucket[j + 1];
                bucket[j + 1] = temp;
            }
        }
    }
}

/**************************************************************
 * Function: HashTableBST::binarySearch
 * Return: bool
 * Input: const vector<int>& bucket, int val
 * Output: Returns true if found, false otherwise
 * author: Liam Clark
 **************************************************************/
bool HashTableBST::binarySearch(const vector<int>& bucket, int val) {
    int left = 0;
    int right = (int)bucket.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (bucket[mid] == val)
            return true;
        else if (val < bucket[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return false;
}

/**************************************************************
 * Function: HashTableBST::insert
 * Return: void
 * Input: int val
 * Output: Inserts into correct bucket
 * author: Liam Clark
 **************************************************************/
void HashTableBST::insert(int val) {
    int index = hashFunction(val);
    buckets[index].push_back(val);
}

/**************************************************************
 * Function: HashTableBST::remove
 * Return: bool
 * Input: int val
 * Output: Removes value if found
 * author: Liam Clark
 **************************************************************/
bool HashTableBST::remove(int val) {
    int index = hashFunction(val);
    sortBucket(buckets[index]);

    for (int i = 0; i < (int)buckets[index].size(); i++) {
        if (buckets[index][i] == val) {
            buckets[index].erase(buckets[index].begin() + i);
            return true;
        }
    }
    return false;
}

/**************************************************************
 * Function: HashTableBST::search
 * Return: bool
 * Input: int val
 * Output: Sorts bucket, then binary searches it
 * author: Liam Clark
 **************************************************************/
bool HashTableBST::search(int val) {
    int index = hashFunction(val);
    sortBucket(buckets[index]);
    return binarySearch(buckets[index], val);
}

/**************************************************************
 * Function: HashTableBST::print
 * Return: void
 * Input: none
 * Output: Prints all buckets
 * author: Liam Clark
 **************************************************************/
void HashTableBST::print() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Bucket [" << i << "]: ";
        if (buckets[i].empty()) {
            cout << "empty";
        } else {
            for (int j = 0; j < (int)buckets[i].size(); j++) {
                cout << buckets[i][j] << " ";
            }
        }
        cout << endl;
    }
}
