#include <stdio.h>

int main()
{
    int arr[301],x=0,n,l,t,y=0,count1=0;
    scanf("%d %d %d",&l,&t,&n);
    arr[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    arr[n+1]=l;
    while(x<=n+1)
    {
        y=x;
        while((arr[x+1]-arr[y])<= t && x<=n)
        {
            x++;
            //lprintf("%d %d %d\n",arr[x],arr[y],x);
        }
        //printf("%d %d\n",x,y);
        if(y==x)
        {
            if(arr[x]==arr[n+1])
            {
                printf("%d\n",count1);
            }
            else
                printf("-1\n",count1);
            return -1;
        }
        if(x<=n)
        {
            count1++;
            //printf("count %d\n",count1);
        }
    }
}
