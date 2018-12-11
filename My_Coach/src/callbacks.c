#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "nafkhmajdi.h"
#include "ajoutdate.h"
#include "checkdate.h"
#include "verif.h"
#include "lastlogin.h"
#include <string.h>
#include "suppper.h"

        GtkWidget *window;
 GtkWidget *output1;
 GtkWidget *output2;
 GtkWidget *output3;
 GtkWidget *output4;

int testes(char x[])
{
if (strcmp(x,"")==0) return(0);
else return(1);
}


void
on_button1_clicked                     (GtkButton       *objective,
                                        gpointer         user_data)
{
    
        

        GtkWidget *input1;

	GtkWidget *input2;

	GtkWidget *output;



	

	char login[20];

	char password[20];
        char message[100];




input1=lookup_widget(objective,"entry1");

input2=lookup_widget(objective,"entry2");

output=lookup_widget(objective,"label4");

strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));

strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
sprintf(message,"please check your password/login");


if(verif(login,password)==1)

{

lastlogin(login);
//GtkWidget *window1;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objective,"window1")));
//gtk_widget_destroy(window1);
window=create_window4();
gtk_widget_show(window);
}


if(verif(login,password)==0) gtk_label_set_text(GTK_LABEL(output),message);





/*GtkWidget *window1;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet,"window1")));
//gtk_widget_destroy(window1);
window=create_window4();
gtk_widget_show(window);*/
}


void
on_button8_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
//GtkWidget *window2;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet,"window2")));
//gtk_widget_destroy(window2);
window=create_window4();
gtk_widget_show(window);
}


void
on_button12_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
char a[50],b[50],c[50],d[50];
char a1[50],b1[50],c1[50],d1[50];
char p[50];
char username[20];
char PassWord[20];
char y[200],date[200];
int role;

GtkWidget *input111;
GtkWidget *input222;
GtkWidget *input333;
GtkWidget *input444;

input111=lookup_widget(objet,"entry4");
input222=lookup_widget(objet,"entry5");
input333=lookup_widget(objet,"entry6");
input444=lookup_widget(objet,"combobox1");
strcpy(p,gtk_entry_get_text(GTK_ENTRY(input111)));
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input222)));
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input333)));
strcpy(d,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input444)));


FILE *f122;
f122=fopen("/home/coca/Projects/My_Coach/src/lastlogiin.txt","r");
fscanf(f122,"%s %s %s %s ",a1,b1,c1,d1);
strcpy(a,a1);
if (strcmp(b,"")==0) strcpy(b,b1);
if (strcmp(c,"")==0) strcpy(c,c1);
if (strcmp(d,"")==0) strcpy(d,d1);
fclose(f122);
suppper(a,b,c,d);



if(strcmp(p,"newpass")!=0){
FILE *f626;
FILE *f1;
f626=fopen("/home/coca/Projects/My_Coach/src/user.txt","r");
f1=fopen("/home/coca/Projects/My_Coach/src/fichier666.txt","w");
strcpy(date,a);
if (f626!=NULL){ while(fscanf(f626,"%s %s %d\n",username,PassWord,&role)!=EOF)
{
strcpy(y,username);
if(strcmp(y,date)!=0)
fprintf(f1,"%s %s %d \n",username,PassWord,role);
else fprintf(f1,"%s %s %d \n",username,p,role);
}}
remove("user.txt");
rename("fichier666.txt","user.txt");
fclose(f626);
fclose(f1);}
lastlogin(a1);
//GtkWidget *window2;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet,"window2")));
//gtk_widget_destroy(window2);
window=create_window4();
gtk_widget_show(window);
}


void
on_button7_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
//GtkWidget *window3;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet,"window3")));
//gtk_widget_destroy(window3);
window=create_window4();
gtk_widget_show(window);
}


void
on_button6_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
char heur[50];
int heure,jour, mois, annee;

