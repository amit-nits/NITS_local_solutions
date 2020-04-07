#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAX = 2e5 + 100;
ll fact[MAX];
void calculate() {
	fact[0] = 1;
	for(int i = 1; i < MAX; i ++) fact[i] = (fact[i - 1] * i) % MOD;
}
string s;
struct SegmentTree {
	int n;
	vector <ll> tree;
	SegmentTree(int n) :
		n(n), tree(4 * n) {}
	void build(int i, int st, int en) {
		if(st == en) {
			tree[i] = 1LL << (s[st] - 'a');
			return;
		}
		int mid = (st + en) / 2;
		build(2 * i, st, mid);
		build(2 * i + 1, mid + 1, en);
		tree[i] = tree[2 * i] | tree[2 * i + 1];
	}
	void update(int i, int st, int en, int idx, char val) {
		if(st == en) {
			tree[i] = 1LL << (val - 'a');
			return;
		}
		int mid = (st + en) / 2;
		if(idx <= mid) update(2 * i, st, mid, idx, val);
		else update(2 * i + 1, mid + 1, en, idx, val);
		tree[i] = tree[2 * i] | tree[2 * i + 1];
	}
	ll query(int i, int st, int en, int l, int r) {
		if(en < l || st > r) return 0;
		if(l <= st && en <= r) return tree[i];
		int mid = (st + en) / 2;
		return query(2 * i, st, mid, l, r) | query(2 * i + 1, mid + 1, en, l, r);
	}
};
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
ll nCr(ll n, ll r) {
	return (fact[n] * modInverse(fact[n - r]) % MOD * modInverse(fact[r]) % MOD) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	calculate();
	int n, q;
	cin >> n >> q;
	SegmentTree seg(n + 1);
	cin >> s;
	seg.build(1, 0, n - 1);
	while(q --) {
		int c; cin >> c;
		if(c == 2) {
			int i; char ch;
			cin >> i >> ch;
			seg.update(1, 0, n - 1, i - 1, ch);
		}
		else {
			int l, r, k;
			cin >> l >> r >> k;
			int x = __builtin_popcountll(seg.query(1, 0, n - 1, l - 1, r - 1));
			cout << nCr(k + x - 1, x - 1) << "\n";
		}
	}
	return 0;
}