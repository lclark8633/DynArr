#include "HashTableLL.h"

/**************************************************************
 * Function: HashTable
 * Return: void (constructor)
 * Input:  none
 * Output: Notify the user that the table was created
 * author: John Grevins
 **************************************************************/
HashTableLL::HashTableLL() 
{
    cout << "Hash table created with " << TABLE_SIZE << " buckets" << endl; // linked lists initialize themselves
}

/**************************************************************
 * Function: ~HashTable()
 * Return: void (destructor)
 * Input:  none
 * Output: Notifies user the table is destroyed
 * author: John Grevins
 **************************************************************/
HashTableLL::~HashTableLL()
{
    cout << "Hash table destroyed" << endl; // linked lists clean themselves by their own destructor
}

/**************************************************************
 * Function: HashTable::hashFunction
 * Return: int - the bucket index for the given value
 * Input:  int val - value to hash
 * Output: Returns val % TABLE_SIZE as the bucket index
 * author: Jay Neill
 **************************************************************/
int HashTableLL::hashFunction(int val) {
    return val % TABLE_SIZE;
}

/**************************************************************
 * Function: insert
 * Return: none
 * Input:  int val - value to insert
 * Output: Inserts val into bucket
 * author: John Grevins
 **************************************************************/
void HashTableLL::insert(int val)
{
    int index = hashFunction(val);

    hashTable[index].Insert(val);

    cout << "Inserted " << val << " into bucket " << index << endl;
}

/**************************************************************
 * Function: remove
 * Return: none
 * Input:  int val - value to remove
 * Output: Removes value from table
 * author: John Grevins
 **************************************************************/
void HashTableLL::remove(int val)
{
    int index = hashFunction(val);

    hashTable[index].Remove(val);
}

/**************************************************************
 * Function: HashSearch
 * Return: bool
 * Input:  int val - value to search for
 * Output: Returns true if value was found and false if not
 * author: John Grevins
 **************************************************************/
bool HashTableLL::HashSearch(int val)
{
    int index = hashFunction(val);

    return hashTable[index].Search(val);
}

/**************************************************************
 * Function: PrintHashTable
 * Return: void
 * Input:  none
 * Output: Prints each bucket and its chained values
 * author: John Grevins
 **************************************************************/
void HashTableLL::PrintHashTable() 
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
          cout << "Bucket [" << i << "]: ";

          if (hashTable[i].IsEmpty())
          {
              cout << "empty";
          }
          else
          {
              hashTable[i].Print();
          }
      
          cout << endl;
    }
}
