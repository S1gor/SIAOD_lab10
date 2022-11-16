#include <iostream>
#include "BinaryTree.h"

using namespace std;

// —оздать бинарное дерево и осуществить: добавление, удаление, поиск, обход дерева 3 способами.

int main()
{
	BinaryTree a;

	a.Insert(20);
	a.Insert(30);
	a.Insert(20);
	a.Insert(1);
	a.Insert(1);
	a.Insert(90);
	a.Insert(25);

	a.Print();

	cout << a.SearchMin() << endl;
	cout << a.SearchMax() << endl;
	
	return 0;
}