// brute
#include "bits/stdc++.h"
using namespace std;using ll = long long;using ld = long double;
vector<int> a;
main(){
    int N , temp;scanf("%d",&N);
    stack<int> s;
    for (int i = 0; i < N; ++i)
    {
        scanf("%d" , &temp);
        while(!s.empty() and temp < s.top())
            s.pop();
        s.push(temp);
    }
    printf("%d\n", s.size());
}