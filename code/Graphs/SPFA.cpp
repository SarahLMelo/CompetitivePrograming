bool spfa(int s) {
    int n = g.size();
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : g[v]) {
            int u = edge.first;
            int w = edge.second;

            if (d[v] + w < d[u]) {
                //if(!isPath[u]) continue;
                d[u] = d[v] + w;
                if (!inqueue[u]) {
                    q.push(u);
                    inqueue[u] = true;
                    cnt[u]++;
                    if (cnt[u] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}
