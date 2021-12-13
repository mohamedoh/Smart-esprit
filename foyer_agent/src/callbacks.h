#include <gtk/gtk.h>

void
on_buttonADD_STUDENT_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDISPLAY_STUDENT_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonBACK_STUDENT_clicked          (GtkButton       *button,
                                        gpointer         user_data);
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_button1_remove                      (GtkContainer    *container,
                                        GtkWidget       *widget,
                                        gpointer         user_data);
void
on_button2_enter                       (GtkButton       *button,
                                        gpointer         user_data);
void
on_buttonFIND_STUDENT_clicked          (GtkButton       *button,
                                        gpointer         user_data);
void
on_buttonREMOVE_STUDENT_clicked        (GtkButton       *button,
                                        gpointer         user_data);
void
on_button_START_UPDATING_STUDENT_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);
void
on_buttonSHOW_UPDATE_clicked           (GtkButton       *button,
                                        gpointer         user_data);
void
on_buttonFIND_clicked                  (GtkButton       *button,
                                        gpointer         user_data);
void
on_buttonSHOW_STUDENT_clicked          (GtkButton       *button,
                                        gpointer         user_data);
void
on_buttonSHOW_BLOC_clicked             (GtkButton       *button,
                                        gpointer         user_data);
void
on_buttonSHOW_FLOOR_clicked            (GtkButton       *button,
                                        gpointer         user_data);
void
on_buttonSHOW_CHAMBER_clicked          (GtkButton       *button,
                                        gpointer         user_data);
void
on_buttonREFRESH_STUDENT_clicked       (GtkButton       *button,
                                        gpointer         user_data);
