#include <iostream>
#include <stdio.h>

int fibonacci_sum_naive(long long n) {
    n = (n+2)%60;
    printf("n = %lld\n",n);
    if(n>60)
    {
        n = (n+2)%60;
        printf("n = %lld\n",n);
    }
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        printf("i = %lld current= %lld \n",i,current);
        //sum += current;
    }
    printf("\n");

    return (current-1) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
