#include<stdio.h>

int main()
{
int num= 1234567890, prime_factors;
for(prime_factors =2; num != 1; prime_factors++)
    if(num % prime_factors == 0)
{
        printf("%d ", prime_factors);
        while(num % prime_factors == 0)
                num = num / prime_factors;
}
return 0;
}
