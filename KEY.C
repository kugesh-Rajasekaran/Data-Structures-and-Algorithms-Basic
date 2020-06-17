#include<stdio.h>

int main()
{
int ch;
while(ch!=283)
{
while(bioskey(1) ==0);
ch = bioskey(0);
printf("%d\n", ch);
}
}
