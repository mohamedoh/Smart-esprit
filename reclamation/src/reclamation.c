#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"reclamation.h"
#include<gtk/gtk.h>

enum
{
    EID,
    ENOM,
    EPRENOM,
    ETYPE,
    EDESCRIPTION,
    EDATE_RECLAMATION,
    COLUMNS,
   
};





///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
void ajouter(reclamation r)
{
FILE  *f;
f=fopen("reclamation.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s \n",r.id,r.nom,r.prenom,r.type,r.description,r.date_reclamation);
fclose(f);
}

}
///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void afficher(GtkWidget *liste)
{

GtkCellRenderer *renderer;
GtkTreeViewColumn  *column;
GtkTreeIter *iter;
GtkListStore *store;

    gchar id[20];
    gchar nom[20];
    gchar prenom[20];
    gchar type[20];
    gchar description[1000];
    gchar date_reclamation[30];
   
reclamation r;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
     {




 renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer, "text", EID,NULL );
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text", ENOM , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);
	

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text", EPRENOM , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);
	

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer, "text", ETYPE , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);
	

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("description",renderer, "text", EDESCRIPTION , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("date_reclamation",renderer, "text", EDATE_RECLAMATION,NULL );
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);

}



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("reclamation.txt","r");
if(f==NULL)
{ 
   return;
}
else
{           f=fopen("reclamation.txt","a+");
            while( fscanf(f,"%s %s %s %s %s %s ",id, r.nom, r.prenom, r.type, r.description,r.date_reclamation)!= EOF)
   {   
         gtk_list_store_append(store ,&iter);
         gtk_list_store_set(store,&iter,EID,id,ENOM,r.nom,EPRENOM,r.prenom,ETYPE,r.type,EDESCRIPTION,r.description,EDATE_RECLAMATION,r.date_reclamation,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref(store);
   }
}





	

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////


 int recherche (char id[])
    {
        FILE*f=NULL;
        reclamation r;
	int c=0;
char ch1[50],ch2[50],ch3[50],ch4[50],ch5[50],ch6[50];
        f=fopen("reclamation.txt","r");
        while(fscanf(f,"%s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
        {
            if(strcmp(id,ch1)==0)
            {
                c=1;
            }
    
        }
        fclose(f);
	return c;

    }
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

void modifier(reclamation r)
    {
        FILE*f=NULL;
        FILE*f1=NULL;
        char ch1[50],ch2[50],ch3[50],ch4[50],ch5[50],ch6[50];
        f=fopen("reclamation.txt","r");
        f1=fopen("new.txt","w");
        while(fscanf(f,"%s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
        {
            if(strcmp(ch1,r.id)!=0)
            {
                fprintf(f1,"%s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6);
            }
            else
            {
                fprintf(f1,"%s %s %s %s %s %s \n",r.id, r.nom, r.prenom, r.type, r.description,r.date_reclamation);
            }

        }
        fclose(f);
        fclose(f1);

        remove("reclamation.txt");
        rename("new.txt","reclamation.txt");
    }

/*********************************************************************/
void service(char ch[])
{
	FILE*f=NULL;
        char ch1[50],ch2[50],ch3[50],ch4[50],ch5[50],ch6[50];
	int res1=0,res2=0,res3=0,res4=0;
	int max;
        f=fopen("reclamation.txt","r");
        while(fscanf(f,"%s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
        {if (strcmp(ch4,"ADMINISTRATION")==0) res1++;
	if (strcmp(ch4,"FOYER")==0) res2++;
	if (strcmp(ch4,"RESTAURATION")==0) res3++;
	if (strcmp(ch4,"SECURITY")==0) res4++;	
	}
	max=maximum(maximum(res1,res2),maximum(res3,res4));
	if(max==res1) strcat(ch," |ADMIMISTRATION| ");
	if(max==res2) strcat(ch," |FOYER| ");
	if(max==res3) strcat(ch," |RESTAURATION| ");
	if(max==res4) strcat(ch," |SECURITY| ");
	
}
/****************************************************************/

void supprimer(char ch[])
{
FILE *f=NULL;
FILE *p=NULL;
char ch1[50],ch2[50],ch3[50],ch4[50],ch5[50],ch6[50];
f=fopen("reclamation.txt","r");
p=fopen("tempo.txt","a");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
if (strcmp(ch,ch1)!=0)
{
if(p!=NULL)
{
fprintf(p,"%s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6);
}
}
}
fclose(f);
fclose(p);
remove("reclamation.txt");
rename("tempo.txt","reclamation.txt");
}
/*************************************************************************/
int maximum(int a,int b)
{
int max=0;
if(a>b)
max=a;
else 
max=b;
return max;
}
