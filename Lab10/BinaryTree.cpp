#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::Node* BinaryTree::InsertNode(Node* node, int data)
{
	if (node == NULL)
	{
		node = new Node;
		node->data = data;
		node->left = node->right = node->parent = nullptr;
		node->counter = 1;
		return node;
	}

	if (data == node->data)
	{
		node->counter++;
		return node;
	}
	else if (data < node->data)
	{
		node->left = InsertNode(node->left, data);
		node->left->parent = node;
	}
	else
	{
		node->right = InsertNode(node->right, data);
		node->right->parent = node;
	}

	return node;
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
			int successor = Successor(data);
			node->data = successor;
			node->counter = node->right->counter;
			node->right = RemoveNode(node->right, successor);
		}
	}
	else if (node->data < data)
		node->right = RemoveNode(node->right, data);
	else
		node->left = RemoveNode(node->left, data);

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

void BinaryTree::PrintPostNode(Node* node)
{
	if (node == NULL)	return;

	PrintPostNode(node->left);
	PrintPostNode(node->right);
	cout << " " << node->data;
	if (node->counter > 1)
		cout << "x" << node->counter;
}

void BinaryTree::PrintPreNode(Node* node)
{
	if (node == NULL)	return;

	cout << " " << node->data;
	if (node->counter > 1)
		cout << "x" << node->counter;
	PrintPreNode(node->left);
	PrintPreNode(node->right);
}

BinaryTree::Node* BinaryTree::SearchNode(Node* node, int data)
{
	if (node == NULL)	return NULL;

	if (data == node->data)
		return node;
	else if (data < node->data)
		return SearchNode(node->left, data);
	else
		return SearchNode(node->right, data);
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

int BinaryTree::SuccessorNode(Node* node)
{
	if (node->right != NULL)		return SearchMinNode(node->right);
	else
	{
		Node* parent_node = node->parent;
		Node* current_node = node;

		while ((parent_node != NULL) && (current_node == parent_node->right))
		{
			current_node = parent_node;
			parent_node = current_node->parent;
		}

		return parent_node == NULL ? -1 : parent_node->data;
	}
}


void BinaryTree::Insert(int data)
{
	root = InsertNode(root, data);
}

void BinaryTree::Remove(int data)
{
	root = RemoveNode(root, data);
}

void BinaryTree::Print()
{
	cout << "Tree (LrR): ";
	PrintNode(root);
	cout << endl;
}

void BinaryTree::PrintPost()
{
	cout << "Tree (LRr): ";
	PrintPostNode(root);
	cout << endl;
}

void BinaryTree::PrintPre()
{
	cout << "Tree (rLR): ";
	PrintPreNode(root);
	cout << endl;
}

void BinaryTree::Search(int data)
{
	Node* result = SearchNode(root, data);
	if (result) cout << "The number " << data << " met " << result->counter << " once" << endl;
	else cout << "There is no number " << data << endl;
}

int BinaryTree::SearchMin()
{
	return SearchMinNode(root);
}

int BinaryTree::SearchMax()
{
	return SearchMaxNode(root);
}

int BinaryTree::Successor(int data)
{
	Node* node = SearchNode(root, data);
	return node == NULL ? -1 : SuccessorNode(node);
}