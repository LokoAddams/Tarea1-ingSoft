#include <bits/stdc++.h>
using namespace std;

//IMPRESINDIBLES PARA ICPC
#define form(i, s, e) for(int i = s; i < e; i++)
#define icin(x)  \
  int x;         \
  cin >> x;
#define llcin(x) \
  long long x;   \
  cin >> x;
#define scin(x)  \
string x;        \
cin >> x;
#define endl '\n'
#define S second
#define F first
#define pb push_back
#define sz(x) x.size()
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const ll INF =  1e9+7;//tambien es primo
const double PI = acos(-1);
//UTILES
#define DBG(x) cerr << #x << '=' << (x) << endl
#define coutDouble cout << fixed << setprecision(17)
#define numtobin(n) bitset<32>(n).to_string()
#define bintoint(bin_str) stoi(bin_str, nullptr, 2)  // bin_str should be a STRING
#define LSOne(S) ((S) & -(S))

typedef double db;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,bool> pib;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef vector<pll> vpll;




int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  icin(n) icin(m);
  char p;
  int x, y, j, ax, ay;
  vector<vector<bool>> t(n, vector<bool>(n, false));
  
  for(int i = 0; i < m; i++) {
    cin >> p >> x >> y;
    x--;
    y--;
    if(p == 'Q') {
      ax = x;
      ay = y;
      while((ax > -1 and ax < n) and (ay > -1 and ay < n)) {
        t[ax][ay] = true;
        ax++;
        ay++;
      }
      ax = x;
      ay = y;
      while((ax > -1 and ax < n) and (ay > -1 and ay < n)) {
        t[ax][ay] = true;
        ax--;
        ay++;
      }
      ax = x;
      ay = y;
      while((ax > -1 and ax < n) and (ay > -1 and ay < n)) {
        t[ax][ay] = true;
        ax++;
        ay--;
      }
      ax = x;
      ay = y;
      while((ax > -1 and ax < n) and (ay > -1 and ay < n)) {
        t[ax][ay] = true;
        ax--;
        ay--;
      }
      for(j = 0; j < n; j++) {
        t[x][j] = true;
        t[j][y] = true;
      }
    }
    else if(p == 'N') {
      ax = x+2;
      ay = y+1;
      if((ax > -1 and ax < n) and (ay > -1 and ay < n)) t[ax][ay] = true;
      ax = x-2;
      ay = y+1;
      if((ax > -1 and ax < n) and (ay > -1 and ay < n)) t[ax][ay] = true;
      ax = x+2;
      ay = y-1;
      if((ax > -1 and ax < n) and (ay > -1 and ay < n)) t[ax][ay] = true;
      ax = x-2;
      ay = y-1;
      if((ax > -1 and ax < n) and (ay > -1 and ay < n)) t[ax][ay] = true;
      ax = x+1;
      ay = y+2;
      if((ax > -1 and ax < n) and (ay > -1 and ay < n)) t[ax][ay] = true;
      ax = x+1;
      ay = y-2;
      if((ax > -1 and ax < n) and (ay > -1 and ay < n)) t[ax][ay] = true;
      ax = x-1;
      ay = y+2;
      if((ax > -1 and ax < n) and (ay > -1 and ay < n)) t[ax][ay] = true;
      ax = x-1;
      ay = y-2;
      if((ax > -1 and ax < n) and (ay > -1 and ay < n)) t[ax][ay] = true;
      t[x][y] = true;
    }
    else {
      for(j = 0; j < n; j++) {
        t[x][j] = true;
        t[j][y] = true;
      }
    }
  }

  int res = 0;

  for(int i = 0; i < n; i++) {
    for(int k = 0; k < n; k++) {
      if(t[i][k]) res++;
    }
  }

  cout << res << endl;

  return 0;
}
