using namespace std;
#define int long long
const int mod = 1e6;
const int m = 2; // size of matrix
 
struct Matrix { 
  int mat[m][m];
  Matrix operator * (const Matrix &p) {
    Matrix ans;
    for(int i = 0; i < m; i++)
      for(int j = 0; j < m; j++)
        for(int k = ans.mat[i][j] = 0; k < m; k++)
          ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
    return ans;
  }
};

Matrix fExp(Matrix &a, int b){
    Matrix ans;
    ans.mat[0][0] = 1;
    ans.mat[0][1] = 0;
    ans.mat[1][0] = 0;
    ans.mat[1][1] = 1;
 
    while(b){
        if(b&1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }
 
    return ans;
}
