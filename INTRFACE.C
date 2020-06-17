#include<stdio.h>
//#include<val.h>
#include<conio.h>

printHeading()
{
gotoxy(15,1);
printf("Our Simple Project to Implement Basic Data Structures");
gotoxy(15,2);
printf("~~~ ~~~~~~ ~~~~~~~ ~~ ~~~~~~~~~ ~~~~~ ~~~~ ~~~~~~~~~~");

}
#define COLHEAD_ROW 4
colHeading()
{
   gotoxy(13,COLHEAD_ROW);
   printf("NAME");
   gotoxy(28,COLHEAD_ROW);
   printf("DEGREE");
   gotoxy(40,COLHEAD_ROW);
   printf("DOB");
   gotoxy(49,COLHEAD_ROW);
   printf("COUNTRY");
   gotoxy(59,COLHEAD_ROW);
   printf("MARKS");
   gotoxy(67,COLHEAD_ROW);
   printf("SALARY");
}
drawDabba()
{
int row=3, col=4, ctr1, ctr2;
clrscr();
// FIRST LINE
gotoxy(col, row);
printf("%c",LT);
for(ctr1=0; ctr1 < 20; ctr1++)
printf("%c",HL);
printf("%c",TT);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",TT);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",TT);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",TT);
for(ctr1=0; ctr1 < 5; ctr1++)
printf("%c",HL);
printf("%c",TT);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",TT);
printf("%c%c",BS,RT);
for(ctr2=0; ctr2 < 11; ctr2++)
{
gotoxy(col, ++row);
printf("%c",VL);
for(ctr1=0; ctr1 < 20; ctr1++)
printf("%c",SPACE);
printf("%c",VL);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",SPACE);
printf("%c",VL);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",SPACE);
printf("%c",VL);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",SPACE);
printf("%c",VL);
for(ctr1=0; ctr1 < 5; ctr1++)
printf("%c",SPACE);
printf("%c",VL);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",SPACE);
printf("%c",VL);
gotoxy(col, ++row);
printf("%c",LST);
for(ctr1=0; ctr1 < 20; ctr1++)
printf("%c",HL);
printf("%c",CROSS);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",CROSS);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",CROSS);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",CROSS);
for(ctr1=0; ctr1 < 5; ctr1++)
printf("%c",HL);
printf("%c",CROSS);
for(ctr1=0; ctr1 <= 10; ctr1++)
printf("%c",HL);
printf("%c%c",BS,RST);
} // BODY
// LAST LINE
gotoxy(col, row);
printf("%c",LB);
for(ctr1=0; ctr1 < 20; ctr1++)
printf("%c",HL);
printf("%c",BT);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",BT);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",BT);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",BT);
for(ctr1=0; ctr1 < 5; ctr1++)
printf("%c",HL);
printf("%c",BT);
for(ctr1=0; ctr1 < 10; ctr1++)
printf("%c",HL);
printf("%c",BT);
printf("%c%c",BS,RB);
}
showInfo(int counter, int ind)
{
     int row=6;
 //    for(ind = start; ind <=end;ind++,row+=2 )
   row = row + (counter * 2);
     {
	gotoxy(5,row);
	printf("%20.19s", data[ind].name);
	gotoxy(26,row);
	printf("%10.8s", data[ind].degree);
	gotoxy(37,row);
	printf("%s", data[ind].dob);

	gotoxy(48,row);
	printf("%s", data[ind].country);

	gotoxy(59,row);
	printf("%s", data[ind].marks);

	gotoxy(65,row);
	printf("%ld", data[ind].salary);

     }
}
