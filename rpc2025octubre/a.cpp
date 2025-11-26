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


bool posible[1000][21];int n; int dp[1000][21];
int f(int i , int j, int cont )
{
  if(dp[i][j] != 0 ) return dp[i][j]; 
  if(i == n-1) return dp[i][j] = 1;
  vector<pii> aux;
  form(k,0,21)
    if(posible[i+1][k])
      if(j == k)
      {
        aux.pb({f(i+1,k,cont + 1), k});
      }
      else
      {
        aux.pb({f(i+1,k,1), k});
      }

  sort(all(aux));
  if(aux.size() >= 2)
  {
    if(posible[i+1][j])
    {
      if(aux[0].first - 1 == dp[i+1][j])
      {
        if(cont + 1 == aux[0].first - 1)
        {
          return dp[i][j] = cont + 1;
        }
      }
    }
  }

  if(aux[0].first == dp[i+1][j])
  {
    return dp[i][j] = aux[0].first + 1;
  }
  else
  {
    return dp[i][j] = aux[0].first ;
  }
  
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  icin(a)icin(b)
  vi nums(n);
  form(i,0,n) cin >> nums[i];
  form(i,0,n)
  {
    form(j,0,21) 
    {
      int p = j - 10;
      if(nums[i] +(12 * p) >= a and nums[i] +(12 * p) <= b)
      {
        posible[i][j] = true;
      }
    }
  }

  int maxi = 0;
  form(j,0,21)
  {
    if(posible[0][j])
    {
      maxi = max(maxi, f(0,j,1));
    }
  }
  cout << maxi << endl;
  
  form(i,0,n)
  {
    form(j,0,21)
      cout << dp[i][j] << " ";
    cout << endl;
  }
      

  return 0;
}
