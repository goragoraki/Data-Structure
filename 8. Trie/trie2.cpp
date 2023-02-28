#include <iostream>
#include <vector>
using namespace std;
#define MAXM 401
vector<char> result;
int cnt, flag, k;
struct TrieNode{
    bool end;
    TrieNode *next[26];

    TrieNode* Alloc(){
        end = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        return this;
    }
} nodes[MAXM * MAXM];
int nodeCnt;
TrieNode head;

void Init(){
    nodeCnt = 0;
    head.Alloc();
}

void insert(char* s){
    int idx = 0;
    TrieNode *node = &head;
    while(s[idx]){
        int id = s[idx] - 'a';
        if(!node->next[id]){
            node->next[id] = nodes[nodeCnt++].Alloc();
        }
        node = node->next[id];
        idx++;
    }
}

void find_k(TrieNode* tmp){
    TrieNode* node = tmp;
    if(cnt == k){
        flag = 1;
        return;
    }
    for (int i = 0; i < 26;i++){
        if(node->next[i]){
            result.push_back(i + 'a');
            if(!node->next[i]->end)
                cnt++;
            find_k(node->next[i]);
            if(flag)
                return;
            result.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t; 
    while(t--){
        char s[MAXM];
        result.clear();
        cnt = flag = 0;
        cin >> k;
        cin >> s;
        Init();
        for (int i = 0; s[i]; i++){
            insert(&s[i]);
        }
        find_k(&head);
        if(!result.size()){
            cout << "none" << '\n';
            continue;
        }
        for (int i = 0; i < result.size();i++){
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}