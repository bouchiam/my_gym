#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "getlogin.h" 
char getlogin(char c)
{
   char c[50];
   FILE *f;
   f=fopen("/home/coca/Projects/My_Coach/src/lastlogiin.txt","r");
   fscanf(f,"%s",c);
   fclose(f);
return (c);
   
}
