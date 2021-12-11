#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
int role_button_global=1;
int role_button_global1=1;
int role_button_global2=1;

//********************************************************** SIGN UP BUTTON (SIGN UP WINDOW)  *********************************************************************************

void
on_buttonSignup_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *fname;
GtkWidget *lname;
GtkWidget *uname;
GtkWidget *pw;
GtkWidget *windowLogin,*Sign_up,*output;
char first_name[20];
char last_name[20];
char user_name[20];
char passw[20];
char rol[20];
char ch[20];
char msg[50];
output = lookup_widget(button, "empty");
my_role(role_button_global1,ch);
fname=lookup_widget(button,"entryFirstName");
lname=lookup_widget(button,"entryLastName");
uname=lookup_widget(button,"entryUsername");
pw=lookup_widget(button,"entryPassword");
strcpy(first_name,gtk_entry_get_text(GTK_ENTRY(fname)));
strcpy(last_name,gtk_entry_get_text(GTK_ENTRY(lname)));
strcpy(user_name,gtk_entry_get_text(GTK_ENTRY(uname)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(rol,ch);
if((strlen(first_name)!=0)&&(strlen(last_name)!=0)&&(strlen(user_name)!=0)&&(strlen(passw)!=0)&&(strlen(rol)!=0))
{
f=fopen("user.txt","a");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",first_name,last_name,user_name,passw,rol);
fclose(f);
windowLogin=create_Login();
gtk_widget_show(windowLogin);
Sign_up = lookup_widget (button,"Sign_up");
gtk_widget_destroy (Sign_up);
}
}
else
{
strcpy(msg,"EMPTY FIELD : YOU HAVE TO FILL ALL FIELD ");
gtk_label_set_text(GTK_LABEL(output),msg);
}





}

//*************************************************************************************************************************************************

//**************************************************** LOGIN BUTTON (LOGIN WINDOW ) ************************************************************************

void
on_buttonLogin_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username,*password, *windowAdmin , *output,*Login;
char user[20];
char pasw[20];
char ch[90];
int trouve ;
username = lookup_widget (button, "entryUsername_Login");
password = lookup_widget (button, "entryPassword_Login");

strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(user,pasw);

if (trouve==1)
{
windowAdmin=create_Admin();
gtk_widget_show(windowAdmin);
Login=lookup_widget(button,"Login");
gtk_widget_destroy(Login);
}
else 
{output = lookup_widget(button, "label6") ;
strcpy(ch,"User not found,create your account");
gtk_label_set_text(GTK_LABEL(output),ch);
}

}
//************************************************************************************************************************************************************

//************************************************************ BUTTONS FUNCTION (WINDOW ADMIN)  ***********************************************************************
void
on_buttonAdd_Add_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[20];
char msg[50];
user u;
GtkWidget *output,*output1;
GtkWidget *fname;
GtkWidget *lname;
GtkWidget *uname;
GtkWidget *pw;
fname=lookup_widget(button,"entryAdd_First_Name");
lname=lookup_widget(button,"entryAdd_Last_Name");
uname=lookup_widget(button,"entryAdd_Username");
pw=lookup_widget(button,"entryAdd_Password");
my_role(role_button_global,ch);
strcpy(u.First_Name,gtk_entry_get_text(GTK_ENTRY(fname)));
strcpy(u.Last_Name,gtk_entry_get_text(GTK_ENTRY(lname)));
strcpy(u.Username,gtk_entry_get_text(GTK_ENTRY(uname)));
strcpy(u.Password,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(u.Role,ch);

output= lookup_widget(button, "msg_Add");
output1= lookup_widget(button, "msg_add2");
if(find_user(u.Username)==1)
{
strcpy(msg,"Username Already Exist");
gtk_label_set_text(GTK_LABEL(output1),msg);
}
else
{
add_user(u);
strcpy(msg,"User Successfully Added");
gtk_label_set_text(GTK_LABEL(output),msg);

}
}


void
on_buttonRemove_Remove_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[20];
char msg[50];
GtkWidget *output,*output1;
GtkWidget *uname;
output= lookup_widget(button, "msg_Remove");
output1= lookup_widget(button, "msg_remove1");
uname=lookup_widget(button,"entryRemove_Username");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(uname)));
if (find_user(ch)==1)
	{delete_user(ch);
	strcpy(msg,"User Successfully Deleted");
	gtk_label_set_text(GTK_LABEL(output),msg);
}
else
{
strcpy(msg,"User Not Found");
gtk_label_set_text(GTK_LABEL(output1),msg);
}
}


