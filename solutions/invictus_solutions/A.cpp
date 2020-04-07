#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i ++) cin >> a[i];
	int ans = 1, last = a[n - 1];
	for(int i = n - 2; i >= 0; i --) {
		if(a[i] <= last) {
			last = a[i];
			ans ++;
		}
	}
	cout << ans;
	return 0;
}