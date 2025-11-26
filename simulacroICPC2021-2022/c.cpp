#include <bits/stdc++.h>
using namespace std;

long long n_to_decimal(long long b, vector<long long>& nums) {
  long long res = 0;
  for (long long i = nums.size() - 1; i >= 0; i--) {
    res += (nums[i] * pow(b, (nums.size() - 1 - i)));
  }
  return res;
}
vector<long long> decimal_to_n(long long b, long long num, long long l) {
  vector<long long> base_n;
  while (num / b >= 1) {
    base_n.push_back(num % b);
    num /= b;
  }
  base_n.push_back(num);
  if (base_n.size() < l) {
    long long diff = l - base_n.size();
    while (diff--) {
      base_n.push_back(0);
    }
  }
  vector<long long> rever;
  for (long long i = base_n.size() - 1; i >= 0; i--) {
    rever.push_back(base_n[i]);
  }
  return rever;
}
const long long INF = 1e18;
int main() {
  long long b, l;
  cin >> b >> l;
  long long dist_cero = 0, pos = -1;
  vector<long long> nums(l);
  for (long long i = 0; i < l; i++) {
    cin >> nums[i];
    if(nums[i] != 0){
      dist_cero++;
      pos = i;
    }
  }
  long long real = n_to_decimal(b, nums);
  if(real % (b+1) == 0){
    cout << 0 << " " << 0 <<endl;
    return 0;
  }
  if(dist_cero == 1){
    cout << pos+1 << " " << 0 <<endl;
    return 0;
  }
  long long cont = 0, indice = INF, diff = INF;
  long long min_indice = INF, min_diff = INF;
  for (long long i = b + 1; i < real; i += (b + 1)) {
    vector<long long> res = decimal_to_n(b, i, l);
    cont = 0, indice = INF, diff = INF;
    if (res.size() == nums.size()) {
      for (long long k = 0; k < nums.size(); k++) {
        if (res[k] < nums[k]) {
          cont++;
          if (cont > 1) {
            cont = -1;
            diff = indice = INF;
            break;
          }
          indice = k;
          diff = res[k];
        } else {
          if (res[k] > nums[k]) {
            diff = indice = INF;
            break;
          }
        }
      }
      if (indice < min_indice) {
        min_diff = diff;
        min_indice = indice;
      } else {
        if (indice == min_indice and indice != INF) {
          if (diff < min_diff) {
            min_diff = diff;
            min_indice = indice;
          }
        }
      }
    }
  }
  if (min_diff == INF) {
    cout << -1 <<" "<< -1 << endl;
  } else {
    cout << min_indice + 1 << " " << min_diff << endl;
    
  }
  return 0;
}