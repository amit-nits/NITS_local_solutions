#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()
map <int, vector <int>> f0, f1;
set <int> val;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		f0[a].push_back(c);
		f1[b].push_back(c);
		val.insert(a);
		val.insert(b);
	}
	for(auto &p : f0) sort(all(p.second));
	for(auto &p : f1) sort(all(p.second));
	ll ans = INF;
	for(int x : val) {
		int l0 = f0[x].size(), l1 = f1[x].size();
		if(l0 + l1 < n / 2) continue;
		ll temp = 0;
		if(l0 == n / 2) {
			ans = 0;
			break;
		}
		if(l0 < n / 2) {
			int i = 0;
			while(l0 < n / 2) {
				temp += f1[x][i ++];
				l0 ++;
			}
			ans = min(ans, temp);
		}
		else {
			int i = 0;
			while(l0 > n / 2) {
				temp += f0[x][i ++];
				l0 --;
			}
			ans = min(ans, temp);
		}
	}
	cout << (ans == INF? -1 : ans);
	return 0;
}