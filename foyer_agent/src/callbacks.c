#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


void
on_buttonADD_STUDENT_clicked           (GtkButton       *button,
                                        gpointer         user_data)

{
student s;
Birthday B;
GtkWidget *fname;
GtkWidget *lname;
GtkWidget *ID;
GtkWidget *d;
GtkWidget *m;
GtkWidget *y;
GtkWidget *mail;
GtkWidget *BLOC;
GtkWidget *FLOOR;
GtkWidget *CHAMBER;
fname=lookup_widget(button,"entryADD_STUDENT_FIRSTNAME");
lname=lookup_widget(button,"entryADD_STUDENT_LASTNAME");
ID=lookup_widget(button,"entryADD_STUDENT_ID");
d=lookup_widget(button,"spinbuttonADD_STUDENT_DAY");
m=lookup_widget(button,"spinbuttonADD_STUDENT_MONTH");
y=lookup_widget(button,"spinbuttonADD_STUDENT_YEAR");
mail=lookup_widget(button,"entryADD_STUDENT_MAIL");
BLOC=lookup_widget(button,"comboboxentryADD_STUDENT_BLOC");
FLOOR=lookup_widget(button,"spinbuttonADD_STUDENT_FLOOR");
CHAMBER=lookup_widget(button,"entryADD_STUDENT_CHAMBER");
strcpy(s.First_Name,gtk_entry_get_text(GTK_ENTRY(fname)));
strcpy(s.Last_Name,gtk_entry_get_text(GTK_ENTRY(lname)));
strcpy(s.ID,gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy(s.B.day,gtk_entry_get_text(GTK_ENTRY(d)));
strcpy(s.B.month,gtk_entry_get_text(GTK_ENTRY(m)));
strcpy(s.B.year,gtk_entry_get_text(GTK_ENTRY(y)));
strcpy(s.Mail,gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(s.BLOC,gtk_combo_box_get_active_text(GTK_COMBO_BOX(BLOC)));
strcpy(s.FLOOR,gtk_entry_get_text(GTK_ENTRY(FLOOR)));
strcpy(s.CHAMBER,gtk_entry_get_text(GTK_ENTRY(CHAMBER)));
add_student(s);



}


void
on_buttonDISPLAY_STUDENT_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *foyer_agent;
GtkWidget *treeview1;
GtkWidget *TREEVIEW;
foyer_agent=lookup_widget(button,"foyer_agent");
gtk_widget_destroy(foyer_agent);
TREEVIEW=create_TREEVIEW();
gtk_widget_show(TREEVIEW);
treeview1=lookup_widget(TREEVIEW,"treeview1");
display(treeview1);

}


void
on_buttonBACK_STUDENT_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *foyer_agent,*TREEVIEW;
TREEVIEW=lookup_widget(button,"TREEVIEW");
gtk_widget_destroy(TREEVIEW);
foyer_agent=create_foyer_agent();
gtk_widget_show(foyer_agent);
}


void
on_buttonREFRESH_STUDENT_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *TREEVIEW,*treeview1;
TREEVIEW=lookup_widget(button,"TREEVIEW");
gtk_widget_destroy(TREEVIEW);
TREEVIEW=create_TREEVIEW();
gtk_widget_show(TREEVIEW);
treeview1=lookup_widget(TREEVIEW,"treeview1");
display(treeview1);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* First_Name;
gchar* Last_Name;
gchar* ID;
gchar* day;
gchar* month;
gchar* year;
gchar* Mail;
gchar* BLOC;
gchar* FLOOR;
gchar* CHAMBER;
student s;
Birthday B;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,1,&First_Name,2,&Last_Name,3,&ID,4,&day,5,&month,6,&year,7,&Mail,&BLOC,8,&FLOOR,9,&CHAMBER,10,-1);
strcpy(s.First_Name,First_Name);
strcpy(s.Last_Name,Last_Name);
strcpy(s.ID,ID);
strcpy(s.B.day,day);
strcpy(s.B.month,month);
strcpy(s.B.year,year);
strcpy(s.Mail,Mail);
strcpy(s.BLOC,BLOC);
strcpy(s.FLOOR,FLOOR);
strcpy(s.CHAMBER,CHAMBER);
display(treeview);
}
}


void
on_button1_remove                      (GtkContainer    *container,
                                        GtkWidget       *widget,
                                        gpointer         user_data)
{

}


void
on_button2_enter                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonFIND_STUDENT_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *foyer_agent;
GtkNotebook *notebook1;
foyer_agent=lookup_widget(button,"foyer_agent");
gtk_widget_destroy(foyer_agent);
foyer_agent=create_foyer_agent();
gtk_widget_show(foyer_agent);
gtk_notebook_set_current_page(notebook1,3);
treeview1=lookup_widget(foyer_agent,"treeview1");
display(treeview1);

}


