#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define pi 3.1415926535
#define endl '\n'
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const ll inf=1e19;
ll power(ll x,ll y)
{
    ll res=1;
    while(y>0)
    {
        if(y%2==1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        y=(y>>1);
    }
    return res;
}
bool tree[800001][27];
ll fac[300001];
void build(int node, int s, int e,ll arr[])
{
    if(s == e)
    {
        // Leaf node will have a single element
        tree[node][arr[s]] = 1;
    }
    else
    {
        int mid = (s + e) / 2;
        // Recurse on the left child
        build(2*node, s, mid,arr);
        // Recurse on the right child
        build(2*node+1, mid+1, e,arr);
        // Internal node will have the sum of both of its children
 
        for(int i=0;i<=25;i++)
            tree[node][i]=tree[2*node][i]|tree[2*node+1][i];
    }
}
void update(int node, int s, int e, int idx, int val,ll arr[])
{
    if(s == e)
    {
        // Leaf node
        tree[node][arr[idx]]=0;
        arr[idx]=val;
        tree[node][arr[idx]]=1;
    }
    else
    {
        int mid = (s + e) / 2;
        if(s <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, s, mid, idx, val,arr);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, e, idx, val,arr);
        }
        // Internal node will have the sum of both of its children
        for(int i=0;i<=25;i++)
        tree[node][i] = tree[2*node][i] | tree[2*node+1][i];
    }
}
void query(int node, int s, int e, int l, int r,bool ans[])
{
    if(r < s or e < l)
    {
        // range represented by a node is completely outside the given range
        return ;
    }
    if(l <= s and e <= r)
    {
        // range represented by a node is completely inside the given range
        for(int i=0;i<=25;i++)
            ans[i]=ans[i]|tree[node][i];
        return;
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (s + e) / 2;
    query(2*node, s, mid, l, r,ans);
     query(2*node+1, mid+1, e, l, r,ans);
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,q,i,j,a,b,c,r,k,x,y,l;
    cin>>n>>q;
    memset(tree,0,sizeof(tree));
    ll arr[n+1];
    for(i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        arr[i]=ch-'a';
    }
    build(1,1,n,arr);
    fac[0]=1;
    for(i=1;i<=300000;i++)
        fac[i]=(i*fac[i-1])%mod;
 
    while(q--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>l>>r>>k;
            bool ans[27]={0};
            c=0;
            query(1,1,n,l,r,ans);
            for(i=0;i<=25;i++)
                if(ans[i])c++;
            r=fac[k+c-1]*power(fac[c-1],mod-2)%mod*power(fac[k],mod-2)%mod;
            cout<<r<<endl;
        }
        else
        {
            char ch;
            cin>>y>>ch;
            c=ch-'a';
            update(1,1,n,y,c,arr);
        }
    }
}