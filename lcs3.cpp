#include <bits/stdc++.h>
#include <iostream>
#include <string>


using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int m = a.size() ;
    int n = b.size();
    int o = c.size();
    vector<vector<vector<int > > >l(m+1,vector<vector<int> >(n+1, vector<int>(o+1,0)));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=o;k++)
            {
                if(i==0 || j==0 || k==0)
                {
                    l[i][j][k]=0;
                }
                else if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
                {
                    l[i][j][k]=l[i-1][j-1][k-1]+1;
                }
                else
                {
                    int temp1 = l[i-1][j][k];
                    int temp2 = l[i][j-1][k];
                    int temp3 = l[i][j][k-1];

                    l[i][j][k] = max(max(temp1,temp2),temp3);
                }
            }
        }
    }
  return l[m][n][o];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