void
on_buttonUpdate_Update_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[20];
char msg[50];
char username1[20];
user u;
GtkWidget *output,*output1;
GtkWidget *fname;
GtkWidget *lname;
GtkWidget *uname;
GtkWidget *uname1;
GtkWidget *pw;
fname=lookup_widget(button,"entryUpdate_First_Name");
lname=lookup_widget(button,"entryUpdate_Last_Name");
uname=lookup_widget(button,"entryUpdate_Username");
uname1=lookup_widget(button,"entryUsername_to_change");
pw=lookup_widget(button,"entryUpdate_Password");
my_role(role_button_global2,ch);
strcpy(u.First_Name,gtk_entry_get_text(GTK_ENTRY(fname)));
strcpy(u.Last_Name,gtk_entry_get_text(GTK_ENTRY(lname)));
strcpy(u.Username,gtk_entry_get_text(GTK_ENTRY(uname)));
strcpy(u.Password,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(u.Role,ch);
strcpy(username1,gtk_entry_get_text(GTK_ENTRY(uname1)));

output= lookup_widget(button, "msg_Update");
output1= lookup_widget(button, "msg_Update1");
if(find_user(username1)==1)
{
update_user(u,username1);
strcpy(msg,"User Successfully Updated");
gtk_label_set_text(GTK_LABEL(output),msg);
}
else
{
strcpy(msg,"Username Not Found , Add User First !!");
gtk_label_set_text(GTK_LABEL(output1),msg);

}

}




void
on_buttonFind_Find_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[20];
char msg[200];
GtkWidget *output,*output1;
GtkWidget *uname;
output= lookup_widget(button, "msg_Find");
output1= lookup_widget(button, "msg_find1");
uname=lookup_widget(button,"entryFind_Username");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(uname)));
if (find_user(ch)==1)
	{
	strcpy(msg,"User Exist, Press Display If You Want See User Info");
	gtk_label_set_text(GTK_LABEL(output),msg);
}
else
{
strcpy(msg,"User Not Found");
gtk_label_set_text(GTK_LABEL(output1),msg);
}
}


void
on_buttonCheck_Check_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}

//***********************************************************************************************************************************************************************



//*********************************************************************** TREEVIEW FUCNTION ***************************************************

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* First_Name;
gchar* Last_Name;
gchar* Username;
gchar* Password;
gchar* Role;
user u;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&First_Name,1,&Last_Name,2,&Username,3,&Password,4,&Role,-1);
strcpy(u.First_Name,First_Name);
strcpy(u.Last_Name,Last_Name);
strcpy(u.Username,Username);
strcpy(u.Password,Password);
strcpy(u.Role,Role);
display(treeview);
}
}



//*****************************************************     RADIO BUTTON   ***************************************************************

//*********** Sign up radio button *******************************************************
void
on_radiobuttonAdmin_Sign_Up_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global1=1;}
}


void
on_radiobuttonStudent_Sign_Up_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global1=6;}
}


void
on_radiobuttonRestaurant_Agent_Sign_Up_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global1=5;}
}


void
on_radiobuttonFoyer_Agent_Sign_Up_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global1=4;}
}


void
on_radiobuttonNutrionist_Sign_Up_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global1=3;}
}


void
on_radiobuttonTechnicien_Sign_Up_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global1=2;}
}




//ADD Radio Button *********************************************************************

void
on_radiobuttonAdmin_Add_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global=1;}
}


void
on_radiobuttonTechnicien_Add_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global=2;}
}


void
on_radiobuttonstudent_Add_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global=6;}
}


void
on_radiobuttonRestaurant_Agent_Add_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global=5;}
}


void
on_radiobuttonNutrionist_Add_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global=3;}
}


void
on_radiobuttonFoyer_Agent_Add_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global=4;}
}


//update radio button *****************************************************************

void
on_radiobuttonAdmin_Update_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global2=1;}
}


void
on_radiobuttonTechnicien_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global2=2;}
}


void
on_radiobuttonNutrionist_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global2=3;}
}


void
on_radiobuttonFoyer_Agent_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global2=4;}
}


void
on_radiobuttonRestaurant_Agent_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global2=5;}
}


void
on_radiobuttonStudent_Update_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{role_button_global2=6;}
}


//*************************************************************************



//****************************************************************************  DISPLAYS FUNCTION ADMIN *******************************************************************

void
on_buttonDisplay_Add_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *treeview1;
GtkWidget *Treeview_window_Admin;
Admin=lookup_widget(button,"Admin");
gtk_widget_destroy(Admin);
Treeview_window_Admin=create_Treeview_window_Admin();
gtk_widget_show(Treeview_window_Admin);
treeview1=lookup_widget(Treeview_window_Admin,"treeview1");
display(treeview1);
}


