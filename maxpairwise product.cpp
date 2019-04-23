#include <stdio.h>
#include <math.h>

int main()
{
    int arr[100000],n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    long long max1 = 0;
    long long max2 =0;
    for(int i =0;i<n;i++)
    {
        if(arr[i]>max1)
        {
            max2=max1;
            max1 = arr[i];
        }
        else if(arr[i]>max2)
        {
            max2 = arr[i];
        }
    }
    long long mul = max1 * max2;
    printf("%lld\n",mul);
    //printf("max1 = %lld max2 = %lld",max1,max2);

}