GtkWidget *input1; // jour 
GtkWidget *input2; // mois
GtkWidget *input3; //année 
GtkWidget *input4; //heure
GtkWidget *output;


input1=lookup_widget(objet,"spinbutton1"); 
input2=lookup_widget(objet,"spinbutton2"); 
input3=lookup_widget(objet,"spinbutton3");
input4=lookup_widget(objet,"combobox2");
output=lookup_widget(objet,"label34");

jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1)); mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2)); annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));

strcpy(heur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));

if(strcmp(heur,"")==0) heure=0;
if(strcmp(heur,"9h==>10h")==0) heure=9;
if(strcmp(heur,"10h==>11h")==0) heure=10;
if(strcmp(heur,"12h==>13h")==0) heure=12;
if(strcmp(heur,"13h==>14h")==0) heure=13;

if ((jour==31 && (mois==4 || mois==6 || mois==9||mois==11)) || ((jour==31 || jour==30 || jour==29)&&mois==2)||heure==0) gtk_label_set_text(GTK_LABEL(output),"donner une date valide");
else{
if(checkdate(jour,mois,annee,heure)==0) ajoutdate(jour,mois,annee,heure);

//GtkWidget *window3;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet,"window3")));
//gtk_widget_destroy(window3);
window=create_window4();
gtk_widget_show(window);}
}


void
on_button11_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
//GtkWidget *window4;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window4")));
//gtk_widget_destroy(window4);
window=create_window1();
gtk_widget_show(window);
}


void
on_button5_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
//GtkWidget *window4;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet,"window4")));
//gtk_widget_destroy(window4);
window=create_window5();
gtk_widget_show(window);
}


void
on_button3_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
//GtkWidget *window4;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window4")));
//gtk_widget_destroy(window4);
window=create_window3();
gtk_widget_show(window);
}


void
on_button4_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
//GtkWidget *window4;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window4")));
//gtk_widget_destroy(window4);
window=create_window2();
gtk_widget_show(window);
}


void
on_button9_clicked                     (GtkButton       *object,
                                        gpointer         user_data)
{
 int num;
 GtkWidget *input9; 
 input9=lookup_widget(object,"spinbutton6");
 num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
 nafkhmajdi(num-1);
//GtkWidget *window5;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(object,"window5")));
//gtk_widget_destroy(window5);
window=create_window3();
gtk_widget_show(window);
}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
//GtkWidget *window5;
//GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"window5")));
//gtk_widget_destroy(window5);
window=create_window4();
gtk_widget_show(window);
}


void
on_window1_activate_default            (GtkWindow       *objet,
                                        gpointer         user_data)
{
 /*char d[50],m[100],l[50], n[50], t[50] ,s[50];

FILE *f;
   f=fopen("/home/coca/Projects/My_Coach/src/lastlogiin.txt","r");
   fscanf(f,"%s %s %s %s",l,n,t,s);
   fclose(f);
 
 output1=lookup_widget(objet,"label15");
 /*output2=lookup_widget(objet_graphique,"label11");
 output3=lookup_widget(objet_graphique,"label12");
 output4=lookup_widget(objet_graphique,"label13");

 sprintf(m,"%s \n \n %s \n \n %s \n \n %s",l,n,t,s);  

 gtk_label_set_text(GTK_LABEL(output1),m);*/
}


void
on_button15_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
//GtkWidget *window4;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window4")));
//gtk_widget_destroy(window4);
window=create_window6();
gtk_widget_show(window);
}


