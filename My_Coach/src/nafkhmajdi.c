#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "nafkhmajdi.h" 

int nafkhmajdi (int num)
{
FILE *f;
FILE *f1;
char date[50];
char y[50];
int jour,mois,annee,h;
int i=0;
f=fopen("/home/coca/Projects/My_Coach/src/date.txt","r");
f1=fopen("/home/coca/Projects/My_Coach/src/fichier.txt","w");
while(fscanf(f,"%i / %i / %i -%i:00- ",&jour,&mois,&annee,&h)!=EOF)
{
if(i!=num)
fprintf(f1,"%i / %i / %i -%i:00- \n",jour,mois,annee,h);
i=i+1;

}
fclose(f);
fclose(f1);
remove("date.txt");
rename("fichier.txt","date.txt");
return(0);
}
