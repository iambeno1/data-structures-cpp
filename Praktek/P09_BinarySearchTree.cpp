#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct TreeNode
{
    char info;
    TreeNode* left;
    TreeNode* right;
} tree_t;

tree_t* root = nullptr;


enum orderType { PRE_ORDER, IN_ORDER, POST_ORDER };

const int MAX_SIZE = 100;
char queueItems[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(char newItem);
void dequeue(char& item);

void makeEmpty(tree_t*& tree);
bool isEmpty(tree_t* tree);
bool isFull();  // Assuming the tree is not explicitly size-limited
int lengthIs(tree_t* tree);
void retrieveItem(char& item, bool& found, tree_t* tree);
void insertItem(char item, tree_t*& tree);
void deleteItem(char item, tree_t*& tree);
void deleteNode(tree_t*& tree);
void getPredecessor(tree_t* tree, char& data);

void enqueue(char newItem);
void dequeue(char& item);
void PreOrder(tree_t* tree);
void InOrder(tree_t* tree);
void PostOrder(tree_t* tree);
void resetTree(orderType order, tree_t* tree);
void getNextItem(char& item, orderType order, tree_t*& tree);
void print(tree_t* tree);

int main()
{
  system("cls");
    // Example usage:
    insertItem('D', root);
    insertItem('B', root);
    insertItem('A', root);
    insertItem('C', root);
    insertItem('F', root);
    insertItem('E', root);
    insertItem('G', root);

    cout << "In-Order Traversal: ";
    print(root);
    //resetTree(IN_ORDER, root);
    char currentItem;
    //getNextItem(currentItem, IN_ORDER, root);
    //while (currentItem != '\0')
    //{
    //    cout << currentItem << " ";
    //    getNextItem(currentItem, IN_ORDER, root);
    //}

    return 0;
}

void makeEmpty(tree_t*& tree)
{
    if (tree != nullptr)
    {
        makeEmpty(tree->left);
        makeEmpty(tree->right);
        delete tree;
    }
    tree = nullptr;
}

bool isEmpty(tree_t* tree)
{
    return tree == nullptr;
}

bool isFull()
{
    tree_t* location;
    try
    {
        location = new tree_t;
        delete location;
        return false;
    }
    catch (bad_alloc)
    {
        return true;
    }
}

int lengthIs(tree_t* tree)
{
    if (tree == nullptr)
        return 0;
    else
        return 1 + lengthIs(tree->left) + lengthIs(tree->right);
}

void retrieveItem(char& item, bool& found, tree_t* tree)
{
    if (tree == nullptr)
        found = false;
    else if (item < tree->info)
        retrieveItem(item, found, tree->left);
    else if (item > tree->info)
        retrieveItem(item, found, tree->right);
    else
    {
        found = true;
        item = tree->info;
    }
}

void insertItem(char item, tree_t*& tree)
{
    if (tree == nullptr)
    {
        tree = new TreeNode;
        tree->info = item;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    else if (item < tree->info)
        insertItem(item, tree->left);
    else
        insertItem(item, tree->right);
}

void deleteItem(char item, tree_t*& tree)
{
    if (tree == nullptr)
        return;

    if (item < tree->info)
        deleteItem(item, tree->left);
    else if (item > tree->info)
        deleteItem(item, tree->right);
    else
    {
        deleteNode(tree);
    }
}

void deleteNode(tree_t*& tree)
{
    char data;
    tree_t* tempPtr;

    tempPtr = tree;
    if (tree->left == nullptr)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right == nullptr)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        getPredecessor(tree->left, data);
        tree->info = data;
        deleteItem(data, tree->left);
    }
}

void getPredecessor(tree_t* tree, char& data)
{
    while (tree->right != nullptr)
        tree = tree->right;
    data = tree->info;
}


void print(tree_t* tree)
{
    if (tree != nullptr)
    {
        print(tree->left);
        cout << tree->info << " ";
        print(tree->right);
    }
}
