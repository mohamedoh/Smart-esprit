#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct
{
char First_Name[50];
char Last_Name[50];
char Username[50];
char Password[50];
char Role[50];
}user ;

/*partie1*/
void add_user(user u);
int find_user(char username[]);
void delete_user(char username[]);
void update_user(user u,char username[]);
void display_user_info(char username[],char t1[],char t2[],char t3[],char t4[],char t5[]);
int verif(char log[], char Pw[]);


//int role_button(int role_button_global, char ch[]);
void display(GtkWidget *list);



/*partie 2*/
int student_number(char ch[]);




#endif // FONCTION_H_INCLUDED

