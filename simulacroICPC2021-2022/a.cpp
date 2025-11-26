#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;


int gauss(int n)
{
  return (((n%INF)*((n+1)%INF))%INF * 500000004)%INF;
}

int main()
{
  int players, limite, aux1, aux2=0;
  cin>>players>>limite;
  vector<pair<int, int>> factores;
  factores.reserve(5001);
  factores.push_back({0, 1});
 

  for(int i=0; i<players; i++)
  {
    cin>>aux1;

    if(limite-aux1<0)
    {
      cout<<0<<endl;
      return 0;
    }
    if(limite - aux1 + 1 > aux2)
    {
      factores.push_back({limite - aux1 + 1, 1});
    }
    else
    {
      pair<int, int > z = {limite - aux1 + 1,0};
      auto j = upper_bound( factores.begin(), factores.end(),z);
      
      int id = j - factores.begin();
      factores[id].first = limite - aux1 + 1;
      factores[id].second = i - id + 1;
      
    }
    aux2 = aux1;
  } 

  int res=0;

  for(int i=1; i<factores.size();)
  {
    if(factores[i].first==1)
    {
      if(res==0)
      {
        res=1;
      }
      break;
    }
    if(factores[i].second == 1)
    { 
      if(res==0)
      {
        res = factores[i].first;
      }
      else
      {
        res = ((res * factores[i].first)%INF - 1)%INF;
      }
      i++;
    }
    else
    {
      int correccion = factores[i].first;
      int k = factores[i].second-1;
      while(k--)
      {
        correccion = gauss(correccion);
      }
      res = (res + correccion)%INF;
      i += factores[i].second;
    }
  }
  cout << res << endl;



  return 0;
}