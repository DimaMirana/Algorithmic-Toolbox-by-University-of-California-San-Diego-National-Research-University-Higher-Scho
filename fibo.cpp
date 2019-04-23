#include <stdio.h>
#include <iostream>
#include <cassert>
unsigned long long fibo(int n)
{
    unsigned long long f[n];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
        printf("%llu ",f[i]);
    }
    printf("\n");
    return f[n];
}

int main()
{
    int n;
    scanf("%d",&n);
    unsigned long long ans=fibo(n);
    printf("%llu\n",ans);
}
