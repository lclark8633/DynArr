#ifndef H_LINKEDLIST
#define H_LINKEDLIST
#include <iostream>
using namespace std;

/**************************************************************
 * Struct: Node
 * A templated node for use in a singly linked list.
 * Contains a data field and a pointer to the next node.
 **************************************************************/
template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(T val) : data(val), next(nullptr) {}
};

/**************************************************************
 * Class: LinkedList
 * A templated singly linked list supporting insert, remove,
 * search, and print operations.
 **************************************************************/
template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList();
    ~LinkedList();
    void Insert(T val);
    bool Remove(T val);
    bool Search(T val);
    void Print();
    bool IsEmpty();
};

/**************************************************************
 * Function: LinkedList::LinkedList
 * Return: void (constructor)
 * Input:  none
 * Output: Initializes an empty linked list with head = nullptr
 * author: Jay Neill
 **************************************************************/
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

/**************************************************************
 * Function: LinkedList::~LinkedList
 * Return: void (destructor)
 * Input:  none
 * Output: Deallocates all nodes in the list
 * author: Jay Neill
 **************************************************************/
template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* curr = head;
    while (curr != nullptr) {
        Node<T>* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

/**************************************************************
 * Function: LinkedList::Insert
 * Return: void
 * Input:  T val - value to insert at the front of the list
 * Output: Inserts a new node at the head of the list
 * author: Jay Neill
 **************************************************************/
template <typename T>
void LinkedList<T>::Insert(T val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
}

/**************************************************************
 * Function: LinkedList::Remove
 * Return: bool
 * Input:  T val - value to remove from the list
 * Output: Removes the first node with matching value.
 *         Returns true if removed, false if not found.
 * author: Jay Neill
 **************************************************************/
template <typename T>
bool LinkedList<T>::Remove(T val) {
    Node<T>* curr = head;
    Node<T>* prev = nullptr;
    while (curr != nullptr) {
        if (curr->data == val) {
            if (prev == nullptr)
                head = curr->next;
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
 * Function: LinkedList::Search
 * Return: bool
 * Input:  T val - value to search for
 * Output: Returns true if val is found in the list, false otherwise
 * author: Jay Neill
 **************************************************************/
template <typename T>
bool LinkedList<T>::Search(T val) {
    Node<T>* curr = head;
    while (curr != nullptr) {
        if (curr->data == val)
            return true;
        curr = curr->next;
    }
    return false;
}

/**************************************************************
 * Function: LinkedList::Print
 * Return: void
 * Input:  none
 * Output: Prints all elements in the list separated by " -> "
 * author: Jay Neill
 **************************************************************/
template <typename T>
void LinkedList<T>::Print() {
    Node<T>* curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " -> ";
        curr = curr->next;
    }
}

/**************************************************************
 * Function: LinkedList::IsEmpty
 * Return: bool
 * Input:  none
 * Output: Returns true if the list is empty, false otherwise
 * author: Jay Neill
 **************************************************************/
template <typename T>
bool LinkedList<T>::IsEmpty() {
    return head == nullptr;
}

#endif
