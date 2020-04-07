#include "bits/stdc++.h"
using namespace std;using ll=long long;
#define sz(x) ((int)x.size())
 
const int MX = 1e5+1;
ll a[MX] , b[MX] , c[MX];
map<ll , multiset<ll>> mp1 , mp2;
set<ll> exist;
void solve(){
    ll N; scanf("%lld",&N);
    for (ll i = 0; i < N; ++i)
    {
        scanf("%lld%lld%lld",&a[i] , &b[i] , &c[i]);
        mp1[a[i]].insert(c[i]); // multiset as a min - heap
        mp2[b[i]].insert(c[i]);
        exist.insert(a[i]);
        exist.insert(b[i]);
    }
    ll ans = 1e18;
    for(auto i : exist){
        if(sz(mp1[i]) + sz(mp2[i]) < N/2)
            continue;
        if(sz(mp1[i]) == N/2){
            printf("0");
            return;
        }
        else if(sz(mp1[i]) > N/2){
            ll anshere = 0 , id = 0 , rem = sz(mp1[i]) - N/2;
            for(auto i:mp1[i]){
                anshere += i;
                if(++id == rem)
                    break;
            }
            ans = min(ans , anshere);
        }
        else{
            int rem = N/2 - sz(mp1[i]);
            ll anshere = 0 , id = 0;
            for(auto i:mp2[i]){
                anshere += i;
                if(++id == rem)
                    break;
            }
            ans = min(ans , anshere);
        }
    }
    if(ans == (ll)1e18)
        printf("-1");
    else
        printf("%lld", ans);
 
 
 
 
}
int main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);cerr.tie(0);
    // int _;cin>>_;while(_--)
        solve();
    return 0;
}