// BinarySearchTree_0069

#include <iostream>
using namespace std;

class Node
{
public:
  int info;
  Node *leftchild;
  Node *rightchild;

  // Constructor for the node class
  Node()
  {
    leftchild = nullptr;  // initialize left child to null
    rightchild = nullptr; // Initialize right child to null
  }
};

class BinaryTree
{
public:
  Node *ROOT;

  BinaryTree()
  {
    ROOT = nullptr; // Initialize ROOT to null
  }

  void insert()
  {
    int x;
    cout << "Masukkan nilai: ";
    cin >> x;

    // Step 1: Alocate memery for the new node
    Node *newNode = new Node();

    // Step 2: Assign value to the data filed of new node
    newNode->info = x;

    
