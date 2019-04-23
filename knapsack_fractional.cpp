#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    double W,res = 0.0;
    scanf("%d %lf",&n,&W);
    vector<pair<double,double> > value_and_weight(n);
    vector <pair <double,double> >unit_and_weight(n);
    for(int i=0;i<n;i++)
    {
        cin >> value_and_weight[i].first >> value_and_weight[i].second;
        unit_and_weight[i].first = (value_and_weight[i].first / value_and_weight[i].second);
        //cout << unit_and_weight[i].first<<endl;
        unit_and_weight[i].second = value_and_weight[i].second;
    }
    sort(unit_and_weight.begin(),unit_and_weight.end(),greater<pair<double,double> >());
    for(int i=0;i<n && W>0;i++)
    {
        //cout << "W now " << W<<endl;
        res +=min(unit_and_weight[i].second,W)*unit_and_weight[i].first;
        //cout <<"result = " << setprecision(4)<<res<<endl;
        W -=min(unit_and_weight[i].second,W);
        //cout <<"reduced weight = " << setprecision(4)<< W << endl;
    }
    cout << fixed << setprecision(4) << res << endl;

    return 0;

}
