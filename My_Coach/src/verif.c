#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include "verif.h"

/*int verif(char login[],char password[])

{

	FILE *f;

	char username[20];

	char PassWord[20];

	int role;

f=fopen("/home/coca/Projects/My_Coach/src/user.txt","r");



	if (f!=NULL){ while(fscanf(f,"%s - %s - %d",username,PassWord,&role)!=EOF)

	{

		if((strcmp(login,username)==0) && strcmp(password,PassWord)==0)

{

return(role);

}
return(0);

}
}
else {return(0);}

fclose(f);

}*/
int verif(char login[50],char passe[50]) { FILE*f; char login1[50]; char passe1[50]; int role1; int v1=3,v2=3,r=0; f=fopen("user.txt","r"); while(fscanf(f,"%s %s %d\n",login1,passe1,&role1)!=EOF) { if(v1!=0){ v1=strcmp(login,login1); if(v1==0){v2=strcmp(passe,passe1); if(v2==0){r=role1; }}} } fclose(f); return r; }
