#include <bits/stdc++.h>

#define form(i, s, e) for (int i = s; i < e; i++)
#define icin(x) \
  int x;        \
  cin >> x;
#define endl '\n'
#define DBG(x) cerr << #x << '=' << (x) << endl
#define coutDouble cout << fixed << setprecision(17)
#define numtobin(n) bitset<32>(n).to_string()
#define bintoint(bin_str) \
  stoi(bin_str, nullptr, 2)  // bin_str should be a STRING
#define F first
#define S second
#define pb push_back
#define sz(x) x.size()

const long long INF = 1e9;
const double PI = acos(-1);

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

int LSOne(int s) { return s & -(s); }

class FenTree {
 private:
  int m;
  vi A, ft;

 public:
  FenTree(int sc) : m(sc), ft(2 * m) {}

  void build() {
    for (int i = 1; i < m; i++) {
      ft[i] += A[i];
      if (i + LSOne(i) < m) ft[i + LSOne(i)] += ft[i];
    }
  }

  FenTree(vi& A) : FenTree((int)A.size()) {
    this->A = A;
    build();
  }

  int srq(int i) {
    int sum = 0;
    do {
      sum += ft[i];
      i = i - LSOne(i);
    } while (i > 0);
    return sum;
  }

  int range_srq(int i, int j) { return srq(j) - srq(i - 1); }

  int range(int res, int k) {
    if (ft[res + 2] < k) {
      return range(res + 2, k);
    } else {
      if (ft[res + 2] = k) {
        return res + 2;
      } else {
        return res + 1;
      }
    }
  }

  int select(int k) {
    int res = 1;
    for (int i = 1; i < m; i = i << 1) {
      if (srq(i) <= k) {
        res = i;
      }
    }
    return range(res, k) + 1;
  }

  void update(int i, int v, int m) {
    for (int j = i; j < m + 1; j += LSOne(j)) {
      ft[j] += v;
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> fr;
  fr.reserve(n + 1);
  fr.push_back(0);
  for (int i = 1; i < n + 1; i++) {
    int aux;
    cin >> aux;
    fr.push_back(aux);
  }
  FenTree ft(fr);

  cout << ft.srq(5) << endl;
  cout << ft.range_srq(3, 5) << endl;

  // cout<<ft.select(5)<<endl;

  ft.update(2, 1, n);

  cout << ft.srq(5) << endl;

  return 0;
}