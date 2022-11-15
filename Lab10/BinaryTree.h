#pragma once

class BinaryTree
{
private:
	struct Node
	{
		int data;
		Node* left;
		Node* right;
		int counter;
	};

	Node* root = nullptr;

	void InsertNode(Node* node, int data);
	void PrintNode(Node* node);
	void RemoveNode(Node* node, int data);



public:
	void Insert(int data);
	void Print();
	void Remove(int data);

};

