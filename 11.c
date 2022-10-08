#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
int f=0,i=0,j=0,ch;
char d[10],fname[10][10],name[10];
 int clrscr();
printf("Enter the directory name:");
scanf("%s",d);
printf("Enter the number of files:");
scanf("%d",&f);
do
{
printf("Enter file name to be created:");
scanf("%s",name);
for(i=0;i<f;i++)
{
if(!strcmp(name,fname[i]))
break;
}
if(i==f)
{
strcpy(fname[j++],name);
f++;
}
else
printf("There is already %s\n",name);
printf("Do you want to enter another file(yes - 1 or no - 0):");
scanf("%d",&ch);
}
while(ch==1);
printf("Directory name is:%s\n",d);
printf("Files names are:");
for(i=0;i<j;i++)
{
printf("\n%s",fname[i]);
}
getch();
}
