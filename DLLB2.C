#include<stdio.h>

typedef struct dllnode
{
   int data;
   struct dllnode *prev;
   struct dllnode *next;
} DLLNODE;
typedef DLLNODE * DLLNODE_PTR;
DLLNODE_PTR start, end, newnode, tptr;

addNode(int num)
{

    newnode = (DLLNODE_PTR) malloc(sizeof(DLLNODE));
    newnode->data = num;
    newnode->prev = newnode->next = NULL;
    for(tptr = start; tptr && newnode->data > tptr->data; tptr = tptr->next);
    if(start==NULL)
    {
       start = end = newnode;
       return;
    }
    else if(tptr==start){
	   newnode->next = start;
	   start->prev =  newnode;
	   start = newnode;
    }
    else if(tptr)
    {
	   newnode->prev = tptr->prev;
	   newnode->next = tptr;
	   tptr->prev->next = newnode;
	   tptr->prev = newnode;
    }
    else
    {
		   newnode->prev= end;
	   end->next =  newnode;
	   end= newnode;

    }





















}
showListForward()
{
for(tptr = start; tptr; printf("%d ", tptr->data), tptr=tptr->next);
}
showListBackward()
{
for(tptr = end; tptr; printf("%d ", tptr->data), tptr=tptr->prev);
}


int main()
{
clrscr();
addNode(40);
addNode(20);
addNode(30);
addNode(10);
addNode(70);
addNode(90);
addNode(33);
showListForward();
getch();
printf("\n\n\n");
showListBackward();
getch();
}
