#include <iostream>
using namespace std;

struct Node
{
	string data;
	struct Node *next;
	struct Node *child;
};

// Creating new Node
Node* newNode(string data)
{
	Node *newNode = new Node;
	newNode->next = newNode->child = NULL;
	newNode->data = data;
	return newNode;
}

// Adds a sibling to a list with starting with n
Node *addSibling(Node *n, string data)
{
	if (n == NULL)
		return NULL;

	while (n->next)
		n = n->next;

	return (n->next = newNode(data));
}

// Add child Node to a Node
Node *addChild(Node * n, string data)
{
	if (n == NULL)
		return NULL;

	// Check if child list is not empty.
	if (n->child)
		return addSibling(n->child, data);
	else
		return (n->child = newNode(data));
}

// Traverses tree in depth first order
void traverseTree(Node * root)
{
	if (root == NULL)
		return;

	while (root)
	{
		cout << " " << root->data;
		if (root->child)
			traverseTree(root->child);
		root = root->next;
	}
}

//Driver code

int main()
{
  system("cls");
	
	Node *root = newNode("Benony");
	Node *n1 = addChild(root, "Amanda");
	Node *n2 = addChild(n1, "Ekal");
	Node *n3 = addChild(n1, "Imanuel");
	Node *n4 = addChild(root, "Jihan");
	Node *n5 = addChild(n4, "Ferdinan");
	Node *n6 = addChild(n4, "Dito");
	Node *n7 = addChild(n4, "Surya");
	Node *n8 = addChild(root, "Akira");
	Node *n9 = addChild(n8, "Algif");
	Node *n10 = addChild(n8, "Diva");
	Node *n11 = addChild(root, "Baruna");
	Node *n12 = addChild(n11, "Pebry");
	Node *n13 = addChild(n11, "Felix");
	Node *n14 = addChild(n11, "Yan");
	traverseTree(root);

	return 0;
}