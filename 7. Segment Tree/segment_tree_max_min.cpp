#include <iostream>
using namespace std;
struct sg{
    int mx;
    int mn;
};
int n, q;
int a[100002];
sg segtree[2 * 100002];

void init() {
    for (size_t i = 0; i < n; ++i){
        segtree[i + n].mx = a[i];
        segtree[i + n].mn = a[i];
    }
    for (size_t i = n - 1; i != 0; --i){
        segtree[i].mx = max(segtree[i << 1].mx, segtree[i << 1 | 1].mx);
        segtree[i].mn = min(segtree[i << 1].mn, segtree[i << 1 | 1].mn);
    }
}
void update(size_t i, int x) {
    segtree[i += n].mx = x;
    segtree[i].mn = x;
    while (i >>= 1){
        segtree[i].mx = max(segtree[i << 1].mx, segtree[i << 1 | 1].mx);
        segtree[i].mn = min(segtree[i << 1].mn, segtree[i << 1 | 1].mn);
    }
}
void query(size_t l, size_t r, int& ans1, int& ans2) {

    int result1 = 0;
    int result2 = 999999991;

    for (l += n, r += n; l != r; l >>= 1, r >>= 1) {
        if (l & 1){
            result1 = max(result1, segtree[l].mx);
            result2 = min(result2, segtree[l++].mn);
        }
        if (r & 1) {
            result1 = max(result1, segtree[--r].mx);
            result2 = min(result2, segtree[r].mn);
        }
    }

    ans1 = result1;
    ans2 = result2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, tc = 1;
    cin >> t;
    while(t--){
        cin >> n >> q;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        init();
        int cmd, x1, x2;
        cout << "#" << tc++ << " ";
        for (int i = 0; i < q; i++){
            cin >> cmd >> x1 >> x2;
            if(cmd==0){
                update(x1, x2);
            }else{
                int ans1, ans2;
                query(x1, x2, ans1, ans2);
                cout << ans1 - ans2 << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}