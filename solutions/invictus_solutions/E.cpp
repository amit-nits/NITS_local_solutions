#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1005;
vector <pair <int, int>> v;
int n, l, dp[MAX][MAX];
int solve(int tim, int id) {
	if(tim > l || id > n - 1) return 0;
	if(dp[id][tim]) return dp[id][tim];
	if(v[id].first > tim) return dp[id][tim] = solve(v[id].first, id);
	if(tim + v[id].second - 1 > l) return dp[id][tim] = solve(tim, id + 1);
	return dp[id][tim] = max(solve(tim, id + 1), 1 + solve(tim + v[id].second, id + 1));
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --) {
		for(int i = 0; i < MAX; i ++) for(int j = 0; j < MAX; j ++) dp[i][j] = 0;
		v.clear();
		cin >> n >> l;
		for(int i = 0; i < n; i ++) {
			int a, b;
			cin >> a >> b;
			v.push_back({a, b});
		}
		sort(v.begin(), v.end());
		cout << solve(0, 0) << "\n";
	}
	return 0;
}