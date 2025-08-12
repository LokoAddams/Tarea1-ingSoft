#include <bits/stdc++.h>

#define form(i, s, e) for (int i = s; i < e; i++)
#define icin(x) \
  int x;        \
  cin >> x;
#define endl '\n'
#define DBG(x) cerr << #x << '=' << (x) << endl
#define coutDouble cout << fixed << setprecision(17)
#define numtobin(n) bitset<32>(n).to_string()
#define bintoint(bin_str) stoi(bin_str, nullptr, 2)  // bin_str should be a STRING
#define F first
#define S second
#define pb push_back
#define sz(x) x.size()

const long long INF =  1e9;
const double PI = acos(-1);

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int , int> pii;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  icin(n) icin(m)
  vector<pair<ll,ll>> cities;
  vector<pair<ll,ll>> bridges(m);
  vector<pair<pair<ll,ll>,ll>> diferences;// min diference,max diference, number city bridge
  ll l1,r1,l2,r2;
  form(i,0,n)
  {
    cin >> l1 >> r1;
    cities.push_back({l1,r1});
  }
  ll max_dif , min_dif;
  form(i,0,n-1)
  {
    max_dif = cities[i+1].second - cities[i].first;
    min_dif = cities[i+1].first - cities[i].second;
    diferences.push_back({{max_dif, min_dif}, i + 1});
  }
  ll aux;
  form(i,0,m)
  {
    cin >> aux;
    bridges[i] = {aux ,i + 1};
  }
  sort(bridges.begin(), bridges.end(), greater<>());
  sort(diferences.begin(), diferences.end(), greater<>());
  vector<pair<ll,ll>> output;
  int size_false = bridges.size();
  if(bridges.size() >= diferences.size())
    for(ll i=0, j= 0; i < size_false; i++,j++)
    {
      if((bridges[j].first <= diferences[i].first.first and bridges[j].first >= diferences[i].first.second))
      {
        if(output.size() < n - 1){
          output.push_back({diferences[i].second,bridges[j].second});
        }
        else break;
      }
      else
      {
        if(size_false <= diferences.size())
        {
          cout << "No" <<endl;
          return 0;
        }
        else
        {
          i--;
          size_false--;
        }
      }
    }
  else
  {
    cout << "No" <<endl;
    return 0;
  }
  sort(output.begin(),output.end());
  cout << "Yes" <<endl;
  for(auto i: output)
    cout << i.second << " ";
    
    

  
  return 0;
}