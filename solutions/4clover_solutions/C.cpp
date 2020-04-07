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
  ll n,i,a,b,c,m,k,r,d,x,y,j;
  cin>>n;
  vector<ll>v[2*n+1],v1,v2[2*n+1];
  unordered_map<ll,ll>mp,cnt,cnt1,mp1;
  x=0,y=0;
  for(i=1;i<=n;i++)
  {
      cin>>a>>b>>c;
      cnt[a]++,cnt1[a]++,cnt[b]++;
      if(mp[b])v[mp[b]].pb(c);
      else
      {
          x++;
          mp[b]=x;
          v[mp[b]].pb(c);
      }
      if(mp1[a])v2[mp1[a]].pb(c);
      else
      {
          y++;
          mp1[a]=y;
          v2[mp1[a]].pb(c);
      }
      if(cnt[a]==n/2)v1.pb(a);
      if(cnt[b]==n/2)v1.pb(b);
  }
  r=inf;
  if(v1.size()==0)
  {
      cout<<-1<<endl;
      return 0;
  }
  for(i=0;i<v1.size();i++)
  {
      a=v1[i];
      sort(v[mp[a]].begin(),v[mp[a]].end());
      b=mp[a];
      c=(n/2)-cnt1[a];
      d=0,x=0;
      if(c<0)
      {
          b=mp1[a];
          sort(v2[b].begin(),v2[b].end());
          c=abs(c);
          for(j=0;j<v2[b].size();j++)
          {
              if(d==c)break;
              x=x+v2[b][j];
              d++;
          }
          r=min(r,x);
          continue;
      }
      for(j=0;j<v[b].size();j++)
      {
          if(d==c)break;
          x=x+v[b][j];
          d++;
      }
      r=min(r,x);
  }
  cout<<r<<endl;
}