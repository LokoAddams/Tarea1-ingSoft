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
vi a(n);
form(i,0,n) cin >> a[i];
vi b = a;
form(i,1,a.size())
{
  if(a[i-1] == 1 and a[i] == 0 )
  {
    int cont0 = 0;
    form(j,i+1,a.size())
    {
      if(a[j] == 0)
      {
        cont0++;
      }
      else
      break;
    }

    int cont1 = 0;
    for(int j = i - 2; j >= 0; j--)
    {
      if(a[j] == 1)
      {
        cont1++;
      }
      else
      break;
    }

    if(cont1 < cont0)
    {
      a.erase(a.begin() + i - 1);
      i--;
    }
    else
    {
      a.erase(a.begin() + i );
    }
    i--;
  }
}

cout << a.size() << endl;
  return 0;
}
