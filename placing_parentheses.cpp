#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void minMaxValue(vector <vector<long long> >&minValues,vector <vector<long long> >&maxValues,const vector <char> &op,long long start,long long last)
{
    long long min_val = 1000000000000;
    long long max_val = -1000000000000;
    for(int i=start;i<last;i++)
    {
        long long m1 = eval(maxValues[start][i],maxValues[i+1][last],op[i]);
        long long m2 = eval(maxValues[start][i],minValues[i+1][last],op[i]);
        long long m3 = eval(minValues[start][i],maxValues[i+1][last],op[i]);
        long long m4 = eval(minValues[start][i],minValues[i+1][last],op[i]);
        long long temp_min = min(m1,min(m2,min(m3,m4)));
        long long temp_max = max(m1,max(m2,max(m3,m4)));

        min_val =min(min_val,temp_min);
        max_val = max(max_val,temp_max);
    }
    minValues[start][last] = min_val;
    maxValues[start][last] = max_val;
}

long long get_max(const vector<long long> &digit,const vector <char> &op,long long start,long long last)
{
    long long x = digit.size();
    long long y = last-start;
    vector <vector <long long> >minValues(x,vector<long long>(x,0));
    vector <vector <long long> >maxValues(x,vector<long long>(x,0));
    for(int i=0;i<x;i++)
    {
        for(int j =0;j<x;j++)
        {
            minValues[i][j]=0;
            maxValues[i][j]=0;
        }
    }
    for(int i=0;i<x;i++)
    {
        minValues[i][i]=digit[i];
        maxValues[i][i]=digit[i];
    }
    for(int i=1;i<=y;i++)
    {
        for(int j=0;j<x-i;j++)
        {
            int k = i+j;
            minMaxValue(minValues,maxValues,op,j,k);
        }
    }
    /*for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            cout<<maxValues[i][j]<<" ";
            cout<<minValues[i][j]<<" ";
        }
        cout<<'\n';
    }*/

    return maxValues[start][last];

}

long long get_maximum_value(const string &exp) {
  //write your code here
  vector <char> op;
  vector <long long > digit;
  for(int i=0;i<exp.size();i++)
  {
      if(i%2==0)
      {
          digit.push_back(exp[i]-'0');
      }
      else
      {
          op.push_back(exp[i]);
      }
  }
  long long x = digit.size() -1;
  return get_max(digit,op,0,x);
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
