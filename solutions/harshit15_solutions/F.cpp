/*
    R_K_C IS GOD _/\_
*/
#include <bits/stdc++.h> 
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ff first
#define ss second
#define mod 1000000007 
#define inf 4e18
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define mx 1000005
#define mx2 200005
ll fact[mx];
inline int add(int x,int y)
{
    if(x + y >= mod)
        return x + y - mod;
    return x + y;
}
inline int sub(int x,int y)
{
    if(x - y < 0)
        return x - y + mod;
    return x - y;
}
inline int mul(int x,int y)
{
    return 1LL * x * y % mod;
}
ll power(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y&1)
            res = res * x % mod;
        y >>= 1;
        x = x*x%mod;
    }
    return res;
}
ll invmod(ll x)
{
    return power(x,mod-2);
}
int ncr(int n,int r)
{
    if(n < r)
        return 0;
    return mul(fact[n],invmod(mul(fact[r],fact[n-r])));
}
void facts()
{
    fact[0] = 1;
    fl(i,1,mx)
    {
        fact[i] = mul(fact[i-1],i);
    }
}
int tree[4*mx2];
string s;
int L,R,val;
 
void update(int l,int r,int id)
{
    if(L>r || R<l) return ;
    if(L<=l && r<=R)
    {
        tree[id] = val;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,2*id);
    update(mid+1,r,2*id+1);
    tree[id] = tree[2*id]|tree[2*id+1];
}
 
int query(int l,int r,int id)
{
    if(L>r || R<l) return 0;
    if(L<=l && r<=R)
    {
        return tree[id];
    }
    int mid = (l+r)/2;
    return query(l,mid,2*id)|query(mid+1,r,2*id+1);
}
main()
{
    fast;
    facts();
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    fl(i,0,n)
    {
        int x = s[i] - 'a';
        L=R=i+1;
        val = (1<<(s[i]-'a'+1));
        update(1,n,1);
    }
    while(q--)
    {
        int t;
        cin>>t;
        if(t==2)
        {
            cin>>L;
            R = L;
            char c;
            cin>>c;
            val = (1<<(c-'a'+1));
            update(1,n,1);
        }
        else
        {
            int y;
            cin>>L>>R>>y;
            int x = __builtin_popcount(query(1,n,1));
            cout<<ncr(x + y - 1,y) << endl;
        }
    }
 
}