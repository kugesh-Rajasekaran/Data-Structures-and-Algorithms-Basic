#include<stdio.h>
isitUgly(int num)
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
int num = 5832;
for(num = 1; num < 1000; num++)
if(isitUgly(num) == 1) printf("%d ", num);

}
