#include<stdio.h>

int main()
{
long long num= 9007199254740992, prime_factors,count=0;
for(prime_factors =2; num != 1; prime_factors++)
    if(num % prime_factors == 0)
{

        while(num % prime_factors == 0)
        {
            count++;
            //printf("%d ", prime_factors);
            num = num / prime_factors;
        }
        printf("%lld->%lld/n",prime_factors,count);
        count=0;

}
return 0;
}
