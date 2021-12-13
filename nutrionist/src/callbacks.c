#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "plats.h"

void
on_buttonADD_MENU_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
Plats Pla;
Date date;
GtkWidget *name;
GtkWidget *id;
GtkWidget *dechets;
GtkWidget *jour,*msg;
char ch[50],ch1[50];
GtkWidget *mois;
GtkWidget *annee;
msg=lookup_widget(button,"msg_add_nut");
name=lookup_widget(button,"entryNAME_ADD_MENU");
id=lookup_widget(button,"entryID_ADD_MENU");
dechets=lookup_widget(button,"entryTRASH_ADD_MENU");
jour=lookup_widget(button,"spinbuttonDAY_ADD_MENU");
mois=lookup_widget(button,"spinbuttonMONTH_ADD_MENU");
annee=lookup_widget(button,"spinbuttonYEAR_ADD_MENU");
strcpy(Pla.Nom,gtk_entry_get_text(GTK_ENTRY(name)));
strcpy(Pla.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(Pla.dechets,gtk_entry_get_text(GTK_ENTRY(dechets)));
strcpy(Pla.date.jour,gtk_entry_get_text(GTK_ENTRY (jour)));
strcpy(Pla.date.mois,gtk_entry_get_text(GTK_ENTRY (mois)));
strcpy(Pla.date.annee,gtk_entry_get_text(GTK_ENTRY (annee)));
strcpy(ch,"MENU SUCCESSFULLY ADDED");
ajouter(Pla);
gtk_label_set_text(GTK_LABEL(msg),ch);

}


void
on_buttonDISPLAY_MENU_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *MENU;
GtkWidget *treeview1;
GtkWidget *Display;
MENU=lookup_widget(button,"MENU");
gtk_widget_destroy(MENU);
Display=create_Display();
gtk_widget_show(Display);
treeview1=lookup_widget(Display,"treeview1");
display(treeview1);
}


void
on_buttonBACK_MENU_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Display,*MENU;
Display=lookup_widget(button,"Display");
gtk_widget_destroy(Display);
MENU=create_MENU();
gtk_widget_show(MENU);
}


void
on_buttonREFRESH_MENU_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *Display,*treeview1;
Display=lookup_widget(button,"Display");
gtk_widget_destroy(Display);
Display=create_Display();
gtk_widget_show(Display);
treeview1=lookup_widget(Display,"treeview1");
display(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* id;
gchar* dechets;
gchar* jour;
gchar* mois;
gchar* annee;
Plats Pla;
Date date;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path)) 
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&id,2,&dechets,3,&jour,4,&mois,5,&annee,-1);
strcpy(Pla.Nom,nom);
strcpy(Pla.id,id);
strcpy(Pla.dechets,dechets);
strcpy(Pla.date.jour,jour);
strcpy(Pla.date.mois,mois);
strcpy(Pla.date.annee,annee);
display(treeview);
}
}

void
on_buttonREMOVE_MENU_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

char ch[20],ch1[50];
Plats Pla;
GtkWidget *ID,*msg;
msg=lookup_widget(button,"msg_remove_nut");
ID=lookup_widget(button,"entryID_REMOVE_MENU");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(ID)));
if (verif(ch)==1)
	{supprimer(Pla,ch);
	strcpy(ch1,"MENU SUCCESSFULLY REMOVED");
	gtk_label_set_text(GTK_LABEL(msg),ch1);}
else
{
strcpy(ch1,"MENU NOT FOUND ");
gtk_label_set_text(GTK_LABEL(msg),ch1);
}

}


void
on_buttonUPDATE_MENU_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[20],ch1[50];
Plats Pla;
GtkWidget *ID,*NAME,*TRASH,*jour,*mois,*annee,*msg;
ID=lookup_widget(button,"entryID_UPDATE_MENU");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy(Pla.id,gtk_entry_get_text(GTK_ENTRY(ID)));
NAME=lookup_widget(button,"entryNAME_UPDATE_MENU");
strcpy(Pla.Nom,gtk_entry_get_text(GTK_ENTRY(NAME)));
TRASH=lookup_widget(button,"entryTRASH_UPDATE_MENU");
strcpy(Pla.dechets,gtk_entry_get_text(GTK_ENTRY(TRASH)));
jour=lookup_widget(button,"spinbuttonUPDATE_DAY_MENU");
strcpy(Pla.date.jour,gtk_entry_get_text(GTK_ENTRY(jour)));
mois=lookup_widget(button,"spinbuttonUPDATE_MONTH_MENU");
strcpy(Pla.date.mois,gtk_entry_get_text(GTK_ENTRY(mois)));
annee=lookup_widget(button,"spinbuttonUPDATE_YEAR_MENU");
strcpy(Pla.date.annee,gtk_entry_get_text(GTK_ENTRY(annee)));

msg=lookup_widget(button,"msg_update_nut");

if (verif(ch)==1)
	{modifier(Pla,ch);
	strcpy(ch1,"MENU SUCCESSFULLY UPDATED");
	gtk_label_set_text(GTK_LABEL(msg),ch1);}
else{strcpy(ch1,"MENU NOT FOUND");
	gtk_label_set_text(GTK_LABEL(msg),ch1);
}
}


void
on_buttonCHECK_NUTRIONIST_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *d,*m,*y,*msg;
char ch[50]="",jour[50],mois[50],annee[50];
char ch1[50],ch2[50],ch3[50],ch4[50],ch5[50],ch6[50];
msg=lookup_widget(button,"labelMENU_MSG");
d=lookup_widget(button,"spinbuttonUPDATE_DAY");
strcpy(jour,gtk_entry_get_text(GTK_ENTRY(d)));
m=lookup_widget(button,"spinbuttonUPDATE_MONTH");
strcpy(mois,gtk_entry_get_text(GTK_ENTRY(m)));
y=lookup_widget(button,"spinbuttonUPDATE_YEAR");
strcpy(annee,gtk_entry_get_text(GTK_ENTRY(y)));
f=fopen("plats.txt","r");
if(f!=NULL)
{
while(fscanf(f," %s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{
if((strcmp(jour,ch4)==0) && (strcmp(mois,ch5)==0) && (strcmp(annee,ch6)==0))
{
strcat(ch,ch2);
strcat(ch," ");
}
}
fclose(f);
}
gtk_label_set_text(GTK_LABEL(msg),ch);
}


void
on_buttonSHOW_BEST_MENU_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *msg;
msg=lookup_widget(button,"label38BEST_MENU_MSG");
char ch[50]="",ch1[50],ch2[50],ch3[50],ch4[50],ch5[50],ch6[50];
int min=1000;
int trash,trash1;
f=fopen("plats.txt","r");
if(f!=NULL)
{
while(fscanf(f," %s %s %s %s %s %s ",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{
trash=atoi(ch3);
if(trash<=min)
{
min=trash;
}
}
fclose(f);
}

f=fopen("plats.txt","r");
if(f!=NULL)
{
while(fscanf(f," %s %s %s %s %s %s ",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{
trash1=atoi(ch3);
if(trash1==min)
{
strcat(ch,ch1);
strcat(ch," ");
}
}
fclose(f);
}
gtk_label_set_text(GTK_LABEL(msg),ch);



}
