#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
  
    int T = 1;
    while(T--) {
        ll a,b;
        cin>>a;
        cin>>b;
        ll g = __gcd(a,b);
        ll l = (a/g)*b*1ll;
        cout<<g<<" "<<l;
    }

    return 0;
}