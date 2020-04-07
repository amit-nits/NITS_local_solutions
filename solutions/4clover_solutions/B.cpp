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
/*ll power(ll x,ll y)
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
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  ll n,i,a,b,c,m,k;
  cin>>n>>k;
  unordered_map<ll,ll>mp,mrk;
  vector<ll>v;
  for(i=0;i<n;i++)
  {
      cin>>m;
      v.pb(m);
      mp[m%k]++;
  }
  c=0;
  for(i=0;i<n;i++)
  {
      if(mrk[v[i]%k])continue;
      a=v[i]%k;
      if(a==0)
      {
          b=mp[a];
          c=c+b;
          mrk[a]=1;
          continue;
      }
      b=k-a;
      if(a==b)
      {
          c=c+(mp[a]/2);
          mrk[a]=1;
          continue;
      }
      c=c+min(mp[a],mp[b]);
      mrk[a]=1,mrk[b]=1;
  }
  cout<<c<<endl;
}