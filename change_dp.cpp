#include <bits/stdc++.h>
#include <iostream>
#include <vector>


using namespace std;

int coins[3] = { 1,3,4 };

int get_change(int m)
{
    //write your code here
    int numCoins=0;
    vector <int>minNumCoins(m+1);
    for (int i =0; i<m+1; i++)
    {
        minNumCoins[i]=INT_MAX;
    }
    minNumCoins[0]=0;
    minNumCoins[1]=1;
    minNumCoins[2]=2;
    minNumCoins[3]=1;

    for(int i =1; i<m+1; i++)
    {
        for(int j=0; j<3; j++)
        {
            //cout<<"coins[j]= "<<coins[j]<<endl;
            if(i>=coins[j])
            {
                numCoins = minNumCoins[i-coins[j]]+1;
                //cout<<"NumCoins= "<<numCoins<<" minNumCoins["<<i<<" - "<<coins[j]<<endl;
                if(numCoins<minNumCoins[i])
                {
                    minNumCoins[i]=numCoins;
                    //cout<<"minNumCoins["<<i<<"]= " <<minNumCoins[i]<<endl;
                }
            }
        }
    }
    /*for(int i=0;i<m+1;i++)
        cout<<"minNumCoins["<<i<<"]= " <<minNumCoins[i]<<endl;
    cout<<"end " <<minNumCoins[m]<<endl;*/

    return minNumCoins[m];
}
int main()
{
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
