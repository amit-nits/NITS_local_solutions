#include "bits/stdc++.h"
using namespace std;using ll = long long;
int a[100001];
int main()
{
    int n,k;
    scanf("%d %d",&n ,&k);
    map<int, int> mp;
    int ans1 = 0 , ans2 = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",a + i);
        a[i]%=k;
        if(a[i])
            mp[a[i]]++;
        else
            ans1++;
    }
    for(auto i:mp){
        ans2 += min(i.second , mp[k - i.first]); 
    }
    printf("%d\n",ans1 + ans2/2 );
    return 0;
}