void
on_buttonREMOVE_STUDENT_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[20];
GtkWidget *ID;
ID=lookup_widget(button,"entrySTUDENT_ID");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(ID)));
if (find_student(ch)==1)
	delete_student(ch);

}


void
on_button_START_UPDATING_STUDENT_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[50];
student s;
Birthday B;
GtkWidget *fname;
GtkWidget *lname;
GtkWidget *ID,*ID1;
GtkWidget *d;
GtkWidget *m;
GtkWidget *y;
GtkWidget *mail;
GtkWidget *BLOC;
GtkWidget *FLOOR;
GtkWidget *CHAMBER;
fname=lookup_widget(button,"entryUPDATE_FIRST_NAME");
lname=lookup_widget(button,"entryUPDATE_LAST_NAME");
ID=lookup_widget(button,"entryUPDATE_ID");
d=lookup_widget(button,"spinbuttonUPDATE_DAY");
m=lookup_widget(button,"spinbuttonUPDATE_MONTH");
y=lookup_widget(button,"spinbuttonUPDATE_YEAR");
mail=lookup_widget(button,"entryUPDATE_MAIL");
BLOC=lookup_widget(button,"comboboxentryUPDATE_BLOC");
FLOOR=lookup_widget(button,"spinbuttonUPDATE_FLOOR");
CHAMBER=lookup_widget(button,"entryUPDATE_CHAMBER");

ID1=lookup_widget(button,"entryUPDATE_ID_UPDATE");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(ID)));

strcpy(s.First_Name,gtk_entry_get_text(GTK_ENTRY(fname)));
strcpy(s.Last_Name,gtk_entry_get_text(GTK_ENTRY(lname)));
strcpy(s.ID,gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy(s.B.day,gtk_entry_get_text(GTK_ENTRY(d)));
strcpy(s.B.month,gtk_entry_get_text(GTK_ENTRY(m)));
strcpy(s.B.year,gtk_entry_get_text(GTK_ENTRY(y)));
strcpy(s.Mail,gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(s.BLOC,gtk_combo_box_get_active_text(GTK_COMBO_BOX(BLOC)));
strcpy(s.FLOOR,gtk_entry_get_text(GTK_ENTRY(FLOOR)));
strcpy(s.CHAMBER,gtk_entry_get_text(GTK_ENTRY(CHAMBER)));
update_student(s,ch);
}


void
on_buttonSHOW_UPDATE_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
char ch[20];
char ch1[50],ch2[50],ch3[50],d[50],m[50],y[50],ch10[50]="",ch4[50],ch5[50],ch6[50],ch7[50];
GtkWidget *ID,*labelFIRSTNAME,*labelLASTNAME,*labelID,*labelBIRTHDAY,*labelMAIL,*labelBLOC,*labelFLOOR,*labelCHAMBER;
ID=lookup_widget(button,"entryUPDATE_ID_UPDATE");
labelFIRSTNAME = lookup_widget(button, "labelFIRSTNAME");
labelLASTNAME = lookup_widget(button, "labelLASTNAME");
labelID = lookup_widget(button, "labelID");
labelBIRTHDAY = lookup_widget(button, "labelBIRTHDAY");
labelMAIL = lookup_widget(button, "labelMAIL");
labelBLOC = lookup_widget(button, "labelBLOC");
labelFLOOR = lookup_widget(button, "labelFLOOR");
labelCHAMBER = lookup_widget(button, "labelCHAMBER");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(ID)));
f=fopen("student.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
{
if(strcmp(ch,ch3)==0)
{
strcat(ch10,d);
strcat(ch10,"/");
strcat(ch10,m);
strcat(ch10,"/");
strcat(ch10,y);
gtk_label_set_text(GTK_LABEL(labelFIRSTNAME),ch1);
gtk_label_set_text(GTK_LABEL(labelLASTNAME),ch2);
gtk_label_set_text(GTK_LABEL(labelID),ch3);
gtk_label_set_text(GTK_LABEL(labelBIRTHDAY),ch10);
gtk_label_set_text(GTK_LABEL(labelMAIL),ch4);
gtk_label_set_text(GTK_LABEL(labelBLOC),ch5);
gtk_label_set_text(GTK_LABEL(labelFLOOR),ch6);
gtk_label_set_text(GTK_LABEL(labelCHAMBER),ch7);
break;
}
}

}
}

