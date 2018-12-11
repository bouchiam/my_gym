#include <gtk/gtk.h>
typedef struct
{
char jour[20];
char mois[20];
char anne[20];
char horaire[20];
}dispo;
/*enum
{ 
JOUR=0,
MOIS,
ANNE,
HORAIRE,
COLUMNS
};*/
void afficher_dispo(GtkWidget *treeview_diet_rdv);
