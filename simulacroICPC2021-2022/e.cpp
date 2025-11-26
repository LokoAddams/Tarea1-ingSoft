#include <bits/stdc++.h>
using namespace std;

int main()
{
  
  int n; cin >> n;
  queue<int> d0;
  queue<int> d1;
  int aux1, aux2;

  for(int i = 0; i < n;  i++) {
    cin >> aux1 >> aux2;
    if(aux2) {
      d1.push(aux1);
    }
    else {
      d0.push(aux1);
    }
  }

  int t = 0, estado = -1, faltante = 0;
  int actual, est_actual;
  while(true) {
    t++;
    // cout << t << endl;

    if(d0.empty()) {
      t--;
      while(!d1.empty()) {
        actual = d1.front();
        d1.pop();
      }
      if(actual > t+faltante) {
        t = actual+10;
      }
      else {
        t = t + faltante + 10;
      }
      break;
    }

    if(d1.empty()) {
      t--;
      while(!d0.empty()) {
        actual = d0.front();
        d0.pop();
      }
      if(actual > t+faltante) {
        t = actual+10;
      }
      else {
        t = t + faltante + 10;
      }
      break;
    }

    if(faltante == 0) {
      estado = -1;
    }
    else {
      faltante--;
      if(faltante == 0) estado = -1;
    }

    if(d0.front() < d1.front()) {
      actual = d0.front();
      est_actual = 0;
      // cout << "0esc" << endl;
    }
    else {
      actual = d1.front();
      est_actual = 1;
      // cout << "1esc" << endl;
    }
    
    if(actual <= t) {
      if(est_actual == estado or estado == -1) {
        faltante = 10;
        estado = est_actual;
        // cout << "anaido" << endl;
        if(est_actual) {
          d1.pop();
        }
        else {
          d0.pop();
        }
      }
      else{
        if(est_actual) {
          actual = d0.front();
        }
        else {
          actual = d1.front();
        }
        if(actual <= t) {
          faltante = 10;
          // cout << "anaido22" << endl;
          if(estado) {
            d1.pop();
          }
          else {
            d0.pop();
          }
        }
      }
    }
  }

  cout << t << endl;

  return 0;
}