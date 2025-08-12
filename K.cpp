#include <bits/stdc++.h>

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
#define DBG(x) cerr << #x << '=' << (x) << endl
#define coutDouble cout << fixed << setprecision(17)
#define numtobin(n) bitset<32>(n).to_string()
#define bintoint(bin_str) stoi(bin_str, nullptr, 2)  // bin_str should be a STRING
#define LSOne(S) ((S) & -(S))
#define S second
#define pb push_back
#define sz(x) x.size()

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef pair<int,bool> pib;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef vector<pll> vpll;

const ll INF =  1e9;
const db PI = acos(-1);



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  icin(k) scin(s);

  if(k == 2) {
    char a = '0', b = '1';
    int sa = 0, sb = 0;
    for(auto c : s) {
      if(c != a) sa++;
      if(c != b) sb++;
      swap(a, b);
    }

    a = '0';
    b = '1';
    if(sa < sb) {
      cout << sa << " ";
      form(i, 0, sz(s)) {
        cout << a;
        swap(a, b);
      }
    }
    else {
      cout << sb << " ";
      form(i, 0, sz(s)) {
        cout << b;
        swap(a, b);
      }
    }

    return 0;
  }

  int suma = 0, cont = 0;
  form(i, 1, sz(s)) {
    
    if(s[i] == s[i-1]) cont++;
    else cont = 0;

    if(cont == k-1) {
      if(s[i] == s[i+1]) {
        if(s[i] == '0') s[i] = '1';
        else if(s[i] == '1') s[i] = '0';
      }
      else {
        if(s[i-1] == '0') s[i-1] = '1';
        else if(s[i-1] == '1') s[i-1] = '0';
      }
      suma++;
    }
  }
  cout << suma << " " << s << endl;


return 0;
}
