#include <iostream>
#include "BinaryTree.h"

using namespace std;

// ������� �������� ������ � �����������: ����������, ��������, �����, ����� ������ 3 ���������.

int main()
{
	BinaryTree a;

	a.Insert(20);
	a.Insert(30);
	a.Insert(20);
	a.Insert(6);
	a.Insert(3);
	a.Insert(7);
	a.Insert(12);
	a.Insert(90);
	a.Insert(25);

	a.Print();
	a.PrintPre();
	a.PrintPost();

	return 0;
}