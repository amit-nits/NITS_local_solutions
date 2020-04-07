/*
Author: amit_dwivedi
Time: 19:35 (02/02/2020) 
*/
#include "bits/stdc++.h"
using namespace std;
using ll = long long int; using ld = long double;
const ll N = 2e5+1;
 
// All Modular Operations, Factorial , Inverse Factorial , nCr in O(n.log(n))  
const ll MAX = 1e6 + 5 , MOD = 1e9 + 7;
vector<ll> fact(MAX,1),invp(MAX,1);
ll add(ll a, ll b, ll c = MOD){ll res=a+b;return(res>=c?res-c:res);}
ll sub(ll a, ll b, ll c = MOD){ll res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
ll mul(ll a, ll b, ll c = MOD){long long res=(long long)a*b;return(res>=c?res%c:res);}
template<typename T>T power(T e, T n, T m = MOD){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n = MOD){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:sub(x,z,n));}
void init() {
    fact[0] = invp[0] = 1;
    fact[1] = 1ll;
    invp[1] = mod_inverse(fact[1]);
    for (ll i = 2; i < MAX; ++i) {
        fact[i] = mul(fact[i-1], i);
        invp[i] = mod_inverse(fact[i]);
    }
}
inline ll ncr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return mul(fact[n], mul(invp[n-r], invp[r]));
}
 
template<class T> struct Seg { 
    const T ID = 0; // comb(ID,b) must equal b
    T comb(T a, T b) { return a|b; } 
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T value) {  // set value at position p
        seg[p += n] = value;
        for (p /= 2; p; p /= 2) pull(p);
    }
    T query(int l, int r) {  // sum on interval [l, r]
        T ra = ID, rb = ID; 
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n , q;
    init();
    cin>>n >> q;
    string s;
    cin>>s;
    Seg<ll> st;
    st.init(n + 1);
    // building the segment tree
    for (int i = 0; i < n; ++i)
        st.seg[i+ n] = 1ll<<(s[i] - 'a'); 
    
    for(int i = n-1; i > 0 ; i--) st.pull(i);
    while(q--){
        int type; cin>>type;
        if(type == 1){
            ll l , r , k;
            cin>>l>>r>>k;
            ll z = st.query(l,r);
            int x = __builtin_popcountll(z);
            // x distinct character in the range we have to make a string of size k. combination  with repeatation.
            cout << ncr(x + k - 1 , x-1) << "\n";
        }
        else{
            int p ;
            char c;
            cin>>p>>c;
            st.upd(p,1ll<<(c-'a'));
        }
    }
}