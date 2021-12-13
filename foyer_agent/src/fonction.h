#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct
{
char day[50];
char month[50];
char year[50];
}Birthday;
typedef struct
{
char First_Name[50];
char Last_Name[50];
char ID[50];
Birthday B;
char Mail[50];
char BLOC[50];
char FLOOR[50];
char CHAMBER[50];
} student ;

/*partie1*/
void add_student(student s);
int find_student(char ID[]);
void delete_student(char ID[]);
void update_student(student s,char ID[]);
void display_student_info(char ID[]);


//int role_button(int role_button_global, char ch[]);
void display(GtkWidget *list);



/*partie 2*/
#endif // FONCTION_H_INCLUDED

