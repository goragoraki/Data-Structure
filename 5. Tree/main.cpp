#include <iostream>
#include "TreeType.h"
using namespace std;

int main()
{
	TreeType tree;
	int nodeNum;
	int item;
	cin >> nodeNum;
	for (int i = 0; i < nodeNum; i++)
	{
		cin >> item;
		tree.InsertItem(item);
	}
	int cutNum;
	cin >> cutNum;
	for (int i = 0; i < cutNum; i++)
	{
		tree.DeleteTree();
	}
	cout << tree.NumberLeaf() << endl;

	return 0;
}