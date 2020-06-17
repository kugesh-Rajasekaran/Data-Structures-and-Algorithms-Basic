#include<stdio.h>
typedef struct sllnode
{
   int data;
   struct sllnode *next;
} SLLNODE;
typedef SLLNODE * SLLNODE_PTR;
SLLNODE_PTR start, newnode, tptr, prev;
addNode(int num)
{
     newnode=  (SLLNODE_PTR) malloc(sizeof(SLLNODE));
     newnode->data = num;
     newnode->next = NULL;
     for(tptr = start;
	    tptr && newnode->data > tptr->data ;
		   prev = tptr, tptr = tptr->next);
	    if(tptr==start){

		   newnode->next = start;
		   start = newnode;
		   }
		   else
		   {
		   newnode->next = tptr;
		   prev->next = newnode;
		   }
}
void delNode(int delnum)
{
     for(tptr = start;
	    tptr && delnum != tptr->data ;
		   prev = tptr, tptr = tptr->next);
	    if(tptr==start)
		   start = start->next;
		   else
		   prev->next = tptr->next;
		   free(tptr);
}


showList()
{
	 for(tptr = start;
	    tptr ;
		    tptr = tptr->next)
		    printf("%d ", tptr->data);
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
showList();
start = reverseList(start, NULL);
getch();
printf("\n");
showList();
}
reverseList(SLLNODE_PTR called, SLLNODE_PTR holdit)
{
SLLNODE_PTR temp;
if(called == NULL)
{
return holdit;
}
temp = reverseList(called->next, called);
called->next = holdit;
return temp;
}










