#include <bits/stdc++.h>

using namespace std;
#define int long long

//Remainer : x ^ (phi (mod)) = 1 (mod)

int phi(int n){ //To calculate one totient
    int ans = n;
    for(int i=2; i*i <= n; i++){
        if((n%i) == 0) {
            ans -= ans/i;
            while(n % i == 0) n/= i;
        }
    }

    if(n>1){
        ans -= ans/n;
    }

    return ans;
}

void PHI(){ //sieve for phi
  for(int i=1; i<= P; i++) phi[i] = i;
 
  for(int i=2; i<=P; i++){
    if(phi[i] == i){
      for(int j = i; j<=P; j++){
        phi[j] = phi[j]/(i*(i-1)); //NEED DEBUGGING / MIGHT BE WRONG
      }
    }
  }
}
