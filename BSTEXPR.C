#include<stdio.h>
#include<malloc.h>

typedef struct btnode
{
    char ch;
    struct btnode *left;
    struct btnode *right;
} BTNODE;
typedef BTNODE * BTNODE_PTR;

void drawTree( int start  , int end , BTNODE_PTR  dispptr)
{
   int col;
   static int row = 5;
   col = (end - start )/ 2 + start;
   if(dispptr)  {
   gotoxy(col,row);

   printf("%c",dispptr->ch);
//   getch();
   row+=3;
   drawTree(start,end/2 + start/2,dispptr->left);
   drawTree(end/2  +start/2 + 1, end , dispptr -> right);
   row-=3;
   }
}

BTNODE_PTR stack[100];
int top = -1;

push(BTNODE_PTR keepit)
{
stack[++top] = keepit;
}
BTNODE_PTR pop()
{
BTNODE_PTR temp;
temp = stack[top];
top--;
return temp;
}

isOperator(char ch)
{
if(ch == '+'|| ch == '-' || ch == '*' || ch == '/') return 1;
return 0;
}

inOrder(BTNODE_PTR disp)
{
if(disp==NULL) return;
inOrder(disp->left);
//if(disp->ch >= '0' &&  disp->ch <= '9')
printf("%c", disp->ch);
//else
//printf("%c", disp->ch);
inOrder(disp->right);


}

int solve(BTNODE_PTR proc)

{
int left_expression, right_expression;

if(proc->left == NULL && proc->right == NULL)
  return proc->ch-48;
left_expression = solve(proc->left);
right_expression = solve(proc->right);
switch(proc->ch)
{
   case '*' : return left_expression * right_expression;
   case '/' : return left_expression / right_expression;
   case '+' : return left_expression + right_expression;
   case '-' : return left_expression - right_expression;

}
}



int main()
{
BTNODE_PTR root = NULL, newnode;
//char *post = "987*+28*+3/";
char *post = "93+72-*36+53-**";
int index;
for(index = 0; post[index]; index++)
{
    if(isOperator(post[index]) == 1)
    {
	  newnode = (BTNODE_PTR) malloc(sizeof(BTNODE));
	  newnode->ch = post[index];
	  newnode->right = pop();
	  newnode->left = pop();
	  push(newnode);
    }//
    else
    {
	  newnode = (BTNODE_PTR) malloc(sizeof(BTNODE));
	  newnode->ch = post[index];
	  newnode->right = NULL;
	  newnode->left = NULL;
	  push(newnode);
    }
}
root = pop();
clrscr();
		    drawTree(1,80,root);
		    printf("\n\n");
		    inOrder(root);
		    printf("\n\n\n%d", solve(root));
		    getch();
}



















