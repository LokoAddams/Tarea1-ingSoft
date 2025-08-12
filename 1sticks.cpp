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


int n;
int lenght, aux2;
bool build_palito(int pos, vi& sticks, bool usados[])
{
  lenght -= sticks[pos];
  if(lenght<0)
  {
    lenght += sticks[pos];
    return false;
  } 
  usados[pos] = true;
  if(lenght == 0) 
  {
    form(i, 0, n)
    {
      if(usados[i] == false)
      {
        lenght = aux2;
        if(!build_palito(i, sticks, usados))
        {
          usados[pos] = false;
          lenght = 0;
          lenght += sticks[pos];
          return false;
        }
        else
        {
          return true;
        }
      }
    }
    return true;
  }
  form(i,pos+1, n)
  {
    if(usados[i] == false)
    {
      if(lenght - sticks[i] < 0)
      {
        int k = i;
        i++;
        while (sticks[i] == sticks[k])
        {
          i++;
        }
        i--;
        continue;
      }
      else
      {
        if(lenght - sticks[i] >= 0)
        {
          if(!build_palito(i, sticks, usados))
          {
            int k = i;
            i++;
            while (sticks[i] == sticks[k])
            {
              i++;
            }
            i--;
            continue;
          }
          else
          {
            return true;
          }
        }
      }
    }

  }
  usados[pos] = false;
  lenght += sticks[pos];
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (cin >> n)
  {
    if( n == 0) break;
    vi sticks;
    sticks.reserve(n);
    int aux, maxi = -1, sum = 0;
    form(i,0,n)
    {
      cin >> aux;
      sum += aux;
      sticks.pb(aux);
      maxi = max(maxi , aux);
    }


    if(maxi == 1)
    {
      cout << 1 << endl;
      continue;
    } 
    if(n == 1)
    {
      cout << aux << endl;
      continue;
    } 

    
    sort(all(sticks), greater<int> ());
    vi divisors;
    for(int i = 2; i * i <= sum; i++)
    {
      if(sum % i == 0)
      {
        divisors.pb(i);
        if(i != sum/i)
        divisors.pb(sum/i);
      }
    }
    sort(all(divisors));


    bool usados[n];
    int j;
    bool un_palo = true;
    for(auto i: divisors)
    {
      if(i >= maxi)
      {
        for(auto& j : usados) j = false;
        lenght = i;
        aux2 = i;
        if (!build_palito(0, sticks, usados))
        {
          continue;
        }
        else
        {
          cout << i << endl;
          un_palo = false;
          break;
        }
      }
    }
    if(un_palo)
      cout << sum << endl;
  }
  
  return 0;
}
