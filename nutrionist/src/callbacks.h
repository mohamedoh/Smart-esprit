#include <gtk/gtk.h>


void
on_buttonADD_MENU_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDISPLAY_MENU_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonBACK_MENU_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonREFRESH_MENU_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonREMOVE_MENU_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonUPDATE_MENU_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCHECK_NUTRIONIST_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSHOW_BEST_MENU_clicked        (GtkButton       *button,
                                        gpointer         user_data);
