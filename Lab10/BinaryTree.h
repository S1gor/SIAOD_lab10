#pragma once

class BinaryTree
{
private:
	struct Node
	{
		int data;
		int counter;
		Node* left;
		Node* right;
		Node* parent;
	};

	Node* root = nullptr;

	Node* InsertNode(Node* node, int data);
	Node* RemoveNode(Node* node, int data);
	void PrintNode(Node* node);

	Node* SearchNode(Node* node, int data);
	int SearchMinNode(Node* node);
	int SearchMaxNode(Node* node);

	int SuccessorNode(Node* node);


public:
	void Insert(int data);
	void Remove(int data);
	void Print();

	void Search(int data);
	int SearchMin();
	int SearchMax();

	int Successor(int data);
};