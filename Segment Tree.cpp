// @author: stash ¯\_(ツ)_/¯

struct segtree
{
    vector<ll> vec;
    ll size=1;
    segtree(ll n)
    {
        while(size<n)size*=2;
        vec.assign(2*size,0);
    }
    void build(vector<ll> &a,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
            if(lx<a.size())
            {
                vec[x]=a[lx];
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        vec[x]=vec[x*2+1]+vec[x*2+2];
    }

    void build(vector<ll> &a)
    {
        build(a,0,0,size);
    }

    void set(ll& i, ll& val, ll x, ll lx, ll rx)
    {
        if(rx-lx==1)
        {
            vec[x]=val;
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m)
            set(i,val,2*x+1,lx,m);
        else
            set(i,val,2*x+2,m,rx);
        
        vec[x]=vec[2*x+1]+vec[2*x+2];
        
    }

    void set(ll i, ll val)
    {
        set(i,val,0,0,size);
    }

    ll sum(ll &l, ll &r, ll x, ll lx, ll rx)
    {
        if(lx>=r || rx<=l) return 0;
        if(lx>=l && rx<=r)return vec[x];
        ll m=(lx+rx)/2;
        ll s1=sum(l,r,2*x+2,m,rx);
        ll s2=sum(l,r,2*x+1,lx,m);
        return s1+s2;
    }

    ll sum(ll l, ll r)
    {
        return sum(l, r , 0, 0, size);
    }
};
