#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k, a , b;
  cin >> n >> k;
  vector<pair<int,int>> nums, copy;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    nums.push_back({a,b});
  }
  copy = nums;
  sort(nums.begin(), nums.end());
  for(int i = 0; i < n; i++){
    if(nums[i].second != copy[i].second){
      cout << "N" << endl;
      return 0;
    }
  }
      cout << "Y" << endl;
  return 0;
}