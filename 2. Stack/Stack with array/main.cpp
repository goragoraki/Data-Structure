#include <iostream>
#include "StackTType.h"

using namespace std;
int main() {
	StackType<int> st;
	int stick[7] = { 5,7,4,5,3,2,3 };
	for (int i = 0; i < 7; i++) {
		st.Push(stick[i]);
	}
	
	int count = 0;
	int Highest_stick = -1;
	while (!st.IsEmpty()) {
		int Top_item = st.Top();
		st.Pop();
		if (Top_item > Highest_stick) {
			count++;
			Highest_stick = Top_item;
		}
	}
	cout << count << '\n';
	return 0;
}