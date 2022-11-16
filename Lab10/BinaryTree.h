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

	Node* InsertNode(Node* node, int data);
	Node* RemoveNode(Node* node, int data);
	void PrintNode(Node* node);

	int SearchMinNode(Node* node);
	int SearchMaxNode(Node* node);


public:
	void Insert(int data);
	void Remove(int data);
	void Print();

	int SearchMin();
	int SearchMax();

};