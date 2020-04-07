
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
#define mx 500005
main()
{
    fast;
    map<int,int> mp;
    int n,k;
    cin >> n >> k;
    int arr[n + 1];
    fl(i,1,n+1)
    {
        cin >> arr[i];
        mp[arr[i]%k]++;
    }
    ll ans = 0;
    fl(i,1,n+1)
    {
        int x = arr[i] % k;
        int y = (k - arr[i]%k)%k;
        if(mp[x] == 0)
            continue;
        if(x == 0)
        {
            continue;
        }
        if(x == y)
        {
            if(mp[x] >= 2)
            {
                mp[x] -= 2;
                ans++;
            }
        }
        else
        {
            if(mp[y] > 0)
            {
                mp[y]--;
                mp[x]--;
                ans++;
            }
        }
    }
    ans += mp[0];
    cout << ans;
 
 
 
}