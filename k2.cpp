#include <bits/stdc++.h>

#define form(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
#define DBG(x) cerr << #x << '=' << (x) << endl

#define INF 1e9
#define tam 1e5

using namespace std;

// variables
int k;
string n;

////////////

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> k >> n;

  int uno, cero, cont;
  uno = cero = cont = 0;
  if (k != 2) 
  form(i, 0, n.size()) {
      if (n[i] == '1') {
        cero = 0;
        uno++;
      } else {
        uno = 0;
        cero++;
      }
      if (uno == k) {
        if (i != n.size() - 1) {
          if (n[i + 1] == '0') {
            n[i - 1] = '0';
          } else {
            n[i] = '0';
          }

        } else {
          n[i] = '0';
        }
        uno = 0;
        cont++;

      } else {
        if (cero == k) {
          if (i != n.size() - 1) {
            if (n[i + 1] == '1') {
              n[i - 1] = '1';
            } else {
              n[i] = '1';
            }

          } else {
            n[i] = '1';
          }
          cero = 0;
          cont++;
        }
      }
      
    }
  else {
    string n2 = n;
    int cont2 = 0;

    form(i, 0, n.size()) {
      if ((i % 2 || i == 1) && i != 0) {
        if (n[i] != '1') {
          n[i] = '1';
          cont++;
        }

        if (n2[i] != '0') {
          n2[i] = '0';
          cont2++;
        }
      } else {
        if (n[i] != '0') {
          n[i] = '0';
          cont++;
        }

        if (n2[i] != '1') {
          n2[i] = '1';
          cont2++;
        }
      }
    }
    cont = min(cont, cont2);
    if (cont == cont2) n = n2;
  }

  cout << cont << " " << n << endl;

  return 0;
}