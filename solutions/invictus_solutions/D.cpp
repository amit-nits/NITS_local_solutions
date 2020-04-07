#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --) {
		ll n; cin >> n;
		n = sqrt(n + 0.5);
		ll r = 0, g = 0;
		bool red = true;
		vector <ll> tmp, factors;
		for(ll i = 1; i * i <= n; i ++) {
			if(n % i == 0) {
				tmp.push_back(i);
				tmp.push_back(n / i);
			}
		}
		for(auto x : tmp) for(auto y : tmp) factors.push_back(x * y);
		sort(factors.begin(), factors.end());
		factors.erase(unique(factors.begin(), factors.end()), factors.end());
		int st = 0, en = factors.size() - 1;
		while(st <= en) {
			ll d = factors[en] - factors[st];
			if(red) {
				r += d * d;
				if(st) g -= d * d;
			}
			else {
				g += d * d;
				r -= d * d;
			}
			red ^= 1;
			st ++, en --;
		}
		cout << r << " " << g << "\n";
	}
	return 0;
}