ll gcd_ext(ll a, ll b, ll& x, ll& y) {
 if (b == 0) {
   x = 1, y = 0;
   return a;
 }
 ll nx, ny;
 ll gc = gcd_ext(b, a % b, nx, ny);
 x = ny;
 y = nx - (a / b) * ny;
 return gc;
}

//A * X + B * Y = gcd(A, B)
