

#include<gtk/gtk.h>

typedef struct
{
    char id[20];
    char nom[20];
    char prenom[20];
    char type[20];
    char description[1000];
    char date_reclamation[30] ;
} reclamation;


void ajouter(reclamation r);
void afficher(GtkWidget *liste);
void modifier(reclamation r);
void supprimer(char ch[]);
void service(char ch[]);
int recherche (char id[]);
int maximum(int a,int b);




