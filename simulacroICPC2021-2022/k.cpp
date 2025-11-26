#include <bits/stdc++.h>
using namespace std;

int main()
{
  int sleep, final, foods, aux1=0, aux2=0;

  cin>>sleep>>final>>foods;
  for(int i=0; i<foods; i++)
  {
    cin>>aux2;
    if(aux2-aux1>=sleep)
    {
      cout<<"Y"<<endl;
      return 0;
    }
    aux1=aux2;
  }
  if(final-aux2>=sleep )
  {
    cout<<"Y"<<endl;
  }
  else
  {
    cout<<"N"<<endl;
  }

  return 0;
}