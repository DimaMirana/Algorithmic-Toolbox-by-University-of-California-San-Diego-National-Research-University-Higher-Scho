#include <iostream>
#include <stdio.h>

int get_change(int m)
{
    //write your code here
    int count=0;
    while(m>=10)
    {
        count +=m/10;
        m = m%10;
        //printf("m = %d and count =%d\n",m,count);
    }
    while(m>=5 && m<10)
    {
        count += m/5;
        m = m%5;
        //printf("m = %d and count =%d\n",m,count);
    }
    if(m<5)
    {
        count+= m;
        //printf("m = %d and count =%d\n",m,count);
    }
    return count;
}

int main()
{
    int m,x;
    std::cin >> m;
    x = get_change(m);
    printf("%d\n",x);
}
