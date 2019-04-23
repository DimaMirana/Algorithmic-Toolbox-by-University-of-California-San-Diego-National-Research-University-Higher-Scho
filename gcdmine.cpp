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
    long long a,b,ans;
    scanf("%lld %lld",&a,&b);
    ans = gcd(a,b);
    printf("%lld\n",ans);
}
