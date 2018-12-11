#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "checkdate.h" 
int checkdate(int jour,int mois,int annee,int h)
{
   FILE *ffff;
   int test=0;
   char date[50];
   char y[50];
   sprintf(date,"%i / %i / %i -%i:00-",jour,mois,annee,h);
   ffff=fopen("/home/coca/Projects/My_Coach/src/date.txt","r");
   while(fscanf(ffff,"%i / %i / %i -%i:00-",&jour,&mois,&annee,&h)!=EOF)
   {

      sprintf(y,"%i / %i / %i -%i:00-",jour,mois,annee,h);
      if(strcmp(date,y)==0)
   {
      test=1;
   }
   }
   fclose(ffff);
   return(test);
}
