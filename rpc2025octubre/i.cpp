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

int items, paginas, inicial, p, d, aux, cont=1, encendido, apagado, diferentes, resultado=0, numero;
int peque=0, grande=0;
bool preseleccionados[1001];
bool deseados[1001];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>items>>paginas>>inicial>>p>>d;

  for(int i=0; i<p; i++)
  {
    cin>>aux;
    preseleccionados[aux] = true;
  }
  for(int i=0; i<d; i++)
  {
    cin>>aux;
    deseados[aux] = true;
  }
  
  while(cont<=items)
  {
    encendido=0;
    apagado=0;
    diferentes=0;

    for(int i=0; i<paginas; i++)
    {
      if(cont > items)
      {
        break;
      }
      if(preseleccionados[cont] != deseados[cont])
      {
        if(peque==0)
        {
          peque = cont;
        }
        grande=max(grande, cont);
        diferentes++;
      }
      if(deseados[cont])
      {
        encendido++;
      }
      else
      {
        apagado++;
      }
      cont++;
    }
    resultado += min(diferentes, min(encendido+1, apagado+1));
  }
  
  if(peque != 0)
  {
    if(peque%paginas==0)
    {
      peque=peque/paginas;
    }
    else
    {
      peque=peque/paginas+1;
    }
  }
  else peque=inicial;
  
  if(grande != 0)
  {
    if(grande%paginas==0)
    {
      grande=grande/paginas;
    }
    else
    {
      grande=grande/paginas+1;
    }
  }
  else grande=inicial;
  
  if(inicial>grande)
  {
    grande=inicial;
  }
  if(inicial<peque)
  {
    peque=inicial;
  }
  if(grande-inicial > inicial-peque)
  {
    resultado += (inicial-peque)*2 + grande-inicial;
  }
  else
  {
    resultado += (grande-inicial)*2 + inicial-peque;
  }

  cout << resultado << endl;

  return 0;
}
