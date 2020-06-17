#include<stdio.h>
int mySqrt(int );
int main()
{
    int start=20,end=100,num;
    for(num=mySqrt(start-1);num*num<=end;num++)
    {
        printf("%d ",num*num);
    }
    return 0;
}
int mySqrt(int input)
{
    int num;
    for( num=1 ; num*num<=input ; num++ );
    return num;
}
