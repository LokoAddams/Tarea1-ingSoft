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

bool visitados[21];
bool no_confiables[21];

void bfs(int nodo,vector<vector<int>>& survey)
{
    stack<int> adj;
    adj.push(nodo);
    visitados[nodo] = true;
    while(!(adj.empty()))
    {
        int actual = adj.top();
        adj.pop();
        visitados[actual] = true;
        for(auto i: survey[actual])
        {
            if(i < 0) no_confiables[abs(i)] = true;
            else adj.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i , a;
    while (cin >> i >> a, i and a)
    {
        vector<vector<int>> survey(i+1);
        int x , y;
        form(k, 0, a)
        {
            cin >> x >> y;
            survey[x].push_back(y);
        }
        form(k, 1, i+1)
            sort(all(survey[k]));
        int maxi = -1;
        form(k,1,i+1)
        {
            bfs(k, survey);
            form(j, 1, i+1)
                if(!(visitados[j]) and no_confiables[j] == false)
                    bfs(j,survey);
            int cont = 0;
            form(j, 1, i+1)
                if(no_confiables[j] == false)
                    cont++;
            maxi = max(cont , maxi);
        }
        cout << maxi << endl;
        form(k,0,22)
        {
            visitados[k] = false;
            no_confiables[k] = false;
        }
    }
    

    return 0;
}
