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
vector<int> a;
vector<char> used;
int targetLen, need;

bool dfs(int cur, int start, int built) {
    if (built == need - 1) return true;

    if (cur == targetLen) {
        return dfs(0, 0, built + 1);
    }

    int last = -1; 
    for (int i = start; i < n; ++i) {
        if (used[i]) continue;
        int x = a[i];
        if (x == last) continue;        
        if (cur + x > targetLen) continue;

        used[i] = 1;
        if (dfs(cur + x, i + 1, built)) return true;
        used[i] = 0;

        last = x;

        if (cur == 0) return false;
        if (cur + x == targetLen) return false;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n && n) {
        a.resize(n);
        int sum = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }

        sort(a.begin(), a.end(), greater<int>());

        int answer = sum;
        for (targetLen = mx; targetLen <= sum; ++targetLen) {
            if (sum % targetLen) continue;
            need = sum / targetLen;
            used.assign(n, 0);
            if (dfs(0, 0, 0)) { answer = targetLen; break; }
        }
        cout << answer << endl;
    }
    return 0;
}
