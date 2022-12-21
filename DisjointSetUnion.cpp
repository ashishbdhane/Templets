class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        u = findUPar(u); 
        v = findUPar(v); 
        if(v == u) return;
        if(rank[u]==rank[v])
            rank[u]++;
        if(rank[u]<rank[v])swap(u,v);
        
        parent[v] = u; 
    }

    void unionBySize(int u, int v) {
        u = findUPar(u); 
        v = findUPar(v); 
        if(u == v) return; 
        if(size[u]<size[v]) swap(u,v);
        
        parent[v] = u;
        size[u] += size[v]; 
    }
};
