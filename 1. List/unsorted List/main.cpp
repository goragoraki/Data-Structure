#include <iostream>
#include <cmath>
#include "ItemType.h"
#include "unsorted.h"
using namespace std;
// insert minus number => list abs(number) in list.
int main() {
	UnsortedType list;
	int InsertNumber[11] = { 1,8,5,9,7,1,7,5,-1,8,0 };

	for (int i = 0; i < 11; i++) {
		ItemType item;
		if (InsertNumber[i] < 0) {
			int num = abs(InsertNumber[i]);
			bool check = true;

			item.Initialize(num);
			while (check) {
				list.RetrieveItem(item, check);
				if (check) {
					list.DeleteItem(item);
				}
			}
		}
		else {
			item.Initialize(InsertNumber[i]);
			list.InsertItem(item);
		}
	}
	list.ResetList();
	for (int i = 0; i < list.LengthIs(); i++) {
		ItemType item;
		list.GetNextItem(item);
		item.Print(cout);
	}
	return 0;
}