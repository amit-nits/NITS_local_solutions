#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 26;
const ll MOD = 1e9 + 7;
ll adj[MAX][MAX], tmp[MAX][MAX];
void MatMul(ll M1[MAX][MAX], ll M2[MAX][MAX], ll M3[MAX][MAX]) {
	ll temp[MAX][MAX] = {0};
	for(int i = 0; i < MAX; i ++) {
		for(int j = 0; j < MAX; j ++) {
			for(int k = 0; k < MAX; k ++) {
				temp[i][j] = (temp[i][j] + M1[i][k] * M2[k][j]) % MOD;
			}
		}
	}
	for(int i = 0; i < MAX; i ++) {
		for(int j = 0; j < MAX; j ++) {
			M1[i][j] = temp[i][j];
		}
	}
}
void MatExp(ll mat[MAX][MAX], ll p) {
	ll I[MAX][MAX] = {0};
	for(int i = 0; i < MAX; i ++) {
		I[i][i] = 1;
	}
	while(p > 0) {
		if(p & 1) {
			MatMul(I, mat, I);
		}
		MatMul(mat, mat, mat);
		p >>= 1;
	}
	for(int i = 0; i < MAX; i ++) {
		for(int j = 0; j < MAX; j ++) {
			mat[i][j] = I[i][j];
		}
	}
}
ll modExp(ll b, ll p) {
	ll res = 1;
	while(p > 0) {
		if(p & 1) {
			res = (res * b) % MOD;
		}
		b = (b * b) % MOD;
		p >>= 1;
	}
	return res;
}
ll modInverse(ll n) {
	return modExp(n, MOD - 2); 
}
map <ll, vector <vector <int>>> Q;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] += 1;
	}
	for(int i = 0; i < q; i ++) {
		int u, v; ll k;
		cin >> u >> v >> k;
		Q[k].push_back({u, v, i});
	}
	ll ans[q];
	for(auto p : Q) {
		for(int i = 0; i < MAX; i ++) for(int j = 0; j < MAX; j ++) tmp[i][j] = adj[i][j];
		MatExp(tmp, p.first);
		for(auto r : p.second) {
			int u = r[0], v = r[1], id = r[2];
			if(p.first == 0) {
				if(u == v) ans[id] = 1;
				else ans[id] = 0;
				continue;
			}
			ll num = tmp[u][v], den = 0;
			for(int i = 0; i < MAX; i ++) den = (den + tmp[u][i]) % MOD;
			ll g = __gcd(num, den);
			num /= g, den /= g;
			num = (num * modInverse(den)) % MOD;
			ans[id] = num;
		}
	}
	for(int i = 0; i < q; i ++) cout << ans[i] << "\n";
	return 0;
}