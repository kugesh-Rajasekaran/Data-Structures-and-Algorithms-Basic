#include<stdio.h>
#include<stdlib.h>

typedef struct students
{
     char name[50];
     char degree[20];
     char dob[12];
     char country[10];
     char marks[6];
     long int salary;

     // LINKS
     int sal_next, sal_prev, name_next, name_prev;
}  STUDENTS;



STUDENTS fillData(char *record)
{
  STUDENTS temp;
  char sal[20];
 int index,ctr;
 for(ctr = 0, index =0; record[ctr]!= ','; index++, ctr++)
     temp.name[index] = record[ctr];
     temp.name[index] = NULL;
 for(index =0,ctr++; record[ctr]!= ','; index++, ctr++)
     temp.degree[index] = record[ctr];
     temp.degree[index] = NULL;
 for(index =0,ctr++; record[ctr]!= ','; index++, ctr++)
     temp.dob[index] = record[ctr];
     temp.dob[index] = NULL;
 for(index =0,ctr++; record[ctr]!= ','; index++, ctr++)
     temp.country[index] = record[ctr];
     temp.country[index] = NULL;
 for(index =0,ctr++; record[ctr]!= ','; index++, ctr++)
     temp.marks[index] = record[ctr];
     temp.marks[index] = NULL;
 for(index =0,ctr++; record[ctr]!=NULL; index++, ctr++)
     sal[index] = record[ctr];
     sal[index] = NULL;
 temp.salary = atol(sal);
 temp.sal_next = temp.sal_prev = temp.name_next = temp.name_prev = -1;
 return temp;
}


int main()
{

 FILE *input = NULL;
 STUDENTS data[50];
 int recordCtr=0,ctr, sal_begin, sal_end, name_begin,name_end, mover,prev;
 int key;
 char tempstr[256], *temp;
 input = fopen("names1.txt", "r");
 temp = fgets(tempstr, 256, input);
 while(temp)
 {
 data[recordCtr] =   fillData(tempstr);
 if(recordCtr == 0)
{
     sal_begin = sal_end = name_begin =  name_end = 0;
} //
else
{
   for(mover = sal_begin;
	  mover != -1 && data[recordCtr].salary > data[mover].salary;
		     prev=mover, mover =data[mover].sal_next);
			   if(mover == sal_begin) // insert in begin
			   {
			   data[recordCtr].sal_next = mover ;
			   data[mover].sal_prev =recordCtr ;
			   sal_begin = recordCtr;
			   }
			   else if(mover !=-1)
			   {
			   data[recordCtr].sal_next = mover;
			   data[recordCtr].sal_prev = prev;
			   data[prev].sal_next = recordCtr;
			   data[mover].sal_prev = recordCtr;
			   }
			   else
			   {
			     data[recordCtr].sal_prev = sal_end ;
			   data[sal_end].sal_next =recordCtr ;
			   sal_end= recordCtr;

			   }
   for(mover = name_begin;
	  mover != -1 && strcmp(data[recordCtr].name, data[mover].name) > 0;
		     prev=mover, mover =data[mover].name_next);
			   if(mover == name_begin) // insert in begin
			   {
			   data[recordCtr].name_next = mover ;
			   data[mover].name_prev =recordCtr ;
			   name_begin = recordCtr;
			   }
			   else if(mover !=-1)
			   {
			   data[recordCtr].name_next = mover;
			   data[recordCtr].name_prev = prev;
			   data[prev].name_next = recordCtr;
			   data[mover].name_prev = recordCtr;
			   }
			   else
			   {
			     data[recordCtr].name_prev = name_end ;
			   data[name_end].name_next =recordCtr ;
			   name_end= recordCtr;

			   }
}
 recordCtr++;
 temp = fgets(tempstr, 256, input);
 }
 fclose(   input);

 // create LINKS
 // SALARY LINK


 while(key!=283)
 {

 while(key=bioskey(1) == 0);
 key = bioskey(0);
 switch(key)
 {
     case 15360 :
       clrscr();

for(ctr = sal_begin;ctr != -1 ; ctr = data[ctr].sal_next)
 printf("%15s\t%8s\t%10s\t%5s\t%s\t%ld\n", data[ctr].name,
   data[ctr].degree, data[ctr].dob, data[ctr].country, data[ctr].marks,
		 data[ctr].salary);
  break;
  case 15616:
	clrscr();
for(ctr = sal_end;ctr != -1 ; ctr = data[ctr].sal_prev)
 printf("%15s\t%8s\t%10s\t%5s\t%s\t%ld\n", data[ctr].name,
   data[ctr].degree, data[ctr].dob, data[ctr].country, data[ctr].marks,
		 data[ctr].salary);
  break;

  case 15872 :
		 clrscr();

for(ctr = name_begin;ctr != -1 ; ctr = data[ctr].name_next)
 printf("%15s\t%8s\t%10s\t%5s\t%s\t%ld\n", data[ctr].name,
   data[ctr].degree, data[ctr].dob, data[ctr].country, data[ctr].marks,
data[ctr].salary);

  break;
  case 16128 :
  clrscr();
for(ctr = name_end;ctr != -1 ; ctr = data[ctr].name_prev)
 printf("%15s\t%8s\t%10s\t%5s\t%s\t%ld\n", data[ctr].name,
   data[ctr].degree, data[ctr].dob, data[ctr].country, data[ctr].marks,
		 data[ctr].salary);




 }
 }



















/*for(ctr = 0;ctr < recordCtr; ctr++)
 printf("%s\t%s\t%s\t%s\t%s\t%ld\n", data[ctr].name,
   data[ctr].degree, data[ctr].dob, data[ctr].country, data[ctr].marks,
		 data[ctr].salary);
  */

















return 0;
}