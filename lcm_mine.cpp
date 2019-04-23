#include <stdio.h>

long long gcd(long long a,long long b)
{
    a=a%b;
    if(a==0)
    {
        return b;
    }
    else
        return gcd(b,a);

}

int main()
{
    long long a,b,ans1,ans2;
    scanf("%lld %lld",&a,&b);
    ans1 = gcd(a,b);
    ans2 = (a/ans1)*b;
    printf("%lld\n",ans2);
}

