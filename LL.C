#include<stdio.h>
typedef struct node
{
    int data;
    struct node   * next;
}                  NODE;
typedef NODE * NODE_PTR;
NODE_PTR newnode, start, tptr;

insertNode(int num)
{
    newnode = (NODE_PTR) malloc(sizeof(NODE));
    newnode->data = num;
    newnode->next = NULL;
    if(start==NULL)
      {
       start = newnode;
       return;
      }
      for(tptr = start; tptr!= NULL; prev = tptr, tptr= tptr->next);
      prev->next = newnode;
      return;
}
displayList()
{
 for(tptr = start; tptr!= NULL; printf("%d ", tptr->num),tptr= tptr->next);

}
int main()
{
insertNode(40);
insertNode(30);
insertNode(60);
insertNode(50);
insertNode(10);
displayList();
}