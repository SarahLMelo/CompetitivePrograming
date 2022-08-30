#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod =  1e9 + 7;

ll fexp(ll a, ll b){
  ll ans = 1;
  
  while(b){
    if(b & 1) ans = ans * a % mod;
    
    a = a * a % mod;
    b >>= 1;
  }
  
  return ans;
}
