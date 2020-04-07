#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		a[i] %= k;
	}
	sort(a, a + n);
	int st = 0, en = n - 1;
	int ans = 0;
	while(st <= en) {
		if(!a[st]) {
			ans ++;
			st ++;
		}
		else break;
	}
	while(st < en) {
		if(a[st] + a[en] == k) {
			ans ++;
			st ++;
			en --;
		}
		else if(a[st] + a[en] < k) {
			st ++;
		}
		else {
			en --;
		}
	}
	cout << ans << "\n";
	return 0;
}