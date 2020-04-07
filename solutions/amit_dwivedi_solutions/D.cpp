#include "bits/stdc++.h"
using namespace std;using ll=long long;
void solve(){
    ll N,n; cin>>N;
    n = sqrt(N);
    set<ll> v , s;
    for (ll i = 1; i*i <= n; ++i)
    {
        if(n%i) continue;
        v.insert(i);
        v.insert(n/i);
    }
    for(auto i:v){
        for(auto j:v){
            s.insert(i*j);
        }
    }
    ll ans1 = 0 , ans2 = (N-1)*(N-1);
    for(auto i:s){
        if(i == n)
            break;
        else{
            ans2 -= (N/i - i)*(N/i - i);
            ans1 += (N/i - i)*(N/i - i);
            swap(ans1 , ans2);
        }
    }
    if(ans1 < ans2) swap(ans1 , ans2);
    cout << ans1 << " " << ans2 << '\n';
 
}
int main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);cerr.tie(0);
    int _;cin>>_;
    while(_--)
        solve();
    return 0;
}