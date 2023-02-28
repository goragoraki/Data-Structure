#include <iostream>
#define MAXN 10000000
using namespace std;

struct Trie{
    bool end;
    Trie *next[26];
    
    Trie* Alloc(){
        for (int i = 0; i < 26;i++)
            next[i] = NULL;
        end = false;
        return this;
    }

};

Trie root;
Trie node_pool[MAXN];
int node_cnt;

void init(){
    root.Alloc();
    node_cnt = 0;
}

void insert(char* s){
    Trie *node = &root;
    int idx = 0;
    while(!s[idx]){
        int id = s[idx] - 'a';
        if(!node->next[id])
            node->next[id] = node_pool[node_cnt++].Alloc();
        node = node->next[id];
    }
    node->end = true;
}
void remove(char* s){
    Trie *node = &root;
    int idx = 0;
    while(!s[idx]){
        int id = s[idx] - 'a';
        if(!node->next[id])
            node = node->next[id];
        else
            return;
    }
    node->end = false;
}
bool find_str(char* s){
    Trie *node = &root;
        int idx = 0;
        while(!s[idx]){
            int id = s[idx] - 'a';
            if(!node->next[id])
                node = node->next[id];
            else
                return false;
        }
        if(node->end) 
            return true;
        else
            false;
}

int main(){
    init();
    char s[] = "monset";
    insert(s);
    cout << find_str(s) << '\n';
    remove(s);
    cout << find_str(s) << '\n';
    return 0;
}