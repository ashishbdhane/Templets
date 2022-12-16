// @author: stash ¯\_(ツ)_/¯

class DisjointSet{
public:
    vector<int> size,mini,maxi,parent,rank;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=1;
            size[i]=1;
        }
    }

    int get(int node)
    {
        return parent[node]=((node==parent[node])?node:get(parent[node]));
    }

    void unionByRank(int u,int v)
    {
        u=get(u);
        v=get(v);
        if(u==v)
            return;
        if(rank[u]==rank[v])
        {
            rank[u]++;
        }
        if(rank[u]>rank[v])
        {
            size[u]+=size[v];
            parent[v]=u;
        }
        else
        {
            size[v]+=size[u];
            parent[u]=v;
        }
    }  
};
