#include "BinaryTree.h"
#include <iostream>

using namespace std;

void BinaryTree::InsertNode(Node* node, int data)
{
	if (data == node->data)
	{
		node->counter++;
		return;
	}
	else if (data < node->data)
	{
		if (node->left == NULL)
		{
			node->left = new Node;
			node->left->data = data;
			node->left->left = node->left->right = nullptr;
			node->left->counter = 1;
		}
		else	InsertNode(node->left, data);
	}
	else
	{
		if (node->right == NULL)
		{
			node->right = new Node;
			node->right->data = data;
			node->right->left = node->right->right = nullptr;
			node->right->counter = 1;
		}
		else	InsertNode(node->right, data);
	}
}

void BinaryTree::PrintNode(Node* node)
{
	if (node == NULL)	return;
	
	PrintNode(node->left);
	cout << " " << node->data;
	if (node->counter > 1)
		cout << "x" << node->counter;
	PrintNode(node->right);
}

void BinaryTree::RemoveNode(Node* node, int data)
{
	if (node == NULL)			return;
	if (data < node->data)		RemoveNode(node->left, data);
	else if (data > node->data)	RemoveNode(node->right, data);


}



void BinaryTree::Insert(int data)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = data;
		root->left = root->right = nullptr;
		root->counter = 1;
	}
	else
		InsertNode(root, data);
}

void BinaryTree::Print()
{
	PrintNode(root);
	cout << endl;
}

void BinaryTree::Remove(int data)
{
	RemoveNode(root, data);
}
