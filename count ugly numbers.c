#include<stdio.h>
isitUgly(long long  num)
{
     while(num % 2 == 0)
          num = num / 2;
     while(num % 3 == 0)
          num = num / 3;
     while(num % 5 == 0)
          num = num / 5;
          if(num == 1) return 1;
          return 0;

}
int main()
{
int  uglyCtr=0;
long long num;
for(num = 1; num < 10; num++)
if(isitUgly(num) == 1) uglyCtr++;
    //printf("%d ", num);
    printf("%d", uglyCtr);

}
