#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXL = 1e4 + 5;
vector<int> G[MAXL];
bool vis[MAXL];
int matchA[MAXL], matchB[MAXL];

bool dfs(int node){
    for(auto &u : G[node]){
        if(vis[u]) continue;
        vis[u] = 1;
        if(matchB[u] == 0 || dfs(matchB[u])){
            matchB[u] = node;
            matchA[node] = u;
            return true;
        }
    }
    return false;
}

ll kunh(int len){
    bool flag = true;
    ll ans = 0LL;
    while (flag){
        for(int i = 1; i <= len; i++) vis[i] = false;
        flag = false;
        for(int buyer = 1; buyer <= len; buyer++){
            if(matchA[buyer]) continue;
            if(dfs(buyer)){
                ans++;
                flag = true;
            }
        }
    }
    return ans;
}