void
on_button14_clicked                    (GtkButton       *object,
                                        gpointer         user_data)
{
	 char namae[100],J[4000],k[4000],E[40],d[4000],M[4000],l[4000], n[4000], t[4000] ,s[4000],r[4000];
         int j,m,a,h,e;
         int jo,mo,ao,ho,eo=1,ff;
         //float ff;

FILE *f;
   GtkWidget *input150;
   GtkWidget *output22; 
 input150=lookup_widget(object,"spinbutton7");
 jo=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input150));
   strcpy(M,"");
   if(jo==696){
   f=fopen("/home/coca/Projects/My_Coach/src/696.txt","r");
   fscanf(f,"%s\n %s \n %s \n %s \n %s \n %s \n %s \n %s \n %s",namae,n,t,k,l,s,E,J,d);
sprintf(M,"%s \n %s \n %s \n %s \n %s \n %s \n %s \n %s \n %s",namae,n,t,k,l,s,E,J,d);   fclose(f); }
if(jo==333){
   f=fopen("/home/coca/Projects/My_Coach/src/333.txt","r");
   fscanf(f,"%s\n %s \n %s \n %s \n %s \n %s \n %s \n %s \n %s",namae,n,t,k,l,s,E,J,d);
sprintf(M,"%s \n %s \n %s \n %s \n %s \n %s \n %s \n %s \n %s",namae,n,t,k,l,s,E,J,d);   fclose(f); }
if((jo!=696)&&(jo!=333)) sprintf(M,"fiche medicale inexistante ");
output22=lookup_widget(object,"label36");
gtk_label_set_text(GTK_LABEL(output22),M);

}


void
on_button13_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

	 char J[4000],k[4000],E[40],d[4000],M[4000],l[4000], n[4000], t[4000] ,s[4000],r[4000];
         int j,m,a,h,e;
         int jo,mo,ao,ho,eo;

FILE *f;
   strcpy(k,"");
   f=fopen("/home/coca/Projects/My_Coach/src/lastlogiin.txt","r");
   fscanf(f,"%s %s %s %s",l,n,t,s);
   fclose(f);
 sprintf(M,"%s \n \n %s \n \n %s \n \n %s",l,n,t,s);  
FILE *f42;
   f42=fopen("/home/coca/Projects/My_Coach/src/date.txt","r");
   while(fscanf(f42,"%i / %i / %i -%i:00-",&j,&m,&a,&h)!=EOF)
     {
     sprintf(d,"%i  /  %i /  %i  -%i:00- \n",j,m,a,h);
     strcat(k,d);
     }
   fclose(f42);
FILE *f41;
      strcpy(J,"");
   f41=fopen("/home/coca/Projects/My_Coach/src/daterdv.txt","r");
   while(fscanf(f41,"%i / %i / %i -%i:00- :%i",&jo,&mo,&ao,&ho,&eo)!=EOF)
     {
      sprintf(E,"%i  /  %i /  %i  -%i:00- id:%i \n",jo,mo,ao,ho,eo);
      strcat(J,E);
     }
   fclose(f41);
   
 output1=lookup_widget(objet_graphique,"label15");
 output2=lookup_widget(objet_graphique,"label39");
 output3=lookup_widget(objet_graphique,"label42");
 /*output4=lookup_widget(objet_graphique,"label13");*/


 gtk_label_set_text(GTK_LABEL(output1),M);
 gtk_label_set_text(GTK_LABEL(output2),k);
 gtk_label_set_text(GTK_LABEL(output3),J);
 /*gtk_label_set_text(GTK_LABEL(output4),s)*/;
//GtkWidget *window4;
/*GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window4")));
//gtk_widget_destroy(window4);
window=create_window4();
gtk_widget_show(window);*/
}


void
on_button16_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
//GtkWidget *window4;
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window6")));
//gtk_widget_destroy(window4);
window=create_window4();
gtk_widget_show(window);
}


void
on_button17_clicked                    (GtkButton       *object,
                                        gpointer         user_data)
{
GtkWidget *window;
gtk_widget_hide(GTK_WIDGET(lookup_widget(object,"window6")));
//gtk_widget_destroy(window5);
window=create_window4();
gtk_widget_show(window);
}


void
on_button18_clicked                    (GtkButton       *obj,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *window5;
window5=lookup_widget(obj,"window5");
treeview1=lookup_widget(window5,"treeview1");
afficher_dispo(treeview1);
}

