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

class SegmentTree {                              // OOP style
private:
  int n;                                         // n = (int)A.size()
  vi A, st, lazy;                                // the arrays

  int l(int p) { return  p<<1; }                 // go to left child
  int r(int p) { return (p<<1)+1; }              // go to right child

  int conquer(int a, int b) {
    if (a == -1) return b;                       // corner case
    if (b == -1) return a;
    return a+b;                            // RMQ
  }

  void build(int p, int L, int R) {              // O(n)
    if (L == R)
      st[p] = A[L];                              // base case
    else {
      int m = (L+R)/2;
      build(l(p), L  , m);
      build(r(p), m+1, R);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {                         // has a lazy flag
      st[p] += lazy[p];                           // [L..R] has same value
      if (L != R)       
      {
        int m = (L+R)/2;
        lazy[l(p)] = (m-L+1);
        lazy[r(p)] = (R-(m+1)+1);       // propagate downwards
      }    
      else                                       // L == R, a single index
      {
        A[L] = lazy[p];                          // time to update this
      }  
      lazy[p] = -1;                              // erase lazy flag
    }
  }

  int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) 
      return -1;                        // infeasible
    if ((L >= i) && (R <= j)) 
      return st[p];      // found the segment
    int m = (L+R)/2;
    int left = RMQ(l(p), L  , m, i, min(m, j));
    int right = RMQ(r(p), m+1, R, max(i, m+1), j);
    return conquer(left,right);
  }

  void update(int p, int L, int R, int i, int j) { // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return;
    if ((L >= i) && (R <= j)) {                  // found the segment
      lazy[p] = R-L+1;                             // update this
      propagate(p, L, R);                        // lazy propagation
    }
    else {
      int m = (L+R)/2;
      update(l(p), L  , m, i          , min(m, j));
      update(r(p), m+1, R, max(i, m+1), j        );
      int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      st[p] = conquer(lsubtree, rsubtree);
    }
  }

public:
  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
    true;
  }

  void update(int i, int j) { update(1, 0, n-1, i, j);  }

  int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  icin(n)icin(m)
  vi ages(n+1);
  form(i,1,n+1)
  {
    icin(a)icin(b)
    ages[i] = a;
  }
  vi A(int(1e5+1),0);
  SegmentTree st(A);
  form(i,0,m)
  {
    icin(o)icin(l)icin(r)
    st.update(l,r);
  }
  form(i,1,n+1)
  {
    cout << st.RMQ(ages[i],ages[i]) << " " ;
  }
  return 0;
}
