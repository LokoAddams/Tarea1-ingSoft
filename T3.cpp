#include <bits/stdc++.h>
using namespace std;

//IMPRESINDIBLES PARA ICPC
#define form(i, s, e) for(long long i = s; i < e; i++)
#define icin(x)  \
  long long x;         \
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
typedef vector<long long> vi;
typedef vector<vi> vvi;
typedef pair<long long,long long> pii;

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
typedef pair<long long,bool> pib;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef vector<pll> vpll;



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  long long aux;
  while (cin >> aux)
  {
    vi tl;
    vi t(int(1e5+1),0);
        
    if(aux == 0)
    {
      cin >> aux;
      if(aux == 0)
      {
        cin >> aux;
        if(aux == 0)
        {
          break;
        }
      }
      else
      {
        tl.pb(aux);
        cin >> aux;
      }
    } 
    tl.reserve(100);
    tl.pb(aux);
    long long maxi = -1;
    while (cin >> aux, aux)
    {
      tl.pb(aux);
      maxi = max(maxi , aux);
    }
    long long semaforos = tl.size();
    // cout << semaforos << endl;
    // for(auto i: tl)
    //   cout << i << ",";
    // cout<<endl;
      
    

    long long answerSeconds;
    bool choque = true;
    int cont = 0;
    for(long long i = 0; choque ; i++)
    {
      if(i%2 == 0)
      for(int j = 0; j < tl.size(); j++)
      {
        long long k;
        if(i == 0)
          k = 1;
        else
          k = tl[j]*i;
        for(; k <= (i+1)*tl[j] - 6 ; k++)
        {
          t[k]++;
          if(t[k] == semaforos and i > 0)
          {
            answerSeconds = k;
            choque = false;
            break;
          }
            
          if(k > 60*60*5)
          {
            tl.erase(tl.begin() + j);
            j--;
            if(tl.size() == 0)
            {
              answerSeconds = k;
              choque = false;
              break;
            }
            break;
          }
        }
        if(!choque) break;
      }
    } 


    if(answerSeconds > 60*60*5)
    {
      cout << "Signals fail to synchronise in 5 hours" << endl;
      continue;
    }

      
    long long hours = answerSeconds / 3600;
    long long minutes = (answerSeconds % 3600) / 60;
    long long seconds = answerSeconds % 60;
    std::cout << std::setfill('0') << std::setw(2) << hours << ":"
              << std::setw(2) << minutes << ":"
              << std::setw(2) << seconds << "\n";
  }
  
  return 0;
}
