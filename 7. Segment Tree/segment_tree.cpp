#include <iostream>
using namespace std;
const int MAX_TABLE = 10;
const int n = 5;
int arr[n] = {5, 1, 3, 6, 4};
int segtree[2 * MAX_TABLE];
void init(){
    for (int i = 0; i < n; i++){
        segtree[n + i] = arr[i];
    }
    for (int i = n - 1; i >= 1; i--){
        // 부모 = 왼쪽 자식 구간 합 + 오른쪽 자식 구간 합.
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}
void update(int idx, int x){
    segtree[idx + n] = x;
    int i = ((idx + n) >> 1);
    for (; i >= 1; i>>=1){
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}
// 구간 [l,r) 까지의 합 return
int find_x(int l, int r){
    l += n;
    r += n;
    int result = 0;
    while(l!=r){
        if(l&1)
            result += segtree[l++];
        if(r&1)
            result += segtree[--r];
        l >>= 1;
        r >>= 1;
    }
    return result;
}

int main(){

    return 0;
}