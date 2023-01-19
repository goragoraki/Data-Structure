#include <iostream>
#include "QueType.h"
using namespace std;
const int CardNum = 7;
int main() {
	QueType<int> q;
	int cards[CardNum] = { 1,2,3,4,5,6,7 };
	for (int i = 0; i < CardNum; i++) {
		q.Enqueue(cards[i]);
	}
	int front_value;
	while (!q.IsEmpty()) {
		
		q.Dequeue(front_value);
		cout << front_value << " ";
		if (!q.IsEmpty()) {
			q.Dequeue(front_value);
			if(!q.IsEmpty())
				q.Enqueue(front_value);
		}
	}
	cout << front_value << '\n';
	return 0;
}