#include <bits/stdc++.h>
using namespace std;

enum { UNVISITED = -1, VISITED = -2 };

vector<vector<int>> AL;
vector<int> dfs_num;
vector<bool> vivos;
int res = 1;

void dfs(int u) {
  dfs_num[u] = VISITED;
  if(vivos[u] == true) {
    res = u;
    return;
  }

  for(int v : AL[u]) {
    if(dfs_num[v] == UNVISITED) {
      if(res == 0)
        dfs(v);
      else 
      return;
    }
  }
}

int main() {  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int q; cin >> q;
  int a, b;
  
  vivos.push_back(true);
  vivos.push_back(true);
  AL.push_back({});
  AL.push_back({});
  dfs_num.push_back(UNVISITED);
  dfs_num.push_back(UNVISITED);
  while(q--) {
    dfs_num.assign(dfs_num.size(), UNVISITED);
    cin >> a >> b;

    if(a == 1) {
      vivos.push_back(true);
      dfs_num.push_back(UNVISITED);
      AL.push_back({});

      AL[b].push_back(vivos.size()-1);
    }
    else {
      vivos[b] = false;
      if(b == res) {
        res = 0;
        dfs(1);
      }
      cout << res << endl;
      
    }

  }

  return 0;
}