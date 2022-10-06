typedef unsigned long long ull;

struct StringHashing {
  const ull MOD = (1LL << 61) - 1;
  const int base = 31;
  vector<ull> h, p;

  ull modMul(ull a, ull b) {
    ull l1 = (unsigned int)a, h1 = a >> 32, l2 = (unsigned int)b, h2 = b >> 32;
    ull l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    ull ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + ((m << 35) >> 3) + 1;
    ret = (ret & MOD) + (ret >> 61);
    ret = (ret & MOD) + (ret >> 61);
    return ret - 1;
  }

  ull getKey(int l, int r) {  // [l, r]
    ull res = h[r];
    if(l > 0) res = (res + MOD - modMul(p[r - l + 1], h[l - 1])) % MOD;
    return res;
  }

  ull getInt(char c) {
    return c - 'a' + 1;
  }

  StringHashing(string &s) {
    int n = s.size();
    h.resize(n);
    p.resize(n);
    p[0] = 1;
    h[0] = getInt(s[0]);
    for(int i = 1; i < n; ++i) {
      p[i] = modMul(p[i - 1], base);
      h[i] = (modMul(h[i - 1], base) + getInt(s[i])) % MOD;
    }
  }
};
