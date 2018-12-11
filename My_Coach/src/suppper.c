#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "suppper.h"
int suppper (char a[],char b[],char c[],char d[])
{
FILE *f8888;
FILE *f1;
char date[50];
char y[50],s[50],a1[50],b1[50],c1[50],d1[50];;
sprintf(date,"%s %s %s %s",a,b,c,d);
f8888=fopen("/home/coca/Projects/My_Coach/src/coaches.txt","r");
f1=fopen("/home/coca/Projects/My_Coach/src/fichier5858.txt","w");
while(fscanf(f8888,"%s %s %s %s\n",s,b,c,d)!=EOF)
{
if(strcmp(a,s)!=0){
sprintf(y,"%s %s %s %s",s,b,c,d);
fprintf(f1,"%s %s %s %s\n",s,b,c,d);}
else fprintf(f1,"%s \n",date);}
remove("coaches.txt");
rename("fichier5858.txt","coaches.txt");
fclose(f8888);
fclose(f1);
return(0);
}
