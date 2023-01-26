#include <iostream>
#include "TreeType.h"
#include "QueType.h"
using namespace std;
int main() {
	ItemType node[] = { 5,3,7,1,4 };
	TreeType tree;
	for (int i = 0; i < 5; i++) {
		tree.InsertItem(node[i]);
	}
	QueType q;
	ItemType item;
	bool finish = false;
	tree.ResetTree(PRE_ORDER);
	while (!finish) {
		tree.GetNextItem(item, PRE_ORDER, finish);
		cout << item << " ";
	} 

	
	return 0;
}