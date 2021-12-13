#include <stdio.h>
#include <stdlib.h>
#include "plats.h"
#include <string.h>
#include <gtk/gtk.h>
enum
{
eid,
enom,
edechets,
ejour,
emois,
eannee,
COLUMNS
};

void ajouter (Plats Pla)
{
FILE *f;
f=fopen("plats.txt","a+");
if(f!=NULL)
{
fprintf(f," %s %s %s %s %s %s \n",Pla.id,Pla.Nom,Pla.dechets,Pla.date.jour,Pla.date.mois,Pla.date.annee);
}
fclose(f);
}

void modifier( Plats pla, char num[30])
{
FILE *f1;
FILE *f2;
Plats Pla;
f1=fopen("plats.txt","r");
f2=fopen("plats1.txt","a+");
if ((f1!=NULL) && (f2!=NULL))
{
while(fscanf(f1," %s %s %s %s %s %s \n",Pla.id,Pla.Nom,&Pla.dechets,&Pla.date.jour,&Pla.date.mois,&Pla.date.annee)!=EOF)
{
if (strcmp(Pla.id,num)!=0)
{
fprintf(f2," %s %s %s %s %s %s \n",Pla.id,Pla.Nom,Pla.dechets,Pla.date.jour,Pla.date.mois,Pla.date.annee);
}
else
{
fprintf(f2," %s %s %s %s %s %s \n",pla.id,pla.Nom,pla.dechets,pla.date.jour,pla.date.mois,pla.date.annee);
}
}
fclose(f1);
fclose(f2);
remove("plats.txt");
rename("plats1.txt","plats.txt");
}
}

void supprimer(Plats Pla, char num[30])
{
FILE *f1;
FILE *f2;

f1=fopen("plats.txt","r");
f2=fopen("plats1.txt","a+");
if ((f1!=NULL) && (f2!=NULL))
{
while(fscanf(f1," %s %s %s %s %s %s \n",Pla.id,Pla.Nom,Pla.dechets,Pla.date.jour,Pla.date.mois,Pla.date.annee)!=EOF)
{
if (strcmp(Pla.id, num)!=0)
{
fprintf(f2,"%s %s %s %s %s %s \n",Pla.id,Pla.Nom,Pla.dechets,Pla.date.jour,Pla.date.mois,Pla.date.annee);
}
}
fclose(f1);
fclose(f2);
remove("plats.txt");
rename("plats1.txt","plats.txt");
}
else
{return;}
}

void afficher()
{
FILE *f;
Plats Pla;
f=fopen("plats.txt","r");
if (f!=NULL)
{
while(fscanf(f," %s %s %s %s %s %s \n",Pla.id,Pla.Nom,Pla.dechets,Pla.date.jour,Pla.date.mois,Pla.date.annee)!=EOF)
{
printf(" %s %s %s %s %s %s \n",Pla.id,Pla.Nom,Pla.dechets,Pla.date.jour,Pla.date.mois,Pla.date.annee);
}
}
fclose(f);

}

void chercher( char num[30])
{
FILE *f;
Plats Pla;
f=fopen("plats.txt","r");

if (f!=NULL) 
{
while(fscanf(f," %s %s %s %s %s %s \n",Pla.id,Pla.Nom,Pla.dechets,Pla.date.jour,Pla.date.mois,Pla.date.annee)!=EOF)
{
if (strcmp(Pla.id, num)==0)
{
printf("%s %s %s %s %s %s \n",Pla.id,Pla.Nom,Pla.dechets,Pla.date.jour,Pla.date.mois,Pla.date.annee);
}
}
fclose(f);
}
}
int verif(char num[30])
{
Plats Pla;
FILE *f;
int trouve=0;
f=fopen("plats.txt","r");
if (f!=NULL)
{
while(fscanf(f," %s %s %s %s %s %s \n",Pla.id,Pla.Nom,Pla.dechets,Pla.date.jour,Pla.date.mois,Pla.date.annee)!=EOF)
{
if (strcmp(Pla.id,num)==0)
{
trouve =1;
}
}
fclose(f);
}
return trouve;
}


void display(GtkWidget *list)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store;

FILE *f=NULL;
char Nom[30];
char id[30];
char dechets[30];
char jour[30];
char mois[30];
char annee[30];



store=NULL ;
store=gtk_tree_view_get_model(list);
if(store==NULL)
{	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("id" , renderer , "text" , eid , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("name" , renderer , "text" , enom , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("trash" , renderer , "text" , edechets , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("day" , renderer , "text" , ejour , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("month" , renderer , "text" , emois , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

        renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("year" , renderer , "text" , eannee , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

}
store=gtk_list_store_new(COLUMNS ,G_TYPE_STRING , G_TYPE_STRING ,G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );

f = fopen("plats.txt" , "r");
if(f==NULL)
{
	return ;
}
else
{f = fopen("plats.txt" , "a+");
	while(fscanf(f," %s %s %s %s %s %s \n" , id, Nom ,dechets,jour ,mois,annee)!=EOF)
	{	gtk_list_store_append(store, &iter);
		gtk_list_store_set(store ,&iter ,eid,id,enom,Nom,edechets,dechets,ejour,jour,emois,mois,eannee,annee,-1);
	}
	fclose(f) ;
gtk_tree_view_set_model(GTK_TREE_VIEW(list) , GTK_TREE_MODEL (store));
g_object_unref(store);


}



}



