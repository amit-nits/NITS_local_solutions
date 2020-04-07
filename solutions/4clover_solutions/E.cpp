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
  ll t;
  cin>>t;
  while(t--)
  {
      ll n,l,a,b,c,i,j;
      cin>>n>>l;
      vector<pair<ll,ll> >v;
      ll dp[l+1]={0};
      for(i=1;i<=n;i++)
      {
          cin>>a>>b;
          if(a+b-1>l)continue;
          v.pb({a,b});
      }
      sort(v.begin(),v.end());
      for(i=0;i<v.size();i++)
      {
          for(j=l-v[i].ss+1;j>=v[i].ff;j--)
          {
              dp[j+v[i].ss-1]=max(dp[j+v[i].ss-1],1+dp[j-1]);
          }
      }
      cout<<*max_element(dp,dp+l+1)<<endl;
  }
}
