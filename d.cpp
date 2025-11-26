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

  icin(n)
  vector<long long> a(n+1);
  form(i,1,n+1)
    cin >> a[i];
    
  ll ener = 0, d = 0;
  a[0] = 0;
  form(i,0,n)
  {
    if(a[i] + ener <= a[i+1])
    {
      d += (a[i+1] - (a[i] + ener));
      ener = 0;
    }
    else
    {
      if(a[i] > a[i+1])
      {
        ener += (a[i] - a[i+1]);
      }
      else
      {
        if(ener >= a[i+1] - a[i])
        {
          ener -= (a[i+1] - a[i]);
        }
      }
      
    }
  }
  cout << d << endl;

  return 0;
}
