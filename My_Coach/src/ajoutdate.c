#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "ajoutdate.h"
#include "interface.h"

int ajoutdate(int j, int m, int a, int h) 
{ 
FILE *fff;
fff=fopen("/home/coca/Projects/My_Coach/src/date.txt","a+");
if(fff!=NULL)fprintf(fff,"%i / %i / %i -%i:00- \n",j,m,a,h);
fclose(fff);
return(0); } 
