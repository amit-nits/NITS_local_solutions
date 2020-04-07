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
int dp[30][30][62];
int cnt[30][30][62];
int mat[30][30];
map<ll,vector<vector<int> > > mp;
main()
{
    fast;
    int n,m,q;
    cin >> n >> m >> q;
    fl(i,1,m+1)
    {
        int x,y;
        cin >> x >> y;
        mat[x][y] = 1;
        dp[x][y][0] = 1;
        cnt[x][y][0] = 1;
    }
    fl(d,1,62)
    {
        fl(i,1,n+1)
        {
            fl(j,1,n+1)
            {
                fl(k,1,n+1)
                {
                    cnt[i][j][d] = add(cnt[i][j][d],mul(cnt[i][k][d-1],cnt[k][j][d-1]));
                }
                
            }
        }
    }
    while(q--)
    {
        ll x,y,k;
        cin >> x >> y >> k;
        vector<vector<int> > dp2(30,vector<int>(30)),dp3(30,vector<int>(30));
        if(mp.find(k) != mp.end())
        {
            goto last;
        }
        fl(i,1,n+1)
        {
            fl(j,1,n+1)
            {
                dp2[i][j] = 0;
                dp3[i][j] = 0;
            }
            dp2[i][i] = 1;
        }
        for(int i = 61; i >= 0 ; i--)
        {
            if(k >> i & 1)
            {
                fl(a,1,n+1)
                {
                    fl(b,1,n+1)
                    {
                        fl(c,1,n+1)
                        {
                            dp3[a][b] = add(dp3[a][b],mul(dp2[a][c],cnt[c][b][i]));
                        }
                    }
                }
                fl(a,1,n+1)
                {
                    fl(b,1,n+1)
                    {
                        dp2[a][b] = dp3[a][b];
                        dp3[a][b] = 0;
                    }
                }
            }
        }
        mp[k] = dp2;
 
        last :;
               dp2 = mp[k];
        ll ans = 0;
        fl(i,1,n+1)
        {
            ans = add(ans,dp2[x][i]);
        }
        ll num = dp2[x][y];
        cout << mul(num,invmod(ans)) << endl;
    }
 
 
}