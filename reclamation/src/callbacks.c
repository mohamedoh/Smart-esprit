#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"


void
on_button_ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
 reclamation r;

 GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*msg;
 
char ch[50];
input1=lookup_widget(objet,"AddReclamationID");
input2=lookup_widget(objet,"AddReclamationLast");
input3=lookup_widget(objet,"AddReclamationFirst");
input4=lookup_widget(objet,"comboboxreclamation");
input5=lookup_widget(objet,"AddReclamationDescription");
input6=lookup_widget(objet,"AddReclamationDate");


strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(r.date_reclamation,gtk_entry_get_text(GTK_ENTRY(input6)));
ajouter(r);
msg=lookup_widget(objet,"msg");
strcpy(ch,"Reclamatiom Successfully Added");
gtk_label_set_text(GTK_LABEL(msg),ch);


}


void
on_button_afficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *SmartEsprit;
GtkWidget *fenetre_afficher;
GtkWidget *treeview_afficher;

SmartEsprit=lookup_widget(objet,"SmartEsprit");

gtk_widget_destroy(SmartEsprit);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

treeview_afficher=lookup_widget(fenetre_afficher,"treeview_afficher");
afficher(treeview_afficher);


}


void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *SmartEsprit,*fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
SmartEsprit=create_SmartEsprit();
gtk_widget_show(SmartEsprit);

}


void
on_treeview_afficher_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* type;
	gchar* description;
        gchar* date_reclamation;
	reclamation r;

   GtkTreeModel *model = gtk_tree_view_get_model(treeview);

 if(gtk_tree_model_get_iter(model,&iter,path))
{   
       //obtention des valeurs de la ligne selectionnée
  gtk_tree_model_get ( GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&type,4,&description,5,&date_reclamation,-1);
       //copie des valeurs dans la variable p de type personne pour le passer a la fonction de suppression
strcpy(r.id,id);
strcpy(r.nom,nom);
strcpy(r.prenom,prenom);
strcpy(r.type,type);
strcpy(r.description,description);
strcpy(r.date_reclamation,date_reclamation);
     

afficher(treeview);
}


}



void
on_UpdateReclamationAdd_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
reclamation r;

 GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*msg1;
 
char ch[50];
input1=lookup_widget(button,"UpdateReclamationID");
input2=lookup_widget(button,"UpdateReclamationLast");
input3=lookup_widget(button,"UpdateReclamationFirst");
input4=lookup_widget(button,"comboboxreclamation_update");
input5=lookup_widget(button,"UpdateReclamationDescription");
input6=lookup_widget(button,"UpdateReclamationDate");


strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(r.date_reclamation,gtk_entry_get_text(GTK_ENTRY(input6)));
if (recherche(r.id)==1)
{modifier(r);
msg1=lookup_widget(button,"msg1");
strcpy(ch,"Reclamatiom Successfully Updated");
gtk_label_set_text(GTK_LABEL(msg1),ch);}
else 
{
msg1=lookup_widget(button,"msg1");
strcpy(ch,"Reclamatiom Not Exist");
gtk_label_set_text(GTK_LABEL(msg1),ch);}

}


void
on_buttonRemove_reclamation_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[50];
GtkWidget *ID;
ID=lookup_widget(button,"entryID_REMOVE_RECLAMATION");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(ID)));
supprimer(ch);
}


void
on_buttoncheck_reclamation_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *msg;
char ch[50]="";
service(ch);
msg=lookup_widget(button,"msg_service");
gtk_label_set_text(GTK_LABEL(msg),ch);
}


void
on_buttonsign_off_reclamation_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_refresh_reclamation_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview_afficher;


w1=lookup_widget(button,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview_afficher=lookup_widget(fenetre_afficher,"treeview_afficher");
afficher(treeview_afficher);

}

