#include "fonction.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <gtk/gtk.h>
enum
{
	First_Name,
	Last_Name,
	Username,
	Password,
	Role,
	COLUMNS
};



//-------------------------------------------------------
/*add user function*/
//-------------------------------------------------------
void add_user(user u)
{
FILE *f=NULL;
f=fopen("user.txt","a");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",u.First_Name,u.Last_Name,u.Username,u.Password,u.Role);
fclose(f);
}
else
	printf("ERROR");
}

//-------------------------------------------------------
/* find user function*/
//-------------------------------------------------------
int find_user(char username[])
{
FILE *f=NULL;
int trouve=0;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];

f=fopen("user.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
if(strcmp(ch3,username)==0)
{
trouve=1;
break;
}
}
fclose(f);
}
return trouve;
}
//-------------------------------------------------------
/*delete user function*/
//-------------------------------------------------------
void delete_user(char username[])
{
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];
int c=0;
FILE *f=NULL;
FILE *temp=NULL;
f=fopen("user.txt","r");
if(f!=NULL)
{
temp=fopen("temp.txt","a");
if(temp!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
fprintf(temp,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5);
}
fclose(temp);
}
fclose(f);
}
temp=fopen("temp.txt","r");
if(temp!=NULL)
{
f=fopen("user.txt","w");
if(f!=NULL)
{
while(fscanf(temp,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
if(strcmp(username,ch3)!=0)
{
c=1;
fprintf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5);
}
}
fclose(f);
}
fclose(temp);
}
remove("temp.txt");

}
//-------------------------------------------------
/*verif function*/
//-------------------------------------------------
int verif(char log[], char Pw[])
{
int trouve=0;
FILE* f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];
f=fopen("user.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
if((strcmp(ch3,log)==0) && (strcmp(ch4,Pw)==0))
{
trouve=1;
break;
}
}
fclose(f);
}
return trouve;
}
//--------------------------------------------------------------
/*update function*/
//--------------------------------------------------------------
void update_user(user u,char username[])
{
FILE *f=NULL;
FILE *p=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];
f=fopen("user.txt","r");
p=fopen("tempo.txt","w");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
if(strcmp(username,ch3)!=0)
{
fprintf(p,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5);
}
else 
{
fprintf(p,"%s %s %s %s %s \n",u.First_Name,u.Last_Name,u.Username,u.Password,u.Role);
}
}
fclose(f);
fclose(p);
}
remove("user.txt");
rename("tempo.txt","user.txt");

}
//------------------------------------------------------------
/*display Function*/
//------------------------------------------------------------
void display_user_info(char username[],char t1[],char t2[],char t3[],char t4[],char t5[])
{
FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];
f=fopen("user.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
if(strcmp(ch3,username)==0)
{
strcpy(t1,ch1);
strcpy(t2,ch2);
strcpy(t3,ch3);
strcpy(t4,ch4);
strcpy(t5,ch5);
break;
}
}
fclose(f);
}
}

//---------------------------------------------------------
/* student num function*/
//---------------------------------------------------------
int student_number(char ch[])
{
FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];
int res=0;
f=fopen("user.txt","r");
if(f!=NULL)
{
if(strcmp(ch,"All")!=0)
{
while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
if(strcmp(ch5,ch)==0)
res++;
}
}
else
{
while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{res++;}
}
fclose(f);
}
return res;
}


//*****************************************************************
/* Display treeview */
//*****************************************************************
void display(GtkWidget *list)

{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store;

FILE *f=NULL;
char First_Name1[20];
char Last_Name1[20];
char Username1[20];
char Password1[20];
char Role1[20];



store=NULL ;
store=gtk_tree_view_get_model(list);
if(store==NULL)
{	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("First_Name" , renderer , "text" , First_Name , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("Last_Name" , renderer , "text" , Last_Name , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("Username" , renderer , "text" , Username , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("Password" , renderer , "text" , Password , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("Role" , renderer , "text" , Role , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );
}
store=gtk_list_store_new(COLUMNS ,G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING );

f = fopen("user.txt" , "r");
if(f==NULL)
{
	return ; 
}
else 
{f=fopen("user.txt" , "a+");
	while(fscanf(f,"%s %s %s %s %s \n" , First_Name1, Last_Name1 ,Username1,Password1 ,Role1)!=EOF)
	{	gtk_list_store_append(store, &iter);
		gtk_list_store_set(store ,&iter ,First_Name,First_Name1,Last_Name,Last_Name1,Username,Username1,Password,Password1,Role,Role1,-1);
	}
	fclose(f) ;
gtk_tree_view_set_model(GTK_TREE_VIEW(list) , GTK_TREE_MODEL (store));
g_object_unref(store);
}

}

//*****************************************************************
//***** role function ***************************************
//*****************************************************************
void my_role(int role_button_global,char ch[])
{
if(role_button_global==1)
	strcpy(ch,"Admin");
else if(role_button_global==2)
  	strcpy(ch,"Technicien");
else if(role_button_global==3)
	strcpy(ch,"Nutrionist");
else if (role_button_global==4)
	strcpy(ch,"FoyerAgent");
else if (role_button_global==5)
	strcpy(ch,"RestaurantAgent");
else
	strcpy(ch,"Student");
	
}

//***************************************************