void
on_buttonDisplay_Remove_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *treeview1;
GtkWidget *Treeview_window_Admin;
Admin=lookup_widget(button,"Admin");
gtk_widget_destroy(Admin);
Treeview_window_Admin=create_Treeview_window_Admin();
gtk_widget_show(Treeview_window_Admin);
treeview1=lookup_widget(Treeview_window_Admin,"treeview1");
display(treeview1);
}


void
on_buttonDisplay_Update_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *treeview1;
GtkWidget *Treeview_window_Admin;
Admin=lookup_widget(button,"Admin");
gtk_widget_destroy(Admin);
Treeview_window_Admin=create_Treeview_window_Admin();
gtk_widget_show(Treeview_window_Admin);
treeview1=lookup_widget(Treeview_window_Admin,"treeview1");
display(treeview1);
}





//*****************************************************************************************************************************************************************************


//********************************************************* Treeview window Buttons **************************************************************************************************
void
on_buttonRefresh_Admin_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *w;
GtkWidget *treeview1;
GtkWidget *Treeview_window_Admin;
w=lookup_widget(button,"Treeview_window_Admin");
Treeview_window_Admin=create_Treeview_window_Admin();
gtk_widget_show(Treeview_window_Admin);
gtk_widget_hide(w);
treeview1=lookup_widget(Treeview_window_Admin,"treeview1");
display(treeview1);
}


void
on_buttonBack_Admin_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *Treeview_window_Admin;
Treeview_window_Admin=lookup_widget(button,"Treeview_window_Admin");
gtk_widget_destroy(Treeview_window_Admin);
Admin=create_Admin();
gtk_widget_show(Admin);

}
//*************************************************************************************************************************************************************************

void
on_buttonCreate_new_account_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Sign_up,*Login;
Login = lookup_widget (button,"Login");
  gtk_widget_destroy (Login);
Sign_up = create_Sign_up ();
  gtk_widget_show (Sign_up);

}


void
on_buttonshow                          (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[20];
char msg[50];
char t1[50],t2[50],t3[50],t4[50],t5[50];
char res[50]="",res1[50]="",res2[50]="",res3[50]="",res4[50]="";
GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *uname;
output= lookup_widget(button, "fn");
output1= lookup_widget(button, "ln");
output2= lookup_widget(button, "un");
output3= lookup_widget(button, "pw");
output4= lookup_widget(button, "rol");
uname=lookup_widget(button,"entryFind_Username");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(uname)));
if (find_user(ch)==1)
	{
	display_user_info(ch,t1,t2,t3,t4,t5);
	strcat(res,"First name : ");
	strcat(res,t1);
	gtk_label_set_text(GTK_LABEL(output),res);
	
strcat(res1,"Last name : ");
	strcat(res1,t2);
	gtk_label_set_text(GTK_LABEL(output1),res1);
strcat(res2,"Username : ");
	strcat(res2,t3);
	gtk_label_set_text(GTK_LABEL(output2),res2);
strcat(res3,"Password : ");
	strcat(res3,t4);
	gtk_label_set_text(GTK_LABEL(output3),res3);
strcat(res4,"Role : ");
	strcat(res4,t5);
	gtk_label_set_text(GTK_LABEL(output4),res4);
}
else
{
strcpy(msg,"Please, Add User First !!!");
gtk_label_set_text(GTK_LABEL(output),msg);
}

}



void
on_buttonsign_off_admin_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin,*Login;

Admin=lookup_widget(button,"Admin");
gtk_widget_destroy(Admin);
Login=create_Login();
gtk_widget_show(Login);
}


void
on_buttonCHECK_ADMIN_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *uname,*output,*output1;
char msg[50],ch[50],msg1[50];
uname=lookup_widget(button,"entryFind_Username");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(uname)));
output=lookup_widget(button,"msg_Find");
output1=lookup_widget(button,"msg_find1");
if (find_user(ch)==1)
{
	strcpy(msg,"User Exist");
	gtk_label_set_text(GTK_LABEL(output),msg);
	strcpy(msg1,"Press Show To Display User Info");
	gtk_label_set_text(GTK_LABEL(output1),msg1);
}
else
{
	strcpy(msg,"Please, Add User First !!!");
	gtk_label_set_text(GTK_LABEL(output1),msg);
}


}


void
on_buttonCHECK_NUMBER_ADMIN_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[50],msg[50]="",ch1[20];
int res;
GtkWidget *combobox1,*output;
combobox1=lookup_widget(button,"combobox1");
strcpy(ch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
res=student_number(ch);
sprintf(ch1, "%d", res);
output=lookup_widget(button,"msg_Check");
strcpy(msg,"The number of ");
strcat(msg,ch);
strcat(msg," User");
strcat(msg, "	=    ");
strcat(msg,ch1);

gtk_label_set_text(GTK_LABEL(output),msg);

}

