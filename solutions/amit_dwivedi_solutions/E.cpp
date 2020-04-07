#include "bits/stdc++.h"
using namespace std;using ll = long long;
const int N = 1001 , INF = 1e9;
int n , l , dp[N][N],T;
pair<int, int> a[N];
int calc(int pos , int tim){ // pos , tim
    if(pos > n || tim > l+1) // last transition was invalid
        return -INF;
    if(pos == n && tim == l+1) // end of recursion
        return 0;
    int &ret = dp[pos][tim];
    if(ret != -1) // already calulated
        return ret;
    ret = max(calc(pos,tim+1),calc(pos+1,tim)); // max(dont start anything now we will take this pos later, ignore this pos) 
    if(tim >= a[pos].first)
        ret = max(ret,1+calc(pos+1,tim+a[pos].second));
    return ret;
}
int main(){
    cin >> T;
    while(T--){
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&n,&l);
        for (int i = 0; i < n; ++i)
            scanf("%d%d",&a[i].first,&a[i].second);
        sort(a , a+n);
        printf("%d\n",calc(0,1));
    }
    return 0;
}