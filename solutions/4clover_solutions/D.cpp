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
  vector<int>v[32000];
  ll i,j,k,a,b,c;
  for(i=1;i<=32000;i++)
  {
      if(i*i>1e9)break;
      int mrk[i+1]={0};
      for(j=1;j<=sqrt(i);j++)
      {
          if(i%j==0)
          {
              v[i].pb(j);
              if(i/j!=j)v[i].pb(i/j);
              mrk[j]=1,mrk[i/j]=1;
          }
      }
      a=v[i].size();
      b=i*i;
      for(j=0;j<a;j++)
      {
          c=b/v[i][j];
          if(c>i)
          v[i].pb(c);
          for(k=j;k<a;k++)
          {
              c=v[i][j]*v[i][k];
              if(c>i)continue;
              if(mrk[c]==0)
              {
                  v[i].pb(c);
                  mrk[c]=1;
                  c=b/c;
                     if(c>i)
                      v[i].pb(c);
              }
          }
      }
  }
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      n=sqrt(n);
      sort(v[n].begin(),v[n].end());
     // for(i=0;i<v[n].size();i++)
       // cout<<v[n][i]<<" ";
      //cout<<endl;
      ll x=0,y=0,d=0;
      a=0,b=v[n].size()-1;
      while(a<b)
      {
          if(d%2==0)
          {
              c=(v[n][b]-v[n][a]);
              c=c*c;
              x=x+c;
              if(d!=0)y=y-c;
          }
          else
          {
               c=(v[n][b]-v[n][a]);
              c=c*c;
              y=y+c;
              if(d!=0)x=x-c;
          }
          a++,b--,d++;
      }
     // x=x/4,y=y/4;
      cout<<x<<" "<<y<<endl;
  }
}