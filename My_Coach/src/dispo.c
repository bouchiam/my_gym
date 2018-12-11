#include <stdio.h>
#include <string.h>

#include <gtk/gtk.h>
#include "dispo.h"
 

void afficher_dispo(GtkWidget *treeview_diet_rdv)
{ 
enum
{ 
JOUR=0,
MOIS,
ANNE,
HORAIRE,
COLUMNS
};
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	dispo d;

	char jour[20];
	char mois[20];
	char anne[20];
	char horaire[20];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(treeview_diet_rdv);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview_diet_rdv), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",MOIS, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview_diet_rdv), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("anne", renderer, "text",ANNE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview_diet_rdv), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("horaire", renderer, "text",HORAIRE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview_diet_rdv), column);

		
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("date.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ 
              while(fscanf(f,"%s / %s / %s %s\n",jour,mois,anne,horaire)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,JOUR,jour,MOIS,mois,ANNE,anne,HORAIRE,horaire, -1); 
		}
		fclose(f);
}
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_diet_rdv),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}

