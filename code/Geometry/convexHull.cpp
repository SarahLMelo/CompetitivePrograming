#include <bits/stdc++.h>

using namespace std;
#define int long long
const double inf = 1e100, eps = 1e-12;
const double PI = acos(-1.0L);

int cmp (double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}

struct pt{ //Struct de ponto/vetor com algumas operações básicas
    int x, y;

    pt (double x = 0, double y = 0) : x(x), y(y) {}
    pt operator+ (const pt &p){ return pt(x + p.x, y + p.y); }
    pt operator- (const pt &p){ return pt(x - p.x, y - p.y); }
    pt operator* (const double &c){ return pt(c*x, c*y); }
    pt operator/ (const double &c){ return pt(x/c, y/c); }

    bool operator <(const pt &p) const {
        if(cmp(x, p.x) != 0) return x < p.x;
        return cmp(y, p.y) < 0;
    }

    bool operator == (const pt &p){ return !cmp(x, p.x) && !cmp(y, p.y); }
    bool operator != (pt &p) const {return !(p == *this);}

};

ostream& operator<<(ostream& os, pt p) { 
return os << "("<< p.x << "," << p.y << ")";
}

double dot(pt a, pt b){
    return a.x * b.x + a.y * b.y;
}

double cross(pt a, pt b){
    return a.x * b.y - a.y * b.x;
}

vector<pt> convexHull(vector<pt> p, bool needs = 1) {

  if(needs) sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());

  int n = p.size(), k = 0;
  if(n <= 1) return p;
  vector<pt> h(n + 2); // se der wa bota n*2

  for(int i = 0; i < n; i++) {
    while(k >= 2 && cross(h[k - 1] - h[k - 2], p[i] - h[k - 2]) < 0) k--;
    h[k++] = p[i];
  }

  for(int i = n - 2, t = k + 1; i >= 0; i--) {
    while(k >= t && cross(h[k - 1] - h[k - 2], p[i] - h[k - 2]) < 0) k--;
    h[k++] = p[i];
  }

  h.resize(--k); // n+1 points where the first is equal to the last
  return h;
}
int32_t main(){
    int n;
    cin >> n;
    vector <pt> points;

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;

        points.push_back(pt(x, y));
    }

    vector <pt> ans = convexHull(points);

    cout << ans.size() << "\n";
    for(auto i:ans)
        cout << i.x << " " << i.y << "\n";

    return 0;
}
