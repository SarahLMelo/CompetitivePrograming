vector <int> tree;

void update(int pos, int val){
    // tree[pos] += val

    for(int x = pos; x < tree.size(); x += x & -x){
        tree[x] += val;
    }
}

int query(int pos){
    // soma de tree[i <= pos]

    int ans = 0;
    for(int x = pos; x > 0; x -= x & -x){
        ans += tree[x];
    }

    return ans;
}
