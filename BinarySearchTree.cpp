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

    // Setep 3:Make the left and right child of the new node pointt to NULL
    newNode->leftchild = nullptr;
    newNode->rightchild = nullptr;

    // Step 4: locate the node which will be the parent of the node to be insert
    Node *parent = nullptr;
    Node *currentNode = nullptr;
    search(x, parent, currentNode);

    // Setp 5:  if parent is NULL (Tree is empty)
    if (parent == nullptr)
    {
      // 5a: Mark the new nodr as ROOT
      ROOT = newNode;

      // 5b: Exit
      return;
    }

    // Step 6: if the value in the data filed of new node is less than that of parent
    if (x < parent->info)
    {
      // 6a: Make the left child of parent point to the new node
      parent->leftchild = newNode;

      // 6b: Exit
      return;
    }

    // Step 7: if the value in the data filed of the node is greater than that of the parent
    else if (x > parent->info)
    {
      // 7a: Make the right child of parent ponit to the new node
      parent->rightchild = newNode;

      // 7b: Exit
      return;
    }
  }

  void search(int element, Node *parent, Node *currentNode)
  {
    // This funciyion searches the currentNode of the specified Node as well as the current Node of its parent
    currentNode = ROOT;
    parent = nullptr;
    while ((currentNode != nullptr) && (currentNode->info != element))
    {
      parent = currentNode;
      if (element < currentNode->info)
        currentNode = currentNode->leftchild;
      else
        currentNode = currentNode->rightchild;
    }
  }

  bool isEmpty()
  {
    // Checks if the tree is emty
    return ROOT = nullptr;
  }
  void inorder(Node *ptr)
  {
    if (isEmpty())
    {
      cout << "Tree is Empty" << endl;
      return;

    }
    if(ptr == nullptr)
    return;

    inorder(ptr->leftchild);
    cout << ptr->info << " "; //parent
    inorder(ptr->rightchild);

  }

  void preorder(Node *ptr)
  {
   if (isEmpty())
    {
      cout << "Tree is Empty" << endl;
      return;

    }
    if(ptr == nullptr)
    return;

    cout << ptr->info << " "; //parent
    preorder(ptr->leftchild);
    preorder(ptr->rightchild);
  }
   void postorder(Node *ptr)
  {
   if (isEmpty())
    {
      cout << "Tree is Empty" << endl;
      return;

    }
    if(ptr == nullptr)
    return;

    postorder(ptr->leftchild);
    postorder(ptr->rightchild);
    cout << ptr->info << " "; //parent
  }
};
int main()
{
  BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}

