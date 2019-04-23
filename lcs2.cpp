#include <bits/stdc++.h>
#include <iostream>
#include <string>


using namespace std;


int lcs2(vector<int> &a, vector<int> &b)
{
    //write your code here
    int m = a.size() ;
    int n = b.size();
    //cout<<m<<n<<endl;
    vector <vector <int> > l((m+1),vector<int>(n+1));
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
            {
                l[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                l[i][j]=l[i-1][j-1]+1;
            }
            else
            {
                int insertion = l[i][j-1];
                int deletion = l[i-1][j];
                l[i][j]=max(insertion,deletion);
            }
        }
    }

    return l[m][n];
}

int main()
{
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}