void
on_buttonFIND_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
char ch[20];
char ch1[50],ch2[50],ch3[50],d[50],m[50],y[50],ch10[50]="",ch4[50],ch5[50],ch6[50],ch7[50];
GtkWidget *ID1,*labelFIRSTNAME1,*labelLASTNAME1,*labelID1,*labelBIRTHDAY1,*labelMAIL1,*labelBLOC1,*labelFLOOR1,*labelCHAMBER1;
ID1=lookup_widget(button,"entryFIND_ID");
labelFIRSTNAME1 = lookup_widget(button, "labelFIRSTNAME1");
labelLASTNAME1 = lookup_widget(button, "labelLASTNAME1");
labelID1 = lookup_widget(button, "labelID1");
labelBIRTHDAY1 = lookup_widget(button, "labelBIRTHDAY1");
labelMAIL1 = lookup_widget(button, "labelMAIL1");
labelBLOC1 = lookup_widget(button, "labelBLOC1");
labelFLOOR1 = lookup_widget(button, "labelFLOOR1");
labelCHAMBER1 = lookup_widget(button, "labelCHAMBER1");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(ID1)));
f=fopen("student.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s  \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
{
if(strcmp(ch,ch3)==0)
{
strcat(ch10,d);
strcat(ch10,"/");
strcat(ch10,m);
strcat(ch10,"/");
strcat(ch10,y);
gtk_label_set_text(GTK_LABEL(labelFIRSTNAME1),ch1);
gtk_label_set_text(GTK_LABEL(labelLASTNAME1),ch2);
gtk_label_set_text(GTK_LABEL(labelID1),ch3);
gtk_label_set_text(GTK_LABEL(labelBIRTHDAY1),ch10);
gtk_label_set_text(GTK_LABEL(labelMAIL1),ch4);
gtk_label_set_text(GTK_LABEL(labelBLOC1),ch5);
gtk_label_set_text(GTK_LABEL(labelFLOOR1),ch6);
gtk_label_set_text(GTK_LABEL(labelCHAMBER1),ch7);
break;
}
}

}
}


void
on_buttonSHOW_STUDENT_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
int i=0;
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
char ch[20];
FILE *f=NULL;
GtkWidget *msg;
msg=lookup_widget(button,"labelSTUDENT_NUMBER");
f=fopen("student.txt","r");
if (f!=NULL)

{
   while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s  \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
	{  i++;



} 
fclose(f);
}
sprintf(ch,"%d",i);
gtk_label_set_text(GTK_LABEL(msg),ch);

}


void
on_buttonSHOW_BLOC_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
int i=0;
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
char ch[20];
char bloc[20];
FILE *f=NULL;
GtkWidget *msg;
GtkWidget *BLOC;
BLOC=lookup_widget(button,"comboboxentryBLOC_TASK_BREAKDOWN");
strcpy(bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(BLOC)));
msg=lookup_widget(button,"labelBLOC_NUMBER");
f=fopen("student.txt","r");
if (f!=NULL)

{
   while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s  \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
	{if ( strcmp(ch5,bloc)==0) 
	 i++;



} 
fclose(f);
}
sprintf(ch,"%d",i);
gtk_label_set_text(GTK_LABEL(msg),ch);


}


void
on_buttonSHOW_FLOOR_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
int i=0;
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
char ch[20];
char bloc[20];
char floor[20];
GtkWidget *BLOC;
BLOC=lookup_widget(button,"comboboxentryBLOC_TASK_BREAKDOWN");
strcpy(bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(BLOC)));
FILE *f=NULL;
GtkWidget *msg;
GtkWidget *FLOOR;
FLOOR=lookup_widget(button,"spinbuttonFLOOR_TASK_BREAKDOWN");
strcpy(floor,gtk_entry_get_text(GTK_ENTRY(FLOOR)));
msg=lookup_widget(button,"labelFLOOR_NUMBER");
f=fopen("student.txt","r");
if (f!=NULL)

{
   while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s  \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
	{if (( strcmp(ch6,floor)==0) && (strcmp(ch5,bloc)==0))
	 i++;



} 
fclose(f);
}
sprintf(ch,"%d",i);
gtk_label_set_text(GTK_LABEL(msg),ch);



}


void
on_buttonSHOW_CHAMBER_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
int i=0;
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
char ch[20];
char bloc[20];
char floor[20];
char chamber[20];
GtkWidget *BLOC;
BLOC=lookup_widget(button,"comboboxentryBLOC_TASK_BREAKDOWN");
strcpy(bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(BLOC)));
FILE *f=NULL;
GtkWidget *msg;
GtkWidget *FLOOR;
FLOOR=lookup_widget(button,"spinbuttonFLOOR_TASK_BREAKDOWN");
strcpy(floor,gtk_entry_get_text(GTK_ENTRY(FLOOR)));
GtkWidget *CHAMBER;
CHAMBER=lookup_widget(button,"entryCHAMBER_TASK_BREAKDOWN");
strcpy(chamber,gtk_entry_get_text(GTK_ENTRY(CHAMBER)));
msg=lookup_widget(button,"labelCHAMBER_NUMBER");
f=fopen("student.txt","r");
if (f!=NULL)

{
   while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s  \n",ch1,ch2,ch3,d,m,y,ch4,ch5,ch6,ch7)!=EOF)
	{if (( strcmp(ch6,floor)==0) && (strcmp(ch5,bloc)==0) && (strcmp(ch7,chamber)==0))
	 i++;



} 
fclose(f);
}
sprintf(ch,"%d",i);
gtk_label_set_text(GTK_LABEL(msg),ch);



}

