#include <gtk/gtk.h>


void
on_button_ajouter_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_afficher_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_afficher_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);



void
on_button_service_plus_reclamer_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_UpdateReclamationAdd_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRemove_reclamation_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttoncheck_reclamation_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsign_off_reclamation_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_refresh_reclamation_clicked  (GtkButton       *button,
                                        gpointer         user_data);
