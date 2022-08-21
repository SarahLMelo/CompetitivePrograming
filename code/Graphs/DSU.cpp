#include <bits/stdc++.h>

using namespace std;

const int nMax = 1e5 + 5;
int parent[nMax];
int sz[nMax];

int n, m;

//Remainer : It is indexed in 0!

void init(){
    for(int i=0; i<n; i++){
        parent[i] = i;
        sz[i] = 1;
    }

    return;
}

int find(int x){
    if(parent[x] != x) return parent[x] = find(parent[x]);

    return parent[x];
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(sz[a] < sz[b]) swap(a, b);
    if(a != b) sz[a] += sz[b];

    parent[b] = a;

    return;
}
