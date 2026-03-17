#ifndef H_BST
#define H_BST
#include <iostream>
using namespace std;

/**************************************************************
 * Struct: BSTNode
 * A templated node for use in a binary search tree.
 * Contains a data field and pointers to left and right children.
 **************************************************************/
template <typename T>
struct BSTNode {
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

/**************************************************************
 * Class: BST
 * A templated binary search tree supporting insert, remove,
 * search, and in-order print operations.
 **************************************************************/
template <typename T>
class BST {
private:
    BSTNode<T>* root;
    void InsertHelper(BSTNode<T>*& node, T val);
    bool SearchHelper(BSTNode<T>* node, T val);
    BSTNode<T>* RemoveHelper(BSTNode<T>* node, T val, bool& removed);
    BSTNode<T>* FindMin(BSTNode<T>* node);
    void PrintHelper(BSTNode<T>* node);
    void DestroyHelper(BSTNode<T>* node);
public:
    BST();
    ~BST();
    void Insert(T val);
    bool Remove(T val);
    bool Search(T val);
    void Print();
    bool IsEmpty();
};

/**************************************************************
 * Function: BST::BST
 * Return: void (constructor)
 * Input:  none
 * Output: Initializes an empty BST with root = nullptr
 * author: Jay Neill
 **************************************************************/
template <typename T>
BST<T>::BST() {
    root = nullptr;
}

/**************************************************************
 * Function: BST::~BST
 * Return: void (destructor)
 * Input:  none
 * Output: Deallocates all nodes in the BST via DestroyHelper
 * author: Jay Neill
 **************************************************************/
template <typename T>
BST<T>::~BST() {
    DestroyHelper(root);
}

/**************************************************************
 * Function: BST::DestroyHelper
 * Return: void
 * Input:  BSTNode<T>* node - current node to destroy
 * Output: Recursively deletes all nodes in post-order
 * author: Jay Neill
 **************************************************************/
template <typename T>
void BST<T>::DestroyHelper(BSTNode<T>* node) {
    if (node == nullptr) return;
    DestroyHelper(node->left);
    DestroyHelper(node->right);
    delete node;
}

/**************************************************************
 * Function: BST::Insert
 * Return: void
 * Input:  T val - value to insert into the BST
 * Output: Delegates to InsertHelper to insert val maintaining
 *         BST ordering property
 * author: Jay Neill
 **************************************************************/
template <typename T>
void BST<T>::Insert(T val) {
    InsertHelper(root, val);
}

/**************************************************************
 * Function: BST::InsertHelper
 * Return: void
 * Input:  BSTNode<T>*& node - current node reference
 *         T val - value to insert
 * Output: Recursively finds the correct position and inserts.
 *         Duplicate values are ignored.
 * author: Jay Neill
 **************************************************************/
template <typename T>
void BST<T>::InsertHelper(BSTNode<T>*& node, T val) {
    if (node == nullptr)
        node = new BSTNode<T>(val);
    else if (val < node->data)
        InsertHelper(node->left, val);
    else if (val > node->data)
        InsertHelper(node->right, val);
    // Ignore duplicates
}

/**************************************************************
 * Function: BST::Search
 * Return: bool
 * Input:  T val - value to search for
 * Output: Returns true if val is found in the BST, false otherwise
 * author:Jay Neill
 **************************************************************/
template <typename T>
bool BST<T>::Search(T val) {
    return SearchHelper(root, val);
}

/**************************************************************
 * Function: BST::SearchHelper
 * Return: bool
 * Input:  BSTNode<T>* node - current node
 *         T val - value to search for
 * Output: Recursively searches the BST. Returns true if found,
 *         false if the subtree is exhausted.
 * author: Jay Neill
 **************************************************************/
template <typename T>
bool BST<T>::SearchHelper(BSTNode<T>* node, T val) {
    if (node == nullptr) return false;
    if (val == node->data) return true;
    if (val < node->data) return SearchHelper(node->left, val);
    return SearchHelper(node->right, val);
}

/**************************************************************
 * Function: BST::Remove
 * Return: bool
 * Input:  T val - value to remove from the BST
 * Output: Delegates to RemoveHelper. Returns true if val was
 *         removed, false if not found.
 * author: Jay Neill
 **************************************************************/
template <typename T>
bool BST<T>::Remove(T val) {
    bool removed = false;
    root = RemoveHelper(root, val, removed);
    return removed;
}

/**************************************************************
 * Function: BST::RemoveHelper
 * Return: BSTNode<T>*
 * Input:  BSTNode<T>* node - current node
 *         T val - value to remove
 *         bool &removed - set to true if val was found and removed
 * Output: Recursively removes val. Handles 0, 1, and 2 child cases.
 *         Uses in-order successor for 2-child case.
 * author: Jay Neill
 **************************************************************/
template <typename T>
BSTNode<T>* BST<T>::RemoveHelper(BSTNode<T>* node, T val, bool& removed) {
    if (node == nullptr) return nullptr;
    if (val < node->data)
        node->left = RemoveHelper(node->left, val, removed);
    else if (val > node->data)
        node->right = RemoveHelper(node->right, val, removed);
    else {
        removed = true;
        if (node->left == nullptr) {
            BSTNode<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode<T>* temp = node->left;
            delete node;
            return temp;
        } else {
            BSTNode<T>* minNode = FindMin(node->right);
            node->data = minNode->data;
            bool dummy = false;
            node->right = RemoveHelper(node->right, minNode->data, dummy);
        }
    }
    return node;
}

/**************************************************************
 * Function: BST::FindMin
 * Return: BSTNode<T>*
 * Input:  BSTNode<T>* node - starting node
 * Output: Returns the leftmost (minimum value) node in the subtree
 * author: Jay Neill
 **************************************************************/
template <typename T>
BSTNode<T>* BST<T>::FindMin(BSTNode<T>* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

/**************************************************************
 * Function: BST::Print
 * Return: void
 * Input:  none
 * Output: Delegates to PrintHelper for in-order traversal output
 * author: Jay Neill
 **************************************************************/
template <typename T>
void BST<T>::Print() {
    PrintHelper(root);
}

/**************************************************************
 * Function: BST::PrintHelper
 * Return: void
 * Input:  BSTNode<T>* node - current node
 * Output: Recursively prints all elements in-order (sorted ascending)
 * author: Jay Neill
 **************************************************************/
template <typename T>
void BST<T>::PrintHelper(BSTNode<T>* node) {
    if (node == nullptr) return;
    PrintHelper(node->left);
    cout << node->data << " ";
    PrintHelper(node->right);
}

/**************************************************************
 * Function: BST::IsEmpty
 * Return: bool
 * Input:  none
 * Output: Returns true if the BST is empty, false otherwise
 * author:Jay Neill
 **************************************************************/
template <typename T>
bool BST<T>::IsEmpty() {
    return root == nullptr;
}

#endif
