#include <bits/stdc++.h>
#include <iostream>
#include <string>


using namespace std;

int edit_distance(const string &str1, const string &str2)
{
    //write your code here
    int m = str1.size() ;
    int n = str2.size();
    //cout<<m<<n<<endl;
    vector <vector <int> > d((m+1),vector<int>(n+1));
    /*for(int i =0; i<=m; i++)
    {
        d[0][i]=i;
    }
    for(int j=0; j<=n; j++)
    {
        d[j][0]=j;
    }
    cout<<endl;
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<d[i][j];
        }
        cout<<endl;
    }*/
    for(int i =0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0)
                d[i][j]=j;
            else if(j==0)
                d[i][j]=i;
            else
            {
                int insertion = d[i][j-1];
                int deletion = d[i-1][j];
                int match = d[i-1][j-1];
                int mismatching = d[i-1][j-1];

                if(str1[i-1]==str2[j-1])
                {
                    d[i][j]=match;
                }
                else
                    d[i][j] = min(min(insertion,deletion),mismatching)+1;
            }
        }
    }
    /*for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cout<<d[i][j];
        }
        cout<<endl;
    }*/
    return d[m][n];
}

int main()
{
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
