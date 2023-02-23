#define parent (i >> 1) // i/2
#define left (i << 1) // i*2
#define right (i << 1 | 1) // i*2 + 1
const int MAX_N = 100000;
class MaxHeap {
private:
    int data[MAX_N + 1];
    int size = 0;
public:
    void Swap(int& x, int& y){
        int t = x;
        x = y;
        y = t;
    }

    bool IsEmpty(){
        if(size==0)
            return true;
        return false;
    }

    // insert new data
	void push(int x) {
		data[++size] = x; // plus 1 index and push new data
		
        // bubble up 
        for (int i = size; parent != 0 && data[parent] < data[i]; i >>= 1) {
			Swap(data[parent], data[i]);
		}
	}

	// return root
	int top() const {
		return data[1];
	}

	// remove root
	void pop() {
        // change root and last data and minus index.
		data[1] = data[size--]; 

        // bubble down
		for (int i = 1; left <= size;) {
			if (left == size || data[left] > data[right]) {
				if (data[i] < data[left]) {
					Swap(data[i], data[left]);
					i = left;
				}else 
				    break;
				
			}else{
				if (data[i] < data[right]){
					Swap(data[i], data[right]);
					i = right;
				}else 
				    break;
			}
		}
	}
};