#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define PI acos(-1)
#define ll long long int
#define ld long double

const int INF = 1e9+7;
const int MAXN = 1e5+7;

vector<int> getPF(int n){
  vector<int> pf;
  for(int d = 2; d*d <= n; d++){
    while(n%d==0){
      pf.push_back(d);
      n/=d;
    }
  }
  if(n > 1) pf.push_back(n);
  return pf;
}

struct Node{
  ll x = 0;
  vector<int> pf;
  Node(){}
};

struct Lazy{
  ll x = 0;
  ll spf = 0;
  Lazy(){}
};

Node t[4*MAXN];
Lazy lazy[4*MAXN];

Node merge(Node L, Node R){
  Node aux;
  aux.x += L.x;
  aux.x += R.x;
  return aux;
}

void build(vector<int>& a, int v, int tl, int tr){
  if(tl == tr){
    t[v].pf = getPF(a[tl]);
    ll acu = 0;
    for(auto x: t[v].pf) acu += x;
    t[v].x = acu;
  }else{
    int tm = (tl+tr)/2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = merge(t[v*2], t[v*2+1]);
  }
}

void push(int v, int tl, int tr){
  if(lazy[v].x){
    lazy[v*2].x = lazy[v*2+1].x = lazy[v].x;
    lazy[v*2].spf = lazy[v*2+1].spf = lazy[v].spf;

    int tm = (tl+tr)/2;
    t[v*2].x = (tm-tl+1)*lazy[v].spf;
    t[v*2+1].x = (tr-tm)*lazy[v].spf;
    lazy[v].x = lazy[v].spf = 0;
  }
}

void update(int v, int tl, int tr, int l, int r, ll x, ll spf){
  if(l > r) return;
  if(tl == l && tr == r){
    t[v].x  = (tr-tl+1)*spf;
    lazy[v].x = x;
    lazy[v].spf = spf;
  }else{
    push(v, tl, tr);  
    int tm = (tl + tr)/2;
    update(v*2, tl, tm, l, min(r, tm), x, spf);
    update(v*2+1, tm+1, tr, max(l, tm+1), r, x, spf);
    t[v] = merge(t[v*2], t[v*2+1]);
  }
}

ll query(int v, int tl, int tr, int l, int r){
  if(l > r) return 0;
  if(tl == l && tr == r) return t[v].x;
  push(v, tl, tr);
  int tm = (tl+tr)/2;
  ll nl = query(v*2, tl, tm, l, min(tm, r));
  ll nr = query(v*2+1, tm+1, tr, max(tm+1, l), r);
  return nl+nr; 
}

void delet(int v, int tl, int tr, int pos){
  if(tl == tr){
    if(lazy[v].x){
      t[v].pf = getPF(lazy[v].x);
      lazy[v].x = lazy[v].spf = 0;
    }
    
    if(!t[v].pf.empty()){
      t[v].x -= t[v].pf.back(); 
      t[v].pf.pop_back();
    }

  }else{
    push(v, tl, tr);
    int tm = (tl + tr)/2;
    if(pos <= tm) delet(v*2, tl, tm, pos);
    else delet(v*2+1, tm+1, tr, pos);
    t[v] = merge(t[v*2], t[v*2+1]);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n; cin >> n;

  vector<int> a(n);
  for(auto &i: a) cin >> i;
  
  build(a, 1, 0, n-1);

  int q; cin >> q;

  while(q--){
    int type; cin >> type;
    
    if(type == 1){
      int x; cin >> x;
      delet(1, 0, n-1, x-1);
    }else if(type == 2){
      int l, r;
      cin >> l >> r;
      cout << query(1, 0, n-1, l-1, r-1) << endl;
    }else{
      int l, r, x;
      cin >> l >> r >> x;

      vector<int> aux = getPF(x);
      ll spf = 0;
      for(auto xx: aux) spf+= xx;
      update(1, 0, n-1, l-1, r-1, x, spf);
    }

  }

}
 