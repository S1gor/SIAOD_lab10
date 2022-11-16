#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::Node* BinaryTree::InsertNode(Node* node, int data)
{
	if (node == NULL)
	{
		node = new Node;
		node->data = data;
		node->left = node->right = nullptr;
		node->counter = 1;
		return node;
	}

	if (data == node->data)
	{
		node->counter++;
		return node;
	}
	else if (data < node->data)
		node->left = InsertNode(node->left, data);
	else
		node->right = InsertNode(node->right, data);

	return node;
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

BinaryTree::Node* BinaryTree::RemoveNode(Node* node, int data)
{
	if (node == NULL)			return NULL;

	if (node->data == data)
	{
		if (node->left == NULL && node->right == NULL)
			node = NULL;
		else if (node->left == NULL && node->right != NULL)
			node = node->right;
		else if (node->left != NULL && node->right == NULL)
			node = node->left;
		else
		{
			// !!!
		}
	}
	else if (node->data < data)
		node->right = RemoveNode(node->right, data);
	else
		node->left = RemoveNode(node->left, data);

	return node;
}

int BinaryTree::SearchMinNode(Node* node)
{
	if (node == NULL)			return -1;
	if (node->left == NULL)		return node->data;
	else SearchMinNode(node->left);
}

int BinaryTree::SearchMaxNode(Node* node)
{
	if (node == NULL)			return -1;
	if (node->right == NULL)	return node->data;
	else SearchMaxNode(node->right);
}



void BinaryTree::Insert(int data)
{
	root = InsertNode(root, data);
}

void BinaryTree::Print()
{
	PrintNode(root);
	cout << endl;
}

void BinaryTree::Remove(int data)
{
	root = RemoveNode(root, data);
}

int BinaryTree::SearchMin()
{
	return SearchMinNode(root);
}

int BinaryTree::SearchMax()
{
	return SearchMaxNode(root);
}
