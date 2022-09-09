#include <bits/stdc++.h>

using namespace std;
const double inf = 1e100, eps = 1e-12;
const double PI = acos(-1.0L);

int cmp (double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}

struct pt{ //Struct de ponto/vetor com algumas operações básicas
    double x, y;

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

//Isso é para debuggar, aqui já printa os pontos bonitinhos e formatados
ostream& operator<<(ostream& os, pt p) { 
return os << "("<< p.x << "," << p.y << ")";
}

//Para transladar um ponto em uma direção v, basta somar o vetor na direção que queremos fazer a translação =D
pt translate(pt v, pt p) {return p+v;} 

//Aqui é para escalonar algo a um fato  r alpha em relação a um ponto c
pt scale(pt c, double factor, pt p) { //
    return c + (p-c)*factor;
}

//Para rotacionar um ponto em relação a origem
pt rot(pt p, double a) {
    return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

double dot(pt a, pt b){
    return a.x * b.x + a.y * b.y;
}

double cross(pt a, pt b){
    return a.x * b.y - a.y * b.x;
}

//Calcula a orientação do de 3 pontos, se for positivo significa que os pontos estão no sentido antihorário, 0 são colineares e negativo é horário
double orient(pt a, pt b, pt c){
    return cross(b-a, c-a);
}

double angle(pt a, pt b){
    return atan2(cross(a, b), dot(a, b));
}

bool isConvex(vector <pt> polygon){
    bool hasPos = false, hasNeg = false;
    int n = polygon.size();

    for(int i = 0; i < polygon.size(); i++){
        int o = orient(polygon[i], polygon[(i+1)%n], polygon[(i+2)%n]);

        if(o > 0) hasPos = true;
        if(o < 0) hasNeg = true;
    }

    return !(hasPos && hasNeg);
}

