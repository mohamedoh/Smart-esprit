#include "fonction_foyer_agent.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <gtk/gtk.h>
enum
{
	First_Name,
	Last_Name,
	ID,
	day,
	month,
	year,
        Mail,
	BLOC,
	FLOOR,	
	CHAMBER,
	COLUMNS
};



//-------------------------------------------------------
/*add student function*/
//-------------------------------------------------------
void add_student(student s)
{

Birthday B;
FILE *f=NULL;
f=fopen("student.txt","a");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s %s %s \n",s.First_Name,s.Last_Name,s.ID,s.B.day,s.B.month,s.B.year,s.Mail,s.BLOC,s.FLOOR,s.CHAMBER);
}
fclose(f);

}

//-------------------------------------------------------
/* find student function*/
//-------------------------------------------------------
int find_student(char ID[])
{
FILE *f=NULL;
int trouve=0;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char d[20];
char m[20];
char y[20];
char ch5[20];
char ch6[20];
char ch7[20];


f=fopen("student.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s  \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
{
if(strcmp(ch3,ID)==0)
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
/*delete student function*/
//-------------------------------------------------------
void delete_student(char ID[])
{
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char d[20];
char m[20];
char y[20];
char ch5[20];
char ch6[20];
char ch7[20];
FILE *f=NULL;
FILE *temp=NULL;
f=fopen("student.txt","r");
if(f!=NULL)
{
temp=fopen("temp.txt","a");
if(temp!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s  \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
{
fprintf(temp,"%s %s %s %s %s %s %s %s %s %s   \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7);
}
fclose(temp);
}
fclose(f);
}
temp=fopen("temp.txt","r");
if(temp!=NULL)
{
f=fopen("student.txt","w");
if(f!=NULL)
{
while(fscanf(temp,"%s %s %s %s %s %s %s %s %s %s \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
{
if(strcmp(ID,ch3)!=0)
{
fprintf(f,"%s %s %s %s %s %s %s %s %s %s  \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7);
}
}
fclose(f);
}
fclose(temp);
}
remove("temp.txt");

}

//--------------------------------------------------------------
/*update function*/
//--------------------------------------------------------------
void update_student(student s,char ID[])
{
FILE *f=NULL;
FILE *p=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char d[20];
char m[20];
char y[20];
char ch5[20];
char ch6[20];
char ch7[20];
f=fopen("student.txt","a+");
p=fopen("temp.txt","a");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
{
if(strcmp(s.ID,ch3)!=0)
{
fprintf(p,"%s %s %s %s %s %s %s %s %s %s \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7);
break;
}
else 
{
fprintf(p,"%s %s %s %s %s %s %s %s %s %s \n",s.First_Name,s.Last_Name,s.ID,s.B.day,s.B.month,s.B.year,s.Mail,s.BLOC,s.FLOOR,s.CHAMBER);
}
}
fclose(f);
fclose(p);
}

remove("student.txt");
rename("temp.txt","student.txt");

}
//------------------------------------------------------------
/*display Function*/
//------------------------------------------------------------
void display_student_info(char ID[])
{
FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char d[20];
char m[20];
char y[20];
char ch5[20];
char ch6[20];
char ch7[20];
f=fopen("user.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
{
if(strcmp(ch3,ID)==0)
{
printf(" First Name : %s \n Last Name : %s \n ID : %s \n Birthday : %s/%s/%s \n Mail : %s  \n BLOC : %s \n FLOOR : %s \n CHAMBER : %s \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7);
break;
}
}
fclose(f);
}
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
char ID1[20];
char day1[20];
char month1[20];
char year1[20];
char Mail1[20];
char BLOC1[20];
char FLOOR1[20];
char CHAMBER1[20];



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
	column = gtk_tree_view_column_new_with_attributes("ID" , renderer , "text" , ID , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("day" , renderer , "text" , day , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );
	
	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("month" , renderer , "text" , month , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("year" , renderer , "text" , year , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("Mail" , renderer , "text" , Mail , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );
	
	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("BLOC" , renderer , "text" , BLOC , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );
	
	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("FLOOR" , renderer , "text" , FLOOR , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );
	
	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("CHAMBER" , renderer , "text" , CHAMBER , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(list) , column );
}
store=gtk_list_store_new(COLUMNS ,G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING  );

f = fopen("student.txt" , "r");
if(f==NULL)
{
	return ; 
}
else 
{f=fopen("student.txt" , "a+");
	while(fscanf(f,"%s %s %s %s %s  %s %s %s  %s %s \n" , First_Name1, Last_Name1 ,ID1, day1, month1 , year1 ,Mail1,BLOC1,FLOOR1,CHAMBER1)!=EOF)
	{	gtk_list_store_append(store, &iter);
		gtk_list_store_set(store ,&iter ,First_Name,First_Name1,Last_Name,Last_Name1,ID,ID1,day,day1,month,month1,year,year1,Mail,Mail1,BLOC,BLOC1,FLOOR,FLOOR1,CHAMBER,CHAMBER1,-1);
	}
	fclose(f) ;
gtk_tree_view_set_model(GTK_TREE_VIEW(list) , GTK_TREE_MODEL (store));
g_object_unref(store);
}

}

int  verif(char num[30])
{
student s;
FILE *f;
int trouve=0;
f=fopen("student.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",s.First_Name,s.Last_Name,s.ID,s.B.day,s.B.month,s.B.year,s.Mail,s.BLOC,s.FLOOR,s.CHAMBER)!=EOF)
{
if  (strcmp(s.ID,num)==0)
{
trouve=1;
}
}
fclose(f);
}
return trouve;
}


