#include <gtk/gtk.h>


void
on_buttonSignup_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonLogin_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonAdmin_Add_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTechnicien_Add_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonNutrionist_Add_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFoyerAgent_Add_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonRestaurantAgent_Add_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonStudent_Add_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonAdd_Add_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRemove_Remove_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonAdmin_Update_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonNutrionist_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFoyerAgent_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonRestaurantAgent_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonUpdate_Role_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonUpdate_Update_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRefresh_Update_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRefresh_Find_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonFind_Find_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCheck_Check_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonStudent_SignUp_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonRestaurantAgent_SignUp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFoyerAgent_SignUp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonNutrionist_SignUp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTechnicien_SignUp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAdmin_SignUp_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonRefresh_Add_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRefresh_Remove_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonStudent_Update_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTechnicien_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAdmin_Sign_Up_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonStudent_Sign_Up_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonRestaurant_Agent_Sign_Up_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFoyer_Agent_Sign_Up_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonNutrionist_Sign_Up_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTechnicien_Sign_Up_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonStudent_Add_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonRestaurant_Agent_Add_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFoyer_Agent_Add_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonNutrionist_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTechnicien_Add_activate  (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonStudent_Update_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonRestaurant_Agent_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFoyer_Agent_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonNutrionist_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTechnicien_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAdmin_Add_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTechnicien_Add_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonstudent_Add_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonRestaurant_Agent_Add_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonNutrionist_Add_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFoyer_Agent_Add_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAdmin_Update_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTechnicien_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonNutrionist_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFoyer_Agent_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonRestaurant_Agent_Update_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonStudent_Update_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonDisplay_Add_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDisplay_Remove_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDisplay_Update_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDisplay_Find_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDispaly_Check_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRefresh_Admin_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonBack_Admin_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCreate_new_account_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonshow                          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCheck_Check_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsign_off_admin_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCHECK_ADMIN_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCHECK_NUMBER_ADMIN_clicked    (GtkButton       *button,
                                        gpointer         user_data);
