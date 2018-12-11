#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "lastlogin.h" 
/*void lastlogin(char login[])
{
   FILE *f;
   FILE *ffff;
   int test=1;
   char profile[100],l[50],n[50], t[50], s[50];
   f=fopen("coaches.txt","r");
   while ((fscanf(f,"%s %s %s %s",l,n,t,s)!=EOF) && test==1 )
   {
   if(strcmp(l,login)==0) test=0;
   }
   fclose(f);   
   sprintf(profile,"%s %s %s %s",l,n,t,s);
   ffff=fopen("lastlogiin.txt","w");
   fprintf(ffff,"%s \n",profile);
   fclose(ffff);
}*/
/*int count()
{
   FILE *f;
   FILE *ffff;
   int test=0;
   char profile[100],l[50],n[50], t[50], s[50];
   f=fopen("coaches.txt","r");
   while ((fscanf(f," %s %s %s %s",l,n,t,s)!=EOF))
   {
   test=test+1;
   }
  
   fclose(f);
   return(test) ;
}*/

void lastlogin(char login[])
{
   FILE *f;
   FILE *ffff;
   int test=1;
   char profile[100],l[50],n[50], t[50], s[50];
   f=fopen("coaches.txt","r");
   while (/*(fscanf(f," %s %s %s %s",l,n,t,s)!=EOF) || */test!=0 )
   {fscanf(f," %s %s %s %s",l,n,t,s);;
   if(strcmp(l,login)==0) test=0;
   }   sprintf(profile,"%s %s %s %s",l,n,t,s);
   fclose(f);   
   ffff=fopen("lastlogiin.txt","w");
   fprintf(ffff,"%s \n",profile);
   fclose(ffff);
}
