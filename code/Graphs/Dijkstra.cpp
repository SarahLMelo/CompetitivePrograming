#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;
const ll inf = 1e18;

int n, m;
vector <vector <ii>> g;
vector <ll> dist;

void init(){
    g.resize(n);
    dist.assign(n, inf);
}

void dijkstra(int x){
    dist[x] = 0;

    priority_queue <ii, vector <ii>, greater <ii>> pq;
    pq.emplace(0, x);

    while(!pq.empty()){
        ll w, u;
        w = pq.top().first;
        u = pq.top(). second;

        pq.pop();

        if(dist[u] < w) continue;

        for(auto i:g[u]){

            if(dist[i.first] > w + i.second){
                dist[i.first] = w + i.second;
                pq.emplace(w + i.second, i.first);
            }
        }
    }

    return;
}
