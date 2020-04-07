
/*
    Slow and steady    
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
#define mod 998244353 
#define inf 4e18
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define mx 400005
solve()
{
    int n,l;
    cin >> n >> l;
    vector<int> v[l+1];
    multiset<int> s;
    fl(i,1,n+1)
    {
        int a,b;
        cin >> a >> b;
        v[a].pb(b);
    }
    int cur = mx, val = mx;
    int ans = 0;
    fl(i,1,l+1)
    {
        if(cur == i - 1)
        {
            ans++;
            cur = mx;
            val = mx;
        }
        for(auto j : v[i])
        {
            s.insert(j);
        }
        if(s.size() == 0)
        {
            continue;
        }
        int x = *s.begin();
        int y = i + x - 1;
        if(y < cur)
        {
            s.erase(s.begin());
            s.insert(cur - i + 1);
            cur = y;
            val = x;
        }
    }
    if(cur == l)
        ans++;
    cout << ans << endl;
    
}
main()
{
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}