/*
    Slow and steady    
*/
#include <bits/stdc++.h> 
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ff first
#define ss second
#define mod 998244353 
#define inf 4e18
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define mx 8005
main()
{
    fast;
    int n;
    cin >> n;
    stack<int> st;
    st.push(0);
    fl(i,1,n+1)
    {
        int x;
        cin >> x;
        while(st.top() > x)
        {
            st.pop();
        }
        st.push(x);
    }
    cout << st.size() - 1;
}