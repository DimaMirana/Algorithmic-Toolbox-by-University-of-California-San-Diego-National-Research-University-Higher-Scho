#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>

using std::vector;

int binary_search(const vector<long long> &a,long long low, long long high, long long x)
{
    //int low = 0, high = (int)a.size();
    while(low<=high)
    {
        long long mid = floor(low+((high-low)/2));
        if(x==a[mid])
        {
            //std::cout<< "mid " <<mid<<std::endl;
            return mid;
        }
        else if(x<a[mid])
        {
            high=mid-1;
            //std::cout<<"high" <<high<<std::endl;
        }
        else
        {
            low=mid+1;
            //std::cout <<"low " << low<<std::endl;
        }
    }
    return -1;
    /*if(high<low)
    {
        return -1;
    }
    int mid = floor(low+((high-low)/2));
    if(x==a[mid])
    {
        return mid;
    }
    else if(x<a[mid])
    {
        return binary_search(a,low,mid-1,x);
    }
    else if(x>a[mid])
    {
        return binary_search(a,mid+1,high,x);
    }
    else
        return -1;*/

}

int linear_search(const vector<int> &a, int x)
{
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    long long n,low=0;
    std::cin >> n;
    vector<long long> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    long long m;
    std::cin >> m;
    vector<long long> b(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i)
    {
        //replace with the call to binary_search when implemented
        //std::cout << linear_search(a,b[i]) << ' ';
        std::cout << binary_search(a,low,n, b[i]) << ' ';
    }
}
