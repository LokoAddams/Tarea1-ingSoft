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

vi acu(int(1e5));
int c(int l, int r)
{
  if(l > 0) return acu[r] - acu[l-1];
  return acu[r];
}

int t ;
int bs(int l, int r)
{
  int i = l, j = r;
  int n , mitad;
  while (i != j)
  {
    n = j - i;
    mitad = i + n/2;
    if(c(l,mitad) == t) return mitad - l + 1;
    if(c(l,mitad) > t) j = mitad;
    else i = mitad + 1;
  }
  return c(l,i) <= t ? i - l + 1 : (c(l,i - 1) ? i - l : - 1) ;  
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  icin(n)
  cin >> t;
  vi nums(n);
  form(i,0,n) cin >> nums[i];

  acu[0] = nums[0];
  form(i,1,n) acu[i] = acu[i-1] + nums[i];
  int maxi = 0;
  form(i,0,n)
    maxi = max(maxi , bs(i, n-1));
  cout << maxi << endl;
  return 0;
}
