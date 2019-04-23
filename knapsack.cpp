#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size();
  vector < vector <int> > arr(n+1 , vector<int>(W+1));
  for(int i=0;i<n+1;i++)
  {
      for(int j=0;j<W+1;j++)
      {
          if(i==0 || j==0)
          {
              arr[i][j]=0;
              //cout<<"if "<<arr[i][j]<<endl;
          }
          else if(w[i-1]<=j)
          {
              arr[i][j] = max(w[i-1]+arr[i-1][j-w[i-1]],arr[i-1][j]);
              //cout<<"else if "<<arr[i][j]<<endl;
          }
          else
          {
              arr[i][j] = arr[i-1][j];
              //cout<<"else "<<arr[i][j]<<endl;
          }
      }
  }
  return arr[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
