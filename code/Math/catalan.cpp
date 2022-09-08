/*
Uses of catalan number:
*Cn is the number of Dyck words[2] of length 2n. A Dyck word is a string consisting of n X's and n Y's such that no initial segment of the string has more Y's than X's.
*Cn is the number of different ways n + 1 factors can be completely parenthesized (or the number of ways of associating n applications of a binary operator, as in the matrix chain multiplication problem).
*A convex polygon with n + 2 sides can be cut into triangles by connecting vertices with non-crossing line segments (a form of polygon triangulation). The number of triangles formed is n and the number of different ways that this can be achieved is Cn.
*Cn is the number of permutations of {1, ..., n} that avoid the permutation pattern 123 (or, alternatively, any of the other patterns of length 3); that is, the number of permutations with no three-term increasing subsequence. For n = 3, these permutations are 132, 213, 231, 312 and 321. For n = 4, they are 1432, 2143, 2413, 2431, 3142, 3214, 3241, 3412, 3421, 4132, 4213, 4231, 4312 and 4321.
*Cn is the number of ways to tile a stairstep shape of height n with n rectangles.
*C_{n} is the number of length n sequences that start with 1 {\displaystyle 1} 1, and can increase by either 0 {\displaystyle 0} {\displaystyle 0} or 1 {\displaystyle 1} 1, or decrease by any number (to at least 1 {\displaystyle 1} 1). For n = 4 {\displaystyle n=4} n=4 these are 1234 , 1233 , 1232 , 1231 , 1223 , 1222 , 1221 , 1212 , 1211 , 1123 , 1122 , 1121 , 1112 , 1111 {\displaystyle 1234,1233,1232,1231,1223,1222,1221,1212,1211,1123,1122,1121,1112,1111} {\displaystyle 1234,1233,1232,1231,1223,1222,1221,1212,1211,1123,1122,1121,1112,1111}. 
*/

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 2*(1e6 + 5);
long long fat[MAXN];

int fExp(long long a, long long b){
    long long ans = 1;

    while(b){
        if(b & 1) ans = ans * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return ans;
}

long long inv(int n){ return fExp(n, mod - 2); }

int choose(int n, int k){
    return (fat[n] * (inv(fat[n-k]) * inv(fat[k]) % mod)) % mod;
}

long long catalan(int n){
    return (choose((2*n), n) * inv(n+1)) % mod;
}

void init(){
    fat[0] = 1;
    fat[1] = 1;

    for(int i=2; i<MAXN ; i++){
        fat[i] = (i * fat[i-1]) % mod;
    }
}
