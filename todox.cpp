#include <bits/stdc++.h>
using namespace std;

// IMPRESINDIBLES PARA ICPC
#define form(i, s, e) for (int i = s; i < e; i++)
#define icin(x) \
  int x;        \
  cin >> x;
#define llcin(x) \
  long long x;   \
  cin >> x;
#define scin(x) \
  string x;     \
  cin >> x;
#define endl '\n'
#define S second
#define F first
#define pb push_back
#define sz(x) x.size()
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const ll INF = 1e9 + 7;  // tambien es primo
const double PI = acos(-1);
// UTILES
#define DBG(x) cerr << #x << '=' << (x) << endl
#define coutDouble cout << fixed << setprecision(17)
#define numtobin(n) bitset<32>(n).to_string()
#define bintoint(bin_str) \
  stoi(bin_str, nullptr, 2)  // bin_str should be a STRING
#define LSOne(S) ((S) & -(S))

typedef double db;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, bool> pib;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef vector<pll> vpll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int k, cont1 = 0, cont0 = 0, cont = 0, contaux = 0;
  cin >> k;
  string bin;
  string res;
  char aux;
  cin >> bin;

  // Chupala Denilson, atte. Piton++

  if (k == 2) {
    for (int i = 0; i < bin.size();) {
      if (bin[i] == '0') {
        cont1++;
      } else {
        cont0++;
      }
      i++;

      if (i < bin.size()) {
        if (bin[i] == '1') {
          cont1++;
        } else {
          cont0++;
        }
        i++;
      }
    }
    cout << min(cont0, cont1) << " ";
    if (cont0 <= cont1) {
      for (int i = 0; i < bin.size();) {
        cout << 0;
        i++;
        if (i < bin.size()) {
          cout << 1;
          i++;
        }
      }
    } else {
      for (int i = 0; i < bin.size();) {
        cout << 1;
        i++;
        if (i < bin.size()) {
          cout << 0;
          i++;
        }
      }
    }
  } else {
    aux = bin[0];
    cont = 1;
    for (int i = 1; i < bin.size(); i++) {
      if (bin[i] == aux and i != bin.size() - 1) {
        cont++;
      } else {
        if (bin[i] == aux and i == bin.size() - 1) {
          cont++;
        }
        while (cont != 0) {
          if (cont == k) {
            for (int j = 0; j < cont; j++) {
              if (j == cont - 2) {
                res.push_back('1' - aux + '0');
                contaux++;
              } else {
                res.push_back(aux);
              }
            }
            cont = cont - k;
          } else {
            if (cont > k) {
              for (int j = 0; j < k - 1; j++) {
                res.push_back(aux);
              }
              res.push_back('1' - aux + '0');
              contaux++;
              cont = cont - k;
            } else {
              for (int j = 0; j < cont; j++) {
                res.push_back(aux);
              }
              cont = 0;
            }
          }
        }
        if (bin[i] != aux and i == bin.size() - 1) {
          res.push_back(bin[i]);
        }
        aux = bin[i];
        cont = 1;
      }
    }
    cout << contaux << " " << res;
  }

  return 0;
}