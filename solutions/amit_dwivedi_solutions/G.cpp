#include "bits/stdc++.h"
using namespace std;using ll = long long;using ld = long double;
#define _(_1, _2, _3, _4, NAME, ...) NAME
#define f3(i, a, n, inc) for(int i = (a); (inc) > 0 ? i <= (n) : i >= (n); i += (inc))
#define f2(i, a, n) f3(i, a, n, 1 - 2*(a > n))
#define f1(i, n) f2(i, 0, n-1)
#define f0(i) f2(i, 0, n-1)
#define fr(...) _(__VA_ARGS__, f3, f2, f1 , f0)(__VA_ARGS__)
#define trav(i,x) for(auto& i: x)
#define sz(x) ((int)x.size())
#define len(x) ((int)x.length())
#define ff first
#define ss second
const int MOD = 1e9 + 7;
namespace io{ // BenQ
  template<class T> void re(complex<T>& x);
  template<class T1, class T2> void re(pair<T1,T2>& p);
  template<class T> void re(vector<T>& a);
  template<class T, size_t SZ> void re(array<T,SZ>& a);
  template<class T> void re(T& x) { cin >> x; }
  void re(double& x) { string t; re(t); x = stod(t); }
  void re(ld& x) { string t; re(t); x = stold(t); }
  template<class T, class... Ts> void re(T& t, Ts&... ts) { re(t); re(ts...);}
  template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; }
  template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
  template<class T> void re(vector<T>& a) { fr(i,sz(a)) re(a[i]); }
  template<class T, size_t SZ> void re(array<T,SZ>& a) { fr(i,SZ) re(a[i]); }
  void pr(int x) { cout << x; }
  void pr(long x) { cout << x; }
  void pr(ll x) { cout << x; }
  void pr(unsigned x) { cout << x; }
  void pr(unsigned long x) { cout << x; }
  void pr(unsigned long long x) { cout << x; }
  void pr(float x) { cout << x; }
  void pr(double x) { cout << x; }
  void pr(ld x) { cout << x; }
  void pr(char x) { cout << x; }
  void pr(const char* x) { cout << x; }
  void pr(const string& x) { cout << x; }
  void pr(bool x) { pr(x ? "true" : "false"); }
  template<class T> void pr(const complex<T>& x) { cout << x; }
  template<class T1, class T2> void pr(const pair<T1,T2>& x);
  template<class T> void pr(const T& x);
  template<class T, class... Ts> void pr(const T& t, const Ts&... ts){pr(t); pr(ts...); }
  template<class T1, class T2> void pr(const pair<T1,T2>& x) { pr("{",x.f,", ",x.s,"}"); }
  template<class T> void pr(const T& x) { pr("{");bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; pr("}");}void ps() { pr("\n"); }
  template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); }void pc() { pr("]\n"); } // debug w/ commas
  template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); }
}using namespace io;
struct mi {
    typedef decay<decltype(MOD)>::type T;
    T v; 
    explicit operator T() const { return v; }
    mi() { v = 0; }
    mi(ll _v) { 
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mi& a, const mi& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) { 
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { 
        return a.v < b.v; }
    friend void re(mi& a) { ll x; re(x); a = mi(x); }
    friend void pr(const mi& a) { pr(a.v); }
    friend ostream& operator<<(ostream& os, const mi& a) { 
        return os << a.v; }
   
    mi operator-() const { return mi(-v); }
    mi& operator+=(const mi& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mi& operator-=(const mi& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
 
    mi& operator*=(const mi& m) { 
        v = (ll)v*m.v%MOD; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { 
        assert(a.v != 0); return pow(a,MOD-2); }
};
template<class T> struct Mat {
    int r,c;
    vector<vector<T>> d;
    Mat(int _r, int _c) : r(_r), c(_c) { 
        d.assign(r,vector<T>(c)); }
    Mat() : Mat(0,0) {} 
    Mat(const vector<vector<T>>&_d) : 
        r(sz(_d)), c(sz(_d[0])) { d = _d; }
    /// friend void pr(const Mat& m) { pr(m.d); }
    Mat& operator+=(const Mat& m) {
        /// assert(r == m.r && c == m.c);
        fr(i,r) fr(j,c) d[i][j] += m.d[i][j];
        return *this; }
    Mat& operator-=(const Mat& m) {
        /// assert(r == m.r && c == m.c);
        fr(i,r) fr(j,c) d[i][j] -= m.d[i][j];
        return *this; }
    Mat operator*(const Mat& m) {
        assert(c == m.r); Mat x(r,m.c);
        fr(i,r) fr(j,c) fr(k,m.c) 
            x.d[i][k] += d[i][j]*m.d[j][k];
        return x; }
    Mat operator+(const Mat& m) { return Mat(*this)+=m; }
    Mat operator-(const Mat& m) { return Mat(*this)-=m; }
    Mat& operator*=(const Mat& m) { return *this = (*this)*m; }
    friend Mat pow(Mat m, ll p) {
        /// assert(m.r == m.c);
        Mat res(m.r,m.c); fr(i,m.r) res.d[i][i] = 1;
        for (; p; p /= 2, m *= m) if (p&1) res *= m;
        return res;
    }
};
 
main(){
    int N , M , Q;
    cin>>N>>M>>Q;
    Mat<mi>  m(N , N);
    for(int i =0; i < M; ++i){
        int u,v; cin>>u>>v;
        u-- , v--;
        m.d[u][v] = 1;
    } 
    vector<pair<pair<int, int>, pair<int, int>>> query;
    for (ll i = 0 , u , v, k; i < Q; ++i)
    {
        cin>>u>>v>>k;
        u-- , v--;
        query.push_back({{k,i} , {u,v}});
    }
 
    sort(query.begin(), query.end());
    vector<ll> ans(Q);
    ll ktill = 0;
    Mat<mi> res = pow(m,0);
    vector<mi> row(N,1);
    for (int i = 0 , k , id , u , v; i < Q; ++i)
    {
        k = query[i].ff.ff;id = query[i].ff.ss;u = query[i].ss.ff , v = query[i].ss.ss;
        if(k > ktill){
            res =  pow(m,k);
            for (int j = 0; j < N; ++j)
            {
                row[j] = 0;
            }
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    row[j] += res.d[j][k];                
                }
            }
            ktill = k;
        }
        if(row[u].v == 0) 
            ans[id] = 0; 
        else
            ans[id] = (res.d[u][v]/row[u]).v;
    }
    for (int i = 0; i < Q; ++i)
    {
        cout << (ans[i]) << endl;
    }
 
}