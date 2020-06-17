#include<stdio.h>

typedef
 struct treenode
{
     int data;
     struct treenode *left;
     struct treenode *right;
}
 TREENODE;
typedef TREENODE * TREENODE_PTR;
typedef struct qnode

{
TREENODE_PTR safe;
struct qnode *next;
} QNODE;
typedef QNODE * QNODE_PTR;
QNODE_PTR front, rear, newQnode;

enQueue(TREENODE_PTR keepit)
{
    newQnode = (QNODE_PTR) calloc(1, sizeof(QNODE));
    newQnode->safe = keepit;
    if(front == NULL)
    {
    front = rear = newQnode;
    }
    else
	rear = rear->next = newQnode;
}
TREENODE_PTR deq()
{
TREENODE_PTR temp = NULL;
QNODE_PTR qtemp;
if(front!=NULL)
{
	temp = front->safe;
	qtemp = front;
	front = front->next;
	free(qtemp);
}
	return temp;

}

TREENODE_PTR root, newnode, prev, tptr;
void drawTree( int start  , int end , TREENODE_PTR  dispptr)
{
   int col;
   static int row = 5;
   col = (end - start )/ 2 + start;
   if(dispptr)  {
   gotoxy(col,row);

   printf("%d",dispptr->data);
//   getch();
   row+=3;
   drawTree(start,end/2 + start/2,dispptr->left);
   drawTree(end/2  +start/2 + 1, end , dispptr -> right);
   row-=3;
   }
}
LPR(TREENODE_PTR disp)
{
if(disp==NULL) return;
LPR(disp->left);
printf("%d ", disp->data);
LPR(disp->right);

}

levelOrder(TREENODE_PTR root)
{
TREENODE_PTR process;
    enQueue(root);
    process = deq();
    do
    {
       printf("%d ", process->data);
       if(process->left)
	    enQueue(process->left);
       if(process->right)
	    enQueue(process->right);
      process = deq();
    }while(process);
}


addNode(int num)
{

      newnode = (TREENODE_PTR) malloc(sizeof(TREENODE));
      newnode->data = num;
      newnode->left = newnode->right = NULL;
      if(root == NULL)
      root = newnode;
      else
      {
      for(tptr = root; tptr; prev = tptr,
	 tptr = newnode->data > tptr->data ? tptr->right : tptr->left);
	 if(newnode->data < prev->data)
	      prev->left = newnode;
	      else
	      prev->right = newnode;
       }
}

int main()
{
int values[]  = {50, 30, 80, 20, 35, 70, 100, 15, 25, 32, 38, 62, 78, 92, 108};
int size, index;
size = sizeof(values)/sizeof(values[0]);
for(index = 0; index < size; index++)
   addNode(values[index]);
   clrscr();
   drawTree(1, 80, root);
   printf("\n\n\n");
   LPR(root);
   getch();
   printf("\n\n\n");
   levelOrder(root);
   getch();

}
