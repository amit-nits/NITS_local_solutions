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
#define mx 100005
int spf[mx];
void sieve()
{
    fl(i,0,mx)
    {
        spf[i] = i;
    }
    for (int i = 2; i < mx ; ++i)
    {
        if(spf[i]!=i)continue;
        for(ll j = 2*i ; j< mx ; j+=i)
        {
            if(spf[j] == j )
                spf[j] = i;
        }
    }
}
vector<int> v[mx];
main()
{
    fast;
    int mxn = sqrt(1e9) + 1;
    fl(i,1,mxn)
    {
        int z = sqrt(i);
        vector<int> temp;
        fl(j,1,z+1)
        {
            if(i % j != 0)
                continue;
            temp.pb(j);
            if(j != i / j)
            {
                temp.pb(i/j);
            }
        }
        fl(j,0,temp.size())
        {
            fl(k,j,temp.size())
            {       
                v[i].pb(temp[j]*temp[k]);
            }
        }
        sort(v[i].begin(), v[i].end());
        v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());
    }
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        ll val = n - 1;
        n = sqrt(n);
        ll ans = 0;
        int sz = v[n].size();
        fl(i,0,sz/2)
        {
            int x = v[n][sz - i - 1] - v[n][i];
        //  cout << x << endl;
            if(i&1)
            {
                ans -= 1LL*x*x;
            }
            else ans += 1LL*x*x;
        }
        cout << ans <<" "<<1LL*val*val - ans << endl;
    }
 
}