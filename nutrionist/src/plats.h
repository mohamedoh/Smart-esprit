#ifndef PLATS_H_INCLUDED
#define PLATS_H_INCLUDED
#include <gtk/gtk.h>

typedef struct
{
  char jour[50];
  char mois[50];
  char annee[50];
} Date;

typedef struct
{
  char Nom[30];
  char id[30];
  char dechets[30];
  Date date;
} Plats;

int verif(char num[30]);
void ajouter( Plats Pla);
void supprimer( Plats Pla, char num[30]);
void modifier( Plats pla, char num[30]);
void chercher( char num[30]);
void afficher();
void display(GtkWidget *list);
#endif
