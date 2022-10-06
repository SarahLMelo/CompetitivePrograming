long long Prim(int source = 0){
    for(int i = 0; i < n; i++) dist[i] = inf;
    dist[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, source);
    while (!pq.empty()){
        int d = pq.top().first, u = pq.top().second; 
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        
        for(auto e : adjList[u]){
            int v = e.first, w = e.second;
            if (!inMST[v] && w < dist[v]) {
                // parent[v] = u;
                dist[v] = w;
                pq.emplace(dist[v], v);
            }
        }
    }
}
