/*
    Slow and steady    
    ai != bi
    WTF
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
#define mx 100005
int arr[mx],brr[mx],c[mx];
int h1[mx],h2[mx],h[mx];
map<int,int> mp;
ll ans = 1e18;
int n;
void solve(int x)
{
    vector<int> v1,v2;
    fl(i,1,n+1)
    {
        if(arr[i] == x)
            v1.pb(c[i]);
        else if(brr[i] == x)
            v2.pb(c[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if(v1.size() > n/2)
    {
        int y = v1.size() - n/2;
        ll sum = 0;
        fl(i,0,y)
        {
            sum += v1[i];
        }
        ans = min(ans,sum);
    }
    else if(v1.size() < n/2)
    {
        int y = n/2 - v1.size();
        ll sum = 0;
        fl(i,0,y)
        {
            sum += v2[i];
        }
        ans = min(ans,sum);
    }
    else ans = 0;
}
main()
{
    fast;
   
    cin >> n;
    fl(i,1,n+1)
    {
        cin >> arr[i] >> brr[i] >> c[i];
        mp[arr[i]]++;
        mp[brr[i]]++;
    }
    for(auto i : mp)
    {
        if(i.ss >= n/2)
        {
            solve(i.ff);
        }
    }
    if(ans == 1e18)
    {
        ans = -1;
    }
    cout << ans;
 
 